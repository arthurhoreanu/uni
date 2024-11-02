import log.LogStatistic;
import log.model.FileType;
import log.parser.LogParser;
import log.parser.LogParserFactory;

public class Main {
    public static void main(String[] args) {
        System.out.println("XML Log");
        parseLogByType(FileType.XML);

        System.out.println("JSON Log");
        parseLogByType(FileType.JSON);

        System.out.println("CSV Log");
        parseLogByType(FileType.CSV);

        System.out.println("TSV Log");
        parseLogByType(FileType.TSV);
    }

    private static void parseLogByType(FileType fileType) {
        LogParser parser = LogParserFactory.getParser(fileType);
        String path = "logs\\logs." + fileType.name().toLowerCase();

        LogStatistic stat = new LogStatistic(parser, path);
        System.out.println("Normal print");
        stat.print();
        System.out.println("Sorted print");
        stat.sortedPrint();
    }
}
