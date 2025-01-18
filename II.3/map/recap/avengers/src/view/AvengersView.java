package view;

import controller.AvengersController;
import model.*;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class AvengersView {

    private TXTLogParser parser;
    private List<Log> logEntries;

    private final AvengersController controller;
    private final Scanner scanner = new Scanner(System.in);

    public AvengersView() throws IOException {
        this.parser = new TXTLogParser(); // Initialize parser
        this.logEntries = parser.parse("src/logs/avengers.txt"); // Parse logs
        this.controller = new AvengersController(logEntries); // Initialize controller with logs
    }

    public void menu() {
        while (true) {
            System.out.println();
            System.out.println("Press:");
            System.out.println("1. Sort by difficulty");
            System.out.println("2. Avengers with at least one success");
            System.out.println("3. Sort Avengers' scores");
            String input = scanner.nextLine();

            switch (input) {
                case "1":
                    controller.sortDifficulty();
                    break;
                case "2":
                    controller.oneSuccess();
                    break;
                case "3":
                    controller.calculateAndSaveResults("src/logs/result.txt");
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
}