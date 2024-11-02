package enum_karte;

public class Karte {
    private final Farbe farbe;
    private final Wert wert;

    public Karte(Farbe farbe, Wert wert){
        this.farbe = farbe;
        this.wert = wert;
    }

    @Override
    public String toString() {
        return "Karte{" +
                "farbe=" + farbe +
                ", wert=" + wert +
                '}';
    }
}
