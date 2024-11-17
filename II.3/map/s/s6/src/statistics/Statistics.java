package statistics;

import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;

public class Statistics {
public static class Sum implements Callable <Integer> {
    List<Integer> numbers;
    ExecutorService executorService;
    public Sum(List<Integer> numbers, ExecutorService executorService) {
        this.numbers = numbers;
        this.executorService = executorService;
    }
    public Integer call() throws Exception {
        if (numbers.size()<=250){
            return numbers.stream().mapToInt(Integer::intValue).sum();
        }
        else {
            Sum sum1 = new Sum(numbers.subList(0,numbers.size()/2), executorService);
            Sum sum2 = new Sum(numbers.subList(numbers.size()/2,numbers.size()), executorService);

            Future<Integer> sum1Future = executorService.submit(sum1);
            Future<Integer> sum2Future = executorService.submit(sum2);

            return sum2Future.get() + sum1Future.get();
        }

    }

}
    public static class Max implements Callable <Integer> {
        List<Integer> numbers;
        ExecutorService executorService;
        public Max(List<Integer> numbers, ExecutorService executorService) {
            this.numbers = numbers;
            this.executorService = executorService;
        }
        public Integer call() throws Exception {
            if (numbers.size()<=250){
                return numbers.stream().mapToInt(Integer::intValue).max().getAsInt();
            }
            else {
                Max max1 = new Max(numbers.subList(0,numbers.size()/2), executorService);
                Max max2 = new Max(numbers.subList(numbers.size()/2,numbers.size()), executorService);

                Future<Integer> max1Future = executorService.submit(max1);
                Future<Integer> max2Future = executorService.submit(max2);

                Integer m1 = max1Future.get();
                Integer m2 = max2Future.get();
                return m1 > m2 ? m1 : m2;
            }
        }
    }
}
