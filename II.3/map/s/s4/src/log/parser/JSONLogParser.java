package log.parser;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import log.model.Log;
import log.model.Message;
import log.model.Severity;
import log.model.Visibility;

/**
 * This is a {@link LogParser} for {@code FileType.JSON}
 */
public class JSONLogParser implements LogParser {

    private static JSONLogParser instance;

    private JSONLogParser() {
    }

    public static JSONLogParser getInstance() {
        if (instance == null) {
            instance = new JSONLogParser();
        }
        return instance;
    }

    /**
     * {@inheritDoc}
     */
    public List<Log> parseLogs(String path) throws IOException {
        Path filePath = Path.of(path);

        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            if (!reader.readLine().contains("[")) {
                throw new IOException("Invalid log file");
            }

            ArrayList<Log> logs = new ArrayList<>();
            String nextLine = reader.readLine();

            while (!nextLine.contains("]")) {
                logs.add(readLog(reader, nextLine));

                nextLine = reader.readLine();
            }

            return logs;
        }
    }

    /**
     * Parses a single {@link Log} entry
     *
     * @param reader
     *         the Reader to read from
     * @param firstLine
     *         the first line that was already read
     * @return the parsed {@link Log}
     */
    private static Log readLog(BufferedReader reader, String firstLine) throws IOException {
        if (!firstLine.contains("{")) {
            throw new IOException("Invalid log file");
        }

        Log log = new Log();

        for (int i = 0; i < 4; i++) {
            readField(reader, log);
        }

        if (!reader.readLine().contains("}")) {
            throw new IOException("Invalid log file");
        }

        return log;
    }

    /**
     * Parses the next {@link Log} field
     *
     * @param reader
     *         the Reader to read from
     * @param log
     *         the {@link Log} where the field is set
     */
    private static void readField(BufferedReader reader, Log log) throws IOException {
        String line2 = reader.readLine();
        String fieldName = line2.split(":")[0].replace("\"", "").trim();

        switch (fieldName) {
        case "timestamp": {
            String[] split = line2.split(":");
            String s = (split[1] + ":" + split[2] + ":" + split[3]).replace("\"", "");
            log.setTimestamp(LocalDateTime.parse(s.substring(1, s.length() - 1)));
            break;
        }
        case "severity": {
            String s = line2.split(":")[1].replace("\"", "");
            log.setSeverity(Severity.valueOf(s.substring(1, s.length() - 1)));
            break;
        }
        case "message": {
            if (!line2.split(":")[1].contains("{")) {
                throw new IOException("Invalid log file");
            }

            Message message = new Message();

            String nextLine = reader.readLine();
            while (!nextLine.contains("}")) {
                readMessageField(message, nextLine);
                nextLine = reader.readLine();
            }

            log.setMessage(message);
            break;
        }
        case "visibility": {
            String s = line2.split(":")[1].replace("\"", "");
            s = s.substring(2, s.length() - 1);
            List<Visibility> visibilityList = Arrays.stream(s.split(","))
                    .map(String::trim)
                    .map(Visibility::valueOf)
                    .toList();
            log.setVisibility(visibilityList);
            break;
        }
        }
    }

    /**
     * Parses the next {@link Message} field
     *
     * @param message
     *         the {@link Message} where the field is set
     * @param line
     *         the line to parse
     */
    private static void readMessageField(Message message, String line) {
        String fieldName = line.split(":")[0].replace("\"", "").trim();

        String[] split2 = line.split(":");
        String s = (split2[1] + ":" + split2[2]).replace("\"", "");

        switch (fieldName) {
        case "file": {
            message.setFile(s.substring(1, s.length() - 1));
            break;
        }
        case "text": {
            message.setText(s.substring(1, s.length() - 1));
            break;
        }

        }
    }

}