package model;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * Parser for TSV files.
 */
public class TSVLogParser implements LogParser {
    @Override
    public List<Log> parse(String filePath) throws IOException {
        List<Log> logEntries = new ArrayList<>();
        Path file = Path.of(filePath);

        try (BufferedReader reader = Files.newBufferedReader(file)) {
            String header = reader.readLine(); // Read and skip header
            String line;

            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("\t");

                if (parts.length == 5) {
                    int id = Integer.parseInt(parts[0].trim());
                    String studentName = parts[1].trim();
                    House house = House.valueOf(parts[2].trim().toUpperCase());
                    String authority = parts[3].trim();
                    int points = Integer.parseInt(parts[4].trim());

                    logEntries.add(new Log(id, studentName, house, authority, points));
                }
            }
        }
        return logEntries;
    }
}
