package log;

import java.io.IOException;

import log.parser.LogParser;

public class LogStatistic {
    private final LogParser logParser;

    private final String path;

    public LogStatistic(LogParser logParser, String path) {
        this.logParser = logParser;
        this.path = path;
    }

    public void print() {
        try {
            this.logParser.parseLogs(path).forEach(System.out::println);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public void sortedPrint() {
        try {
            this.logParser.parseLogs(path).stream().sorted().forEach(System.out::println);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
