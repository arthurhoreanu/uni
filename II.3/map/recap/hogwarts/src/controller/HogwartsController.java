package controller;

import model.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


/**
 * The Controller manages the application logic.
 */
public class HogwartsController {
    private final List<Log> logEntries;

    public HogwartsController(List<Log> logEntries) {
        this.logEntries = logEntries;
    }

    //b
    /**
     * Returns all the students whose names begin with a specified letter.
     */
    public List<String> getStudentsByLetter(String letter) {
        Set<String> uniqueStudents = new HashSet<>(); // Eliminating students that show up more than once
        for (Log entry : logEntries) {
            String studentName = entry.getStudentName();
            if (studentName.startsWith(String.valueOf(letter))) {
                uniqueStudents.add(studentName);
            }
        }
        return new ArrayList<>(uniqueStudents); // Converting to List, printStudents needs a List parameter
    }

    //c
    /**
     * Returns all the Gryffindor in alphabetical order.
     */
    public List<String> getGryffindorStudents() {
        Set<String> uniqueStudents = new HashSet<>();
        for (Log entry : logEntries) {
            if (entry.getHouse() == House.GRYFFINDOR) {
                uniqueStudents.add(entry.getStudentName());
            }
        }
        List<String> sortedStudents = new ArrayList<>(uniqueStudents);
        Collections.sort(sortedStudents);

        return sortedStudents;
    }

    //d
    /**
     * Calculates the house scores and sorts them in descending order.
     */
    public void getHouseResults(String filePath) {
        Map<House, Integer> houseScores = new HashMap<>();

        // 1. Calculate the scores for each house
        for (Log entry : logEntries) {
            House house = entry.getHouse();
            int points = entry.getPoints();

            // Add points to the corresponding house
            houseScores.put(house, houseScores.getOrDefault(house, 0) + points);
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