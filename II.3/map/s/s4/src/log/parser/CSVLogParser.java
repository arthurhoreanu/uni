package log.parser;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDateTime;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;

import log.model.Log;
import log.model.Message;
import log.model.Severity;
import log.model.Visibility;

/**
 * This is a {@link LogParser} for {@code FileType.CSV}
 */
public class CSVLogParser implements log.parser.LogParser {

    private static CSVLogParser instance;

    private CSVLogParser() {
    }

    public static CSVLogParser getInstance() {
        if (instance == null) {
            instance = new CSVLogParser();
        }
        return instance;
    }

    /**
     * {@inheritDoc}
     */
    public List<Log> parseLogs(String path) throws IOException {
        Path filePath = Path.of(path);

        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            String header = reader.readLine();
            String[] fields = header.split(",");
            return reader.lines().map(parseCSVLine(fields)).toList();

        }

    }

    /**
     * Parses a single {@link Log} entry
     *
     * @param fields
     *         the fields previously read from the header
     * @return the parsed {@link Log}
     */
    private static Function<String, Log> parseCSVLine(String[] fields) {
        return line -> {
            String[] values = line.split(",");

            Log log = new Log();
            Message message = new Message();

            for (int i = 0; i < fields.length; i++) {
                String value = values[i].replace("\"", "");
                switch (fields[i]) {
                case "timestamp": {
                    log.setTimestamp(LocalDateTime.parse(value));
                    break;
                }
                case "visibility": {
                    log.setVisibility(Arrays.stream(value.split(";"))
                            .map(String::trim)
                            .map(Visibility::valueOf).toList());
                    break;
                }
                case "severity": {
                    log.setSeverity(Severity.valueOf(value));
                    break;
                }
                case "message_text": {
                    message.setText(value);
                    break;
                }
                case "message_file": {
                    message.setFile(value);
                    break;
                }
                }
            }
            log.setMessage(message);
            return log;
        };
    }
}
