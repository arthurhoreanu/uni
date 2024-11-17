package salary;

import java.util.List;

public class SimpleCalculator implements Calculator {
    @Override
    public void employeeStatistics(List<Employee> employees) {
        System.out.println("Simple calculator");
        sum(employees);
        avg(employees);
        min(employees);
        max(employees);
    }

    private void sum(List<Employee> employees) {
        Integer sum = 0;
        for (Employee employee : employees) {
            sum += employee.getSalary();
        }
        System.out.println("Sum of employees: " + sum);
    }

    private void avg(List<Employee> employees) {
        Integer avg = 0;
        for (Employee employee : employees) {
            avg += employee.getSalary();
        }
        System.out.println("Avg of employees: " + avg/employees.size());
    }

    private void min(List<Employee> employees) {
        Integer min = Integer.MAX_VALUE;
        for (Employee employee : employees) {
            if (employee.getSalary() < min) {
                min = employee.getSalary();
            }
        }
        System.out.println("Min of employees: " + min);
    }

    private void max(List<Employee> employees) {
        Integer max = Integer.MIN_VALUE;
        for (Employee employee : employees) {
            if (employee.getSalary() > max) {
                max = employee.getSalary();
            }
        }
        System.out.println("Max of employees: " + max);
    }
}
