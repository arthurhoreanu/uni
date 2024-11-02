package tv;

public class Kanal {
    String name;

    public Kanal(String name){
        this.name = name;
    }

    @Override
    public String toString() {
        return "Kanal{" +
                "name='" + name + '\'' +
                '}';
    }
}
