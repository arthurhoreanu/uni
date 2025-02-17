import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Controller {

    private final List<Log> logEntries;

    public Controller(List<Log> logEntries) {
        this.logEntries = logEntries;
    }

    /**
     * Filter characters by user input first letter.
     * @param letter
     * @return
     */
    public List<String> filterCharacterByLetter(String letter) {
        Set<String> uniqueCharacters = new HashSet<>();
        for (Log entry : logEntries) {
            String characterName = entry.getName();
            if (characterName.startsWith(String.valueOf(letter))) {
                uniqueCharacters.add(characterName);
            }
        }
        return new ArrayList<>(uniqueCharacters); // Converting to List, printStudents needs a List parameter
    }

    /**
     * Sort Stark events by date.
     * @return
     */
    public List<Log> sortStarkEvents() {
        List<Log> starkEvents = new ArrayList<>();
        for (Log entry : logEntries) {
            if(entry.getHouse()== House.STARK)
                starkEvents.add(entry);
        }
        starkEvents.sort(Comparator.comparing(Log::getDate));
        return starkEvents;
    }

    public void getHouseResults(String filePath) {
        Map<House, Integer> houseScores = new HashMap<>();

        // 1. Calculate the scores for each house
        for (Log entry : logEntries) {
            House house = entry.getHouse();

            // Add points to the corresponding house
            houseScores.put(house, houseScores.getOrDefault(house, 0) + 1);
        }

        // 2. Sort the houses by their scores in descending order
        List<Map.Entry<House, Integer>> sortedHouseScores = new ArrayList<>(houseScores.entrySet());
        sortedHouseScores.sort((e1, e2) -> e2.getValue().compareTo(e1.getValue())); // Descending order

        // 3. Write the sorted results to the file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Map.Entry<House, Integer> entry : sortedHouseScores) {
                writer.write(entry.getKey() + "#" + entry.getValue());
                writer.newLine();
            }
            System.out.println("Results have been successfully saved to " + filePath);
        } catch (IOException e) {
            System.err.println("An error occurred while writing to the file: " + e.getMessage());
        }
    }

}