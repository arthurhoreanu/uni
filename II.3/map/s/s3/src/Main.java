import karte.Karte;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Stream.of("Pik", "Kreuz", "Herz", "Karo")
                .flatMap(farbe -> IntStream.range(1,14)
                        .mapToObj(wert -> new Karte(farbe, wert))).toList();

        List<String>
    }
}