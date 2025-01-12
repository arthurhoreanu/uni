import controller.HogwartsController;
import model.*;
import view.ConsoleView;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            LogParser parser = LogParserFactory.getParser("txt");
            List<Log> logEntries = parser.parse("src/logs/punkte.txt");

            HogwartsController controller = new HogwartsController(logEntries);
            ConsoleView view = new ConsoleView();

            System.out.println("All the students whose names start with H:");
            view.printStudents(controller.getStudentsByLetter('H'));

            System.out.println("");
            System.out.println("All the Gryffindor students:");
            view.printStudents(controller.getGryffindorStudents());

            System.out.println("");
            System.out.println("House results:");
            view.printHouseResults(controller);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}