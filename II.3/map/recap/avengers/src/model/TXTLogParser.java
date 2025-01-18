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
public class TXTLogParser {

    public List<Log> parse(String filePath) throws IOException {
        List<Log> logEntries = new ArrayList<>();
        Path file = Path.of(filePath);

        try (BufferedReader reader = Files.newBufferedReader(file)) {
            String header = reader.readLine(); // Ignore header row
            String line;
            while ((line = reader.readLine()) != null) {
                String[] field = line.split("#");
                if (field.length != 7) continue; // Filed number validation
                int id = Integer.parseInt(field[0]);
                String name = field[1];
                Group group = Group.valueOf(field[2].toUpperCase());
                String task = field[3];
                Difficulty difficulty = Difficulty.valueOf(field[4].toUpperCase());
                int points = Integer.parseInt(field[5]);
                String success = field[6];
                logEntries.add(new Log(id, name, group, task, difficulty, points, success));
            }
        }
        return logEntries;
    }
}