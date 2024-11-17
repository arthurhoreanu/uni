package matrix;

import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.function.BiConsumer;
import java.util.stream.IntStream;

public class Main {

    private static final Random rand = new Random();

    public static void main(String[] args) {
        int x = 10000;
        int y = 10000;
        List<List<Integer>> matrix1 = generateMatrix(x, y);
        List<List<Integer>> matrix2 = generateMatrix(x, y);

        System.out.print("Add:                          ");
        timeOp(Main::simpleAdd, matrix1, matrix2);
        System.out.print("Add on multiple threads:      ");
        timeOp(Main::threadAdd, matrix1, matrix2);

        x = 1000;
        y = 1000;
        matrix1 = generateMatrix(x, y);
        matrix2 = generateMatrix(x, y);

        System.out.print("Multiply:                     ");
        timeOp(Main::simpleMultiply, matrix1, matrix2);
        System.out.print("Multiply on multiple threads: ");
        timeOp(Main::threadMultiply, matrix1, matrix2);
    }

    private static List<List<Integer>> generateMatrix(int x, int y) {
        return IntStream.range(0, y).mapToObj(yy -> IntStream.range(0, x).mapToObj(xx -> rand.nextInt()).toList()).toList();
    }

    private static void timeOp(BiConsumer<List<List<Integer>>, List<List<Integer>>> op,
            List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        Instant start = Instant.now();
        op.accept(matrix1, matrix2);
        System.out.println((Instant.now().toEpochMilli() - start.toEpochMilli()) + "ms");
    }

    private static List<List<Integer>> threadAdd(List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        int y = matrix1.size();
        int x = matrix2.getFirst().size();

        List<Callable<List<Integer>>> rowOps = IntStream.range(0, y).mapToObj(i ->
                (Callable<List<Integer>>) () ->
                        IntStream.range(0, x).mapToObj(j -> matrix1.get(i).get(j) + matrix2.get(i).get(j)).toList()
        ).toList();

        return runRowOps(rowOps);
    }

    private static List<List<Integer>> simpleAdd(List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        int y = matrix1.size();
        int x = matrix2.getFirst().size();

        return IntStream.range(0, y).mapToObj(i ->
                        IntStream.range(0, x).mapToObj(j ->
                                        matrix1.get(i).get(j) + matrix2.get(i).get(j))
                                .toList())
                .toList();
    }

    private static List<List<Integer>> threadMultiply(List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        int x1 = matrix1.getFirst().size();
        int x2 = matrix2.getFirst().size();

        List<Callable<List<Integer>>> rowOps = matrix1.stream().map(integers -> (Callable<List<Integer>>) () -> {
            List<Integer> newRow = new ArrayList<>();
            for (int j = 0; j < x2; j++) {
                int sum = 0;
                for (int k = 0; k < x1; k++) {
                    sum += integers.get(k) * matrix2.get(k).get(j);
                }
                newRow.add(sum);
            }
            return newRow;
        }).toList();

        return runRowOps(rowOps);
    }

    private static List<List<Integer>> simpleMultiply(List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        int y1 = matrix1.size();
        int x1 = matrix1.getFirst().size();
        int x2 = matrix2.getFirst().size();

        List<List<Integer>> resultMatrix = new ArrayList<>();

        for (int i = 0; i < y1; i++) {
            List<Integer> newRow = new ArrayList<>();
            for (int j = 0; j < x2; j++) {
                int sum = 0;
                for (int k = 0; k < x1; k++) {
                    sum += matrix1.get(i).get(k) * matrix2.get(k).get(j);
                }
                newRow.add(sum);
            }
            resultMatrix.add(newRow);
        }

        return resultMatrix;
    }

    private static List<List<Integer>> runRowOps(List<Callable<List<Integer>>> rowOps) {
        List<List<Integer>> resultMatrix;
        try (ExecutorService executorService = Executors.newFixedThreadPool(16)) {

            List<Future<List<Integer>>> futureList = executorService.invokeAll(rowOps);

            resultMatrix = futureList.stream().map(future -> {
                try {
                    return future.get();
                } catch (InterruptedException | ExecutionException e) {
                    throw new RuntimeException(e);
                }
            }).toList();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return resultMatrix;
    }

    private static void printMatrix(List<List<Integer>> matrix) {
        for (List<Integer> row : matrix) {
            for (Integer i : row) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}