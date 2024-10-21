package karte;

public class Karte {
    private String farbe;
    private int wert;

    public Karte(String farbe, int wert) {
        this.farbe = farbe;
        this.wert = wert;
    }

    @Override
    public String toString() {
        return farbe + " " + wert;
    }
}
