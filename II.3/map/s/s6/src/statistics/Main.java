package statistics;

import java.time.Instant;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        List<Integer> list = IntStream.range(0,1000).mapToObj(i->rand.nextInt()).toList();

        Instant start1 = Instant.now();

        Integer sum = 0;
        for (Integer i : list) {
            sum += i;
        }
        System.out.println("Sum mit for: "+sum);

        Integer max = Integer.MIN_VALUE;
        for (Integer i : list) {
            if (max < i) {
                max = i;
            }
        }
        System.out.println("Max mit for: "+max);

        System.out.println("Time: "+ (Instant.now().toEpochMilli()-start1.toEpochMilli())+"ms");

        ExecutorService executors = Executors.newFixedThreadPool(16);
        Instant start2 = Instant.now();

        Callable<Integer> sum3 = new Statistics.Sum(list, executors);
        Callable<Integer> max3 = new Statistics.Max(list, executors);

        Future<Integer> sum4 = executors.submit(sum3);
        Future<Integer> max4 = executors.submit(max3);

        try {
            System.out.println("sum mit threads: "+ sum4.get());
            System.out.println("max mit threads: "+ max4.get());
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }

        System.out.println("Time: "+ (Instant.now().toEpochMilli()-start2.toEpochMilli())+"ms");

    }
}
