package log.parser;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import log.model.Log;
import log.model.Message;
import log.model.Severity;
import log.model.Visibility;

/**
 * This is a {@link LogParser} for {@code FileType.XML}
 */
public class XMLLogParser implements LogParser {

    private static final Pattern TIMESTAMP_PATTERN = Pattern.compile(
            "\\p{javaSpaceChar}*<timestamp>(\\d{4}-\\d{2}-\\d{2}T\\d{2}:\\d{2}:\\d{2})</timestamp>");

    public static final Pattern SEVERITY_PATTERN = Pattern.compile(
            "\\p{javaSpaceChar}*<severity>(" + Severity.DEBUG + "|" + Severity.ERROR + "|" + Severity.FATAL + "|"
                    + Severity.INFO + "|" + Severity.WARN + ")</severity>");

    private static final Pattern VISIBILITY_PATTERN = Pattern.compile(
            "\\p{javaSpaceChar}*<level>(" + Visibility.low + "|" + Visibility.medium + "|" + Visibility.high + ")</level>");

    private static final Pattern FILE_PATTERN = Pattern.compile("\\p{javaSpaceChar}*<file>(.*)</file>");

    private static final Pattern TEXT_PATTERN = Pattern.compile("\\p{javaSpaceChar}*<text>(.*)</text>");

    private static XMLLogParser instance;

    private XMLLogParser() {
    }

    public static XMLLogParser getInstance() {
        if (instance == null) {
            instance = new XMLLogParser();
        }
        return instance;
    }

    /**
     * {@inheritDoc}
     */
    public List<Log> parseLogs(String path) throws IOException {
        Path filePath = Path.of(path);

        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            if (!reader.readLine().equals("<logs>")) {
                throw new IOException("Invalid log file");
            }

            List<Log> logs = new ArrayList<>();
            String nextLine = reader.readLine();

            while (!nextLine.equals("</logs>")) {
                logs.add(parseLog(reader, nextLine));
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
    private Log parseLog(BufferedReader reader, String firstLine) throws IOException {
        Log log = new Log();

        if (!firstLine.contains("<log>")) {
            throw new IOException("Invalid log file");
        }

        String nextLine = reader.readLine();
        while (true) {
            parseField(reader, nextLine, log);
            nextLine = reader.readLine();
            if (nextLine.contains("</log>")) {
                return log;
            }
        }
    }

    /**
     * Parses the next {@link Log} field
     *
     * @param reader
     *         the Reader to read from
     * @param log
     *         the {@link Log} where the field is set
     */
    private void parseField(BufferedReader reader, String firstLine, Log log) throws IOException {
        Matcher timestampMatcher = TIMESTAMP_PATTERN.matcher(firstLine);
        if (timestampMatcher.matches()) {
            log.setTimestamp(LocalDateTime.parse(timestampMatcher.group(1)));
        }

        Matcher severityMatcher = SEVERITY_PATTERN.matcher(firstLine);
        if (severityMatcher.matches()) {
            log.setSeverity(Severity.valueOf(severityMatcher.group(1)));
        }

        if (firstLine.contains("<visibility>")) {
            log.setVisibility(parseVisibilities(reader));
        }

        if (firstLine.contains("<message>")) {
            log.setMessage(parseMessage(reader));
        }

    }

    private static Message parseMessage(BufferedReader reader) throws IOException {
        Message message = new Message();

        String nextLine = reader.readLine();
        while (true) {
            Matcher fileMatcher = FILE_PATTERN.matcher(nextLine);
            if (fileMatcher.matches()) {
                message.setFile(fileMatcher.group(1));
            }
            Matcher matcher = TEXT_PATTERN.matcher(nextLine);
            if (matcher.matches()) {
                message.setText(matcher.group(1));
            }
            nextLine = reader.readLine();
            if (nextLine.contains("</message>")) {
                return message;
            }
        }
    }

    private static ArrayList<Visibility> parseVisibilities(BufferedReader reader) throws IOException {
        ArrayList<Visibility> visibilities = new ArrayList<>();

        String nextLine = reader.readLine();
        while (true) {
            Matcher matcher = VISIBILITY_PATTERN.matcher(nextLine);
            if (matcher.matches()) {
                visibilities.add(Visibility.valueOf(matcher.group(1)));
            }
            nextLine = reader.readLine();
            if (nextLine.contains("</visibility>")) {
                return visibilities;
            }
        }
    }
}
