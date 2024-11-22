package aufgabe3;

import java.util.concurrent.Callable;

public class Creator implements Callable<Singleton> {
    @Override
    public Singleton call() throws Exception {
        return Singleton.getInstance();
    }
}
