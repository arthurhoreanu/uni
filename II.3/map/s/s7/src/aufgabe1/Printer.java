package aufgabe1;

import java.util.Queue;

public class Printer implements Runnable {
    Queue<Integer> outputQueue;

    public Printer(Queue<Integer> outputQueue) {
        this.outputQueue = outputQueue;
    }

    @Override
    public void run() {
        outputQueue.forEach(nr -> System.out.println("Result: " + nr));
    }
}
