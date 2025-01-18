import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class View {

    private TSVLogParser parser;
    private List<Log> logEntries;

    private final Controller controller;
    private final Scanner scanner = new Scanner(System.in);

    public View() throws IOException {
        this.parser = new TSVLogParser(); // Initialize parser
        this.logEntries = parser.parse("src/evenimente.tsv"); // Parse logs
        this.controller = new Controller(logEntries); // Initialize controller with logs
    }

    public void menu() {
        while (true) {
            System.out.println();
            System.out.println("Press:");
            System.out.println("1. Filter character by letter");
            System.out.println("2. Sort Stark events by date");
            String input = scanner.nextLine();

            switch (input) {
                case "1":
                    filterCharacterByLetter();
                    break;
                case "2":
                    sortStarkEvents();
                    break;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }

    }

    /**
     * Filters Character by first letter.
     */
    private void filterCharacterByLetter() {
        System.out.print("Enter a capital letter: ");
        String letter = scanner.nextLine();
        controller.filterCharacterByLetter(letter).forEach(System.out::println);
    }

    /**
     * Sort Stark events by date.
     */
    private void sortStarkEvents() {
        controller.sortStarkEvents().forEach(System.out::println);
    }
}
