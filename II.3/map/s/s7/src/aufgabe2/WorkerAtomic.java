package aufgabe2;

import java.util.concurrent.atomic.AtomicInteger;

public class WorkerAtomic implements Runnable {
    AtomicInteger atomicInteger;

    WorkerAtomic(AtomicInteger atomicInteger) {
        this.atomicInteger = atomicInteger;
    }

    @Override
    public void run() {
        while (atomicInteger.get() < 50) {
            System.out.println(atomicInteger.getAndIncrement());
        }
    }
}
