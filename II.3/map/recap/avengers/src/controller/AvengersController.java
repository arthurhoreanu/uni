package controller;

import model.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class AvengersController {

    private final List<Log> logEntries;

    public AvengersController(List<Log> logEntries) {
        this.logEntries = logEntries;
    }

    public void sortDifficulty() {
        for(Log entry: logEntries) {
            if (entry.getDifficulty() == Difficulty.EASY) {
                System.out.println(entry.getTask());}}
        for (Log entry: logEntries) {
            if (entry.getDifficulty() == Difficulty.MEDIUM) {
                System.out.println(entry.getTask());}}
        for (Log entry: logEntries) {
            if (entry.getDifficulty() == Difficulty.HARD) {
                System.out.println(entry.getTask());
            }
        }
    }

    public void oneSuccess() {
        HashSet<Log> logs = new HashSet<>();
        for(Log entry: logEntries) {
            if(Objects.equals(entry.getSuccess(), "win"))
                logs.add(entry);
        }
        ArrayList<Log> sortedLogs = new ArrayList<>(logs);
        sortedLogs.sort(Comparator.comparing(Log::getName));
        for(Log entry: sortedLogs) {
            System.out.println(entry.getName());
        }
    }

    public void calculateAndSaveResults(String filePath) {

        Map<String, Integer> scores = new HashMap<>();

        for (Log log: logEntries) {
            String name = log.getName();
            int points = log.getPoints();
            String isSuccess = log.getSuccess();

            if (!scores.containsKey(name)) {
                scores.put(name, 0);
            }

            if ("win".equalsIgnoreCase(isSuccess)) {
                scores.put(name, scores.get(name) + points);
            } else {
                scores.put(name, scores.get(name) - points);
            }

            List<Map.Entry<String, Integer>> sortedScores = new ArrayList<>(scores.entrySet());

            for (int i = 0; i < sortedScores.size() - 1; i++) {
                for (int j = i + 1; j < sortedScores.size(); j++) {
                    if (sortedScores.get(i).getValue() < sortedScores.get(j).getValue()) {
                        Map.Entry<String, Integer> temp = sortedScores.get(i);
                        sortedScores.set(i, sortedScores.get(j));
                        sortedScores.set(j, temp);
                    }
                }
            }

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
                for (Map.Entry<String, Integer> entry : sortedScores) {
                    writer.write(entry.getKey() + "&" + entry.getValue());
                    writer.newLine();
                }
                System.out.println("Results have been successfully saved to " + filePath);
            } catch (IOException e) {
                System.err.println("An error occurred while writing to the file: " + e.getMessage());
            }
        }
        }
    }