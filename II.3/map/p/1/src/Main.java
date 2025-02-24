import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        new View().menu();
}}

//temp
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.core.type.TypeReference;
import org.w3c.dom.*;
        import javax.xml.parsers.*;
        import java.io.*;
        import java.nio.file.*;
        import java.time.LocalDate;
import java.util.*;
        import java.util.stream.Collectors;

enum Konfrontationstyp { Individuell, Team, Galaktisch, Multiversal }

class Konfrontation {
    int id;
    String held;
    String antagonist;
    Konfrontationstyp konfrontationstyp;
    String ort;
    LocalDate datum;
    double globalerEinfluss;

    // Constructor, Getteri, Setteri și toString
}

public class MarvelArchiv {
    public static List<Konfrontation> leseDatei(String dateipfad) throws Exception {
        if (dateipfad.endsWith(".json")) return leseJSON(dateipfad);
        if (dateipfad.endsWith(".tsv")) return leseTSV(dateipfad);
        if (dateipfad.endsWith(".xml")) return leseXML(dateipfad);
        throw new IllegalArgumentException("Formatul fișierului nu este acceptat!");
    }

    private static List<Konfrontation> leseJSON(String dateipfad) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readValue(new File(dateipfad), new TypeReference<List<Konfrontation>>() {});
    }

    private static List<Konfrontation> leseTSV(String dateipfad) throws IOException {
        List<Konfrontation> liste = new ArrayList<>();
        List<String> zeilen = Files.readAllLines(Paths.get(dateipfad));
        for (String zeile : zeilen.subList(1, zeilen.size())) {
            String[] teile = zeile.split("\t");
            liste.add(new Konfrontation(
                    Integer.parseInt(teile[0]), teile[1], teile[2],
                    Konfrontationstyp.valueOf(teile[3]), teile[4],
                    LocalDate.parse(teile[5]), Double.parseDouble(teile[6])
            ));
        }
        return liste;
    }

    private static List<Konfrontation> leseXML(String dateipfad) throws Exception {
        List<Konfrontation> liste = new ArrayList<>();
        Document doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(new File(dateipfad));
        NodeList nodes = doc.getElementsByTagName("log");

        for (int i = 0; i < nodes.getLength(); i++) {
            Element e = (Element) nodes.item(i);
            liste.add(new Konfrontation(
                    Integer.parseInt(e.getElementsByTagName("Id").item(0).getTextContent()),
                    e.getElementsByTagName("Held").item(0).getTextContent(),
                    e.getElementsByTagName("Antagonist").item(0).getTextContent(),
                    Konfrontationstyp.valueOf(e.getElementsByTagName("Konfrontationstyp").item(0).getTextContent()),
                    e.getElementsByTagName("Ort").item(0).getTextContent(),
                    LocalDate.parse(e.getElementsByTagName("Datum").item(0).getTextContent()),
                    Double.parseDouble(e.getElementsByTagName("GlobalerEinfluss").item(0).getTextContent())
            ));
        }
        return liste;
    }

    public static void main(String[] args) throws Exception {
        List<Konfrontation> daten = leseDatei("evenimente.json");
        System.out.println(daten);
    }
}

public static void filtereHelden(List<Konfrontation> daten, double minEinfluss) {
    daten.stream()
            .filter(k -> k.globalerEinfluss > minEinfluss)
            .map(k -> k.held)
            .distinct()
            .forEach(System.out::println);
}

public static void zeigeGalaktischeKonfrontationen(List<Konfrontation> daten) {
    daten.stream()
            .filter(k -> k.konfrontationstyp == Konfrontationstyp.Galaktisch)
            .sorted(Comparator.comparing(Konfrontation::getDatum).reversed())
            .forEach(k -> System.out.println(k.datum + ": " + k.held + " vs. " + k.antagonist + " - " + k.ort));
}

public static void speichereKonfrontationen(List<Konfrontation> daten, String dateiname) throws IOException {
    Map<Konfrontationstyp, Long> anzahl = daten.stream().collect(Collectors.groupingBy(k -> k.konfrontationstyp, Collectors.counting()));
    Map<Konfrontationstyp, Double> impact = daten.stream().collect(Collectors.groupingBy(k -> k.konfrontationstyp, Collectors.summingDouble(k -> k.globalerEinfluss)));

    List<String> ergebnisse = anzahl.entrySet().stream()
            .sorted(Comparator.<Map.Entry<Konfrontationstyp, Long>>comparingLong(Map.Entry::getValue).reversed()
                    .thenComparing(e -> impact.get(e.getKey())))
            .map(e -> e.getKey() + "&" + e.getValue() + "$" + impact.get(e.getKey()))
            .collect(Collectors.toList());

    Files.write(Paths.get(dateiname), ergebnisse);
}

class Produkt {
    String name, universum;
    double preis;
}

class Charakter {
    int id;
    String name, region;
    List<Produkt> gekaufteProdukte;
}

class ProduktController {
    List<Produkt> produkte = new ArrayList<>();

    void addProdukt(String name, double preis, String universum) {
        produkte.add(new Produkt(name, preis, universum));
    }

    void listProdukte() {
        produkte.forEach(p -> System.out.println(p.name + " - " + p.preis + " - " + p.universum));
    }
}

void filterCharaktereNachRegion(List<Charakter> charaktere, String region) {
    charaktere.stream().filter(c -> c.region.equals(region))
            .map(c -> c.name).forEach(System.out::println);
}

void sortiereProdukteEinesCharakters(List<Charakter> charaktere, String name, boolean absteigend) {
    charaktere.stream().filter(c -> c.name.equals(name)).findFirst()
            .ifPresent(c -> c.gekaufteProdukte.stream()
                    .sorted(Comparator.comparingDouble(p -> absteigend ? -p.preis : p.preis))
                    .forEach(p -> System.out.println(p.name + " - " + p.preis)));
}