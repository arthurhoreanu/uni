package view;

import controller.HogwartsController;

import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class ConsoleView {

                            // TreeSet<String> for lambda
    public void printStudents(List<String> students) {
        students.forEach(System.out::println);
    }

    public void printHouseResults(HogwartsController controller) {
        controller.getHouseResults().forEach((house, points) ->
                System.out.println(house + "#" + points));
    }
}
