package box;

public class Scissor implements Tool {

    private double weight;

    public Scissor(double weight) {
        this.weight = weight;
    }

    @Override
    public double getWeight() {
        return weight;
    }

    @Override
    public boolean canCut() {
        return true;
    }

    @Override
    public String toString() {
        return "Scheren{" +
                "weight=" + weight +
                '}';
    }
}
