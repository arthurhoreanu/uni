package aufgabe2;

public class Worker implements Runnable {
    Integer number;

    Worker(Integer number) {
        this.number = number;
    }

    @Override
    public void run() {
        while (number < 50) {
            number++;
            System.out.println(number);
        }
    }

}
