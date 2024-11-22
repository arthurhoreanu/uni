package aufgabe2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
    public static void main(String[] args) {
        calcSemaphor();
    }

    public static void calc() {
        Integer number = 0;
        Worker worker1 = new Worker(number);
        Worker worker2 = new Worker(number);
        try (ExecutorService executor = Executors.newFixedThreadPool(16)) {
            executor.submit(worker1);
            executor.submit(worker2);
        }

    }

    public static void calcAtomic() {
        AtomicInteger number = new AtomicInteger(0);
        WorkerAtomic worker1 = new WorkerAtomic(number);
        WorkerAtomic worker2 = new WorkerAtomic(number);
        try (ExecutorService executor = Executors.newFixedThreadPool(16)) {
            executor.submit(worker1);
            executor.submit(worker2);
        }
    }

    public static void calcSemaphor() {
        Semaphore semaphore = new Semaphore(1);
        AtomicInteger number = new AtomicInteger(0);
        WorkerSemaphore workerSemaphore = new WorkerSemaphore(number, semaphore);
        WorkerSemaphore workerSemaphore1 = new WorkerSemaphore(number, semaphore);
        try (ExecutorService executor = Executors.newFixedThreadPool(16)) {
            executor.submit(workerSemaphore);
            executor.submit(workerSemaphore1);
        }
    }

}
