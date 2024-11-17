package salary;

import java.util.List;

public class StreamCalculator implements Calculator {
    @Override
    public void employeeStatistics(List<Employee> employees) {
        System.out.println("Stream calculator");
        sum(employees);
        avg(employees);
        min(employees);
        max(employees);
    }

    private void sum(List<Employee> employees) {
        System.out.println("Sum of employees: " +
                employees.parallelStream()
                .mapToInt(Employee::getSalary).sum());
    }

    private void avg(List<Employee> employees) {
        System.out.println("Avg of employees: " + (int)employees.parallelStream()
                .mapToInt(Employee::getSalary).average().getAsDouble());
    }

    private void min(List<Employee> employees) {
        System.out.println("Min of employees: " + employees.parallelStream()
                .mapToInt(Employee::getSalary).min().getAsInt());
    }

    private void max(List<Employee> employees) {
        System.out.println("Max of employees: " + employees.parallelStream()
        .mapToInt(Employee::getSalary).max().getAsInt());
    }
}
