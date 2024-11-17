package salary;

import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ThreadCalculator implements Calculator {

    @Override
    public void employeeStatistics(List<Employee> employees) {
        System.out.println("ex1.ThreadCalculator");
        try(ExecutorService executorService = Executors.newFixedThreadPool(4)){
            SumOperation sumOperation = new SumOperation(employees);
            AvgOperation avgOperation = new AvgOperation(employees);
            MinOperation minOperation = new MinOperation(employees);
            MaxOperation maxOperation = new MaxOperation(employees);

            Future<Integer> sumFuture = executorService.submit(sumOperation);
            Future<Integer> avgFuture = executorService.submit(avgOperation);
            Future<Integer> minFuture = executorService.submit(minOperation);
            Future<Integer> maxFuture = executorService.submit(maxOperation);

            System.out.println("Sum of employees: "+ sumFuture.get());
            System.out.println("Avg of employees: "+ avgFuture.get());
            System.out.println("Min of employees: "+ minFuture.get());
            System.out.println("Max of employees: "+ maxFuture.get());
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    public static class SumOperation implements Callable<Integer>{
        List<Employee> employees;

        public SumOperation(List<Employee> employees){
            this.employees = employees;
        }

        @Override
        public Integer call() throws Exception {
            Integer sum = 0;
            for(Employee employee : employees){
                sum += employee.getSalary();
            }
            return sum;
        }
    }

    public static class AvgOperation implements Callable<Integer>{
        List<Employee> employees;

        public AvgOperation(List<Employee> employees){
            this.employees = employees;
        }

        @Override
        public Integer call() throws Exception {
            Integer sum = 0;
            for(Employee employee : employees){
                sum += employee.getSalary();
            }
            return sum/employees.size();
        }
    }

    public static class MinOperation implements Callable<Integer>{

        List<Employee> employees;

        public MinOperation(List<Employee> employees){
            this.employees = employees;
        }

        @Override
        public Integer call() throws Exception {
            Integer min = Integer.MAX_VALUE;
            for(Employee employee : employees){
                if(employee.getSalary() < min){
                    min = employee.getSalary();
                }
            }
            return min;
        }
    }

    public static class MaxOperation implements Callable<Integer>{
        List<Employee> employees;
        public MaxOperation(List<Employee> employees){
            this.employees = employees;
        }

        @Override
        public Integer call() throws Exception {
            Integer max = Integer.MIN_VALUE;
            for(Employee employee : employees){
                if(employee.getSalary() > max){
                    max = employee.getSalary();
                }
            }
            return max;
        }
    }
}
