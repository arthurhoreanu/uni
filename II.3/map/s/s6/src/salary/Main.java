package salary;

import java.time.Instant;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        List<Employee> employees = IntStream.range(0, 10000000)
                .mapToObj(i -> new Employee("Employee" + i, rand.nextInt(1000, 10000)))
                .toList();

        SimpleCalculator simpleCalculator = new SimpleCalculator();
        StreamCalculator streamCalculator = new StreamCalculator();
        ThreadCalculator threadCalculator = new ThreadCalculator();

        timeCalculator(simpleCalculator,employees);
        timeCalculator(streamCalculator,employees);
        timeCalculator(threadCalculator,employees);
    }

    public static void timeCalculator(Calculator calculator,List<Employee> employees) {
        Instant start = Instant.now();
        calculator.employeeStatistics(employees);
        System.out.println("Time: " + (Instant.now().toEpochMilli() - start.toEpochMilli())+"ms");
    }
}
