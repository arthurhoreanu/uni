package controller;

import model.*;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Controller care manages the application logic.
 */
public class HogwartsController {
    private final List<Log> logEntries;

    public HogwartsController(List<Log> logEntries) {
        this.logEntries = logEntries;
    }

    /**
     * Returns all the students whose names begin with a specified letter.
     */
        // TreeSet<String> for lambda
    public List<String> getStudentsByLetter(char letter) {
        Set<String> uniqueStudents = new HashSet<>(); // Eliminating students that show up more than once
        for (Log entry : logEntries) {
            String studentName = entry.getStudentName();
            if (studentName.startsWith(String.valueOf(letter))) {
                uniqueStudents.add(studentName);
            }
        }
        return new ArrayList<>(uniqueStudents); // Converting to List, printStudents needs a List parameter

        // Lambda version:
//        return logEntries.stream()
//                .map(Log::getStudentName)
//                .filter(name -> name.startsWith(String.valueOf(letter)))
//                .collect(Collectors.toCollection(TreeSet::new));
    }


    /**
     * Returns all the Gryffindor in alphabetical order.
     */
        // TreeSet<String> for lambda
    public List<String> getGryffindorStudents() {
        Set<String> uniqueStudents = new HashSet<>(); // Eliminating students that show up more than once
        for (Log entry : logEntries) {
            if (entry.getHouse() == House.GRYFFINDOR) {
                uniqueStudents.add(entry.getStudentName());
            }
        }
        List<String> sortedStudents = new ArrayList<>(uniqueStudents);  // Converting to List, printStudents needs a List parameter
        Collections.sort(sortedStudents);                               // and Collections too
        return sortedStudents;

        // Lambda version:
//        return logEntries.stream()
//                .filter(entry -> entry.getHouse() == House.GRYFFINDOR)
//                .map(Log::getStudentName)
//                .collect(Collectors.toCollection(TreeSet::new));
    }


    /**
     * Calculates the house scores and sorts them in descending order.
     */
    public Map<House, Integer> getHouseResults() {

        // 1. Calculating the score for each house
        Map<House, Integer> houseScores = new HashMap<>();
        for (Log entry : logEntries) {
            House house = entry.getHouse();
            int points = entry.getPoints();
            houseScores.put(house, houseScores.getOrDefault(house, 0) + points);
        }

        // 2. Sort the scores in descending order
        List<House> sortedHouses = new ArrayList<>(houseScores.keySet());
        sortedHouses.sort(new Comparator<House>() {
            @Override
            public int compare(House h1, House h2) {
                return houseScores.get(h2) - houseScores.get(h1);
            }
        });

        // 3. Creating a LinkedHashMap to keep the descending order sort
        Map<House, Integer> sortedHouseScores = new LinkedHashMap<>();
        for (House house : sortedHouses) {
            sortedHouseScores.put(house, houseScores.get(house));
        }

        return sortedHouseScores;
    }

    // Lambda version:
//    return logEntries.stream()
//            .collect(Collectors.groupingBy(LogEntry::getHouse, Collectors.summingInt(LogEntry::getPoints)))
//            .entrySet().stream()
//                .sorted((e1, e2) -> e2.getValue() - e1.getValue())
//            .collect(Collectors.toMap(
//            Map.Entry::getKey,
//                     Map.Entry::getValue,
//                        (e1, e2) -> e1,
//    LinkedHashMap::new
//            ));

}