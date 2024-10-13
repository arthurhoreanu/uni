package box;

public class Hammer implements Tool {

    private double weight;

    public Hammer(double weight) {
        this.weight = weight;
    }

    @Override
    public double getWeight() {
        return weight;
    }

    @Override
    public boolean canCut() {
        return false;
    }

    @Override
    public String toString() {
        return "Haemmer{" +
                "weight=" + weight +
                '}';
    }
}
