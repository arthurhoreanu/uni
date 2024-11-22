package aufgabe3;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        List<Creator> creators = IntStream.range(0, 100).mapToObj(i -> new Creator()).toList();
        try (ExecutorService executor = Executors.newFixedThreadPool(16)) {
            List<Future<Singleton>> futures = executor.invokeAll(creators);

            List<Singleton> singletons = new ArrayList<>(creators.size());

            for (Future<Singleton> future : futures) {
                singletons.add(future.get());
            }

            singletons.forEach(System.out::println);

        } catch (InterruptedException | ExecutionException e) {
            throw new RuntimeException(e);
        }

    }
}
