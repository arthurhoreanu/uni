package log.parser;

import log.model.FileType;

/**
 * This factory creates the appropriate {@link LogParser} for the supported {@link FileType}s
 */
public class LogParserFactory {
    private LogParserFactory() {
    }

    public static LogParser getParser(FileType type) {
        return switch (type) {
            case CSV -> CSVLogParser.getInstance();
            case TSV -> TSVLogParser.getInstance();
            case JSON -> JSONLogParser.getInstance();
            case XML -> XMLLogParser.getInstance();
        };
    }
}
