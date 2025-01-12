package model;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * Parser for TXT files.
 */
public class TXTLogParser implements LogParser {

    @Override
    public List<Log> parse(String filePath) throws IOException {
        List<Log> logEntries = new ArrayList<>();
        Path file = Path.of(filePath);

        try (BufferedReader reader = Files.newBufferedReader(file)) {
            String header = reader.readLine(); // Ignore header row
            String line;
            while ((line = reader.readLine()) != null) {
                String[] field = line.split("&");
                if (field.length != 5) continue; // Filed number validation
                int id = Integer.parseInt(field[0]);
                String studentName = field[1];
                House house = House.valueOf(field[2].toUpperCase());
                String authority = field[3];
                int points = Integer.parseInt(field[4]);

                logEntries.add(new Log(id, studentName, house, authority, points));
            }
        }
        return logEntries;
    }
}