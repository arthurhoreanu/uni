package aufgabe1;

import java.util.Queue;
import java.util.concurrent.Callable;

public class Worker implements Callable<Void> {
    Queue<Integer> inputQueue;

    Queue<Integer> outputQueue;

    Integer threadNr;

    public Worker(Queue<Integer> inputQueue, Queue<Integer> outputQueue, Integer threadNr) {
        this.inputQueue = inputQueue;
        this.outputQueue = outputQueue;
        this.threadNr = threadNr;
    }

    @Override
    public Void call() {
        Integer number = inputQueue.poll();
        while (number != null) {
            //            System.out.println("Thread "+threadNr+" dequeued: "+number);
            outputQueue.add(number * number);
            number = inputQueue.poll();
        }
        return null;
    }
}
