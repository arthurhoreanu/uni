package view;

import controller.HogwartsController;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

/**
 * ConsoleView provides a menu-driven interface for interacting with HogwartsController.
 */
public class ConsoleView {
    private final HogwartsController controller;
    private final Scanner scanner;

    public ConsoleView(HogwartsController controller) {
        this.controller = controller;
        this.scanner = new Scanner(System.in);
    }

    /**
     * Main menu for the console application.
     */
    public void menu() throws IOException {
        while (true) {
            System.out.println();
            System.out.println("1. Show all students whose names start with a specific letter");
            System.out.println("2. Show all Gryffindor students");
            System.out.println("3. Show house results");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            String input = scanner.nextLine();

            switch (input) {
                case "1":
                    handleStudentsByLetter();
                    break;
                case "2":
                    printStudents(controller.getGryffindorStudents());
                    break;
                case "3":
                    printHouseResults();
                    break;
                case "4":
                    System.out.println("Exiting the application. Goodbye!");
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }

    /**
     * Handles the option to display students whose names start with a specific letter.
     */
    private void handleStudentsByLetter() {
        System.out.print("Enter a capital letter: ");
        String letter = scanner.nextLine();
        controller.getStudentsByLetter(letter).forEach(System.out::println);
    }

    /**
     * Prints a list of students.
     *
     * @param students The list of student names.
     */
    private void printStudents(List<String> students) {
        if (students.isEmpty()) {
            System.out.println("No students found.");
        } else {
            students.forEach(System.out::println);
        }
    }

    /**
     * Prints the house results.
     */
    private void printHouseResults() {
        controller.getHouseResults("src/logs/ergebnis.txt");
    }
}
