package strategy;

public class DivStrategy implements MathStrategy {
    @Override
    public double op(double x, double y) {
        return x - y;
    }
}
