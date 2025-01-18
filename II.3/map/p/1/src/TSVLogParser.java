import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Parser for TSV files.
 */
public class TSVLogParser {

    public List<Log> parse(String filePath) throws IOException {
        List<Log> logEntries = new ArrayList<>();
        Path file = Path.of(filePath);

        try (BufferedReader reader = Files.newBufferedReader(file)) {
            String header = reader.readLine(); // Ignore header row
            String line;
            while ((line = reader.readLine()) != null) {
                String[] field = line.split("\t");
                if (field.length != 5) continue; // Filed number validation
                int id = Integer.parseInt(field[0]);
                String name = field[1];
                House house = House.valueOf(field[2].toUpperCase());
                String event = field[3];
                LocalDate date = LocalDate.parse(field[4]);
                logEntries.add(new Log(id, name, house, event, date));
            }
        }
        return logEntries;
    }
}