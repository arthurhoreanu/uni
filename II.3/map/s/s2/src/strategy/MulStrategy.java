package strategy;

public class MulStrategy implements MathStrategy {
    @Override
    public double op(double x, double y) {
        return x * y;
    }
}
