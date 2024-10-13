package strategy;

public class AddStrategy implements MathStrategy {
    @Override
    public double op(double x, double y) {
        return x + y;
    }
}
