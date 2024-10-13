package box;

public class Nail implements Tool {
    @Override
    public double getWeight() {
        return 0.01;
    }

    @Override
    public boolean canCut() {
        return false;
    }

    @Override
    public String toString() {
        return "Naegel{}";
    }
}
