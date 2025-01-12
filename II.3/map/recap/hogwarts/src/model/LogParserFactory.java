package model;

/**
 * Factory for selecting the right parser based on file extension.
 */
public class LogParserFactory {

    /**
     * Returns the right parser for the given extension.
     *
     * @param fileType File extension (txt, csv, json, etc.).
     * @return Instance of a LogParser.
     * @throws IllegalArgumentException If format is not supported.
     */
    public static LogParser getParser(String fileType) {
        return switch (fileType.toLowerCase()) {
            case "txt" -> new TXTLogParser();
            case "csv" -> new CSVLogParser();
            case "json" -> new JSONLogParser();
            case "xml" -> new XMLLogParser();
            case "tsv" -> new TSVLogParser();
            default -> throw new IllegalArgumentException("Unsupported file type: " + fileType);
        };
    }
}
