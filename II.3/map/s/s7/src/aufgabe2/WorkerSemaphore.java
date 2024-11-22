package aufgabe2;

import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

public class WorkerSemaphore implements Runnable {
    AtomicInteger number;

    Semaphore semaphore;

    WorkerSemaphore(AtomicInteger number, Semaphore semaphore) {
        this.number = number;
        this.semaphore = semaphore;
    }

    @Override
    public void run() {
        while (true) {
            try {
                semaphore.acquire();
                if (number.get() >= 50) {
                    break;
                }
                System.out.println(number.getAndIncrement());
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            } finally {
                semaphore.release();
            }
        }
    }
}
