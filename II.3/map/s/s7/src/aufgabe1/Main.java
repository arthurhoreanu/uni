package aufgabe1;

import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.PriorityBlockingQueue;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> inputQueue = new PriorityBlockingQueue<>();
        Queue<Integer> outputQueue = new PriorityBlockingQueue<>();

        IntStream.range(0, 10000).forEach(inputQueue::add);

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number of worker threads: ");
        int n = scanner.nextInt();

        List<Worker> workers = IntStream.range(0, n).mapToObj(i -> new Worker(inputQueue, outputQueue, i)).toList();

        try (ExecutorService executor = Executors.newFixedThreadPool(16)) {
            List<Future<Void>> futures = executor.invokeAll(workers);

            while (!futures.stream().allMatch(Future::isDone)) {
                Thread.sleep(100);
            }

            System.out.println(outputQueue.size());
            //            executor.submit(new Printer(outputQueue));

        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }
}
