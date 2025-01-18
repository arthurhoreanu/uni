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

}