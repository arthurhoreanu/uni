package box;

public class Saw implements Tool {

    double weight;

    public Saw(double weight) {
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
        return "Saegen{" +
                "weight=" + weight +
                '}';
    }
}
