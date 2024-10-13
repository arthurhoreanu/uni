package strategy;

public class SubStrategy implements MathStrategy {
    @Override
    public double op(double x, double y) {
        return x - y;
    }
}
