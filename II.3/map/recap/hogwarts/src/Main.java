import controller.HogwartsController;
import model.Log;
import model.LogParser;
import model.LogParserFactory;
import view.ConsoleView;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            LogParser parser = LogParserFactory.getParser("txt");
            List<Log> logEntries = parser.parse("src/logs/punkte.txt");

            HogwartsController controller = new HogwartsController(logEntries);

            ConsoleView view = new ConsoleView(controller);
            view.menu();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
