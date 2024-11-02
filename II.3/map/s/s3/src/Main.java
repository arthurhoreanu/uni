import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import enum_karte.Farbe;
import enum_karte.Wert;
import enum_karte.Deck;
import enum_karte.Karte;
import tv.Kanal;
import tv.Remote;
import tv.SmartTV;
import tv.TV;

public class Main {
    public static void main(String[] args) {
        kartenOhneEnum();
        kartenMitEnum();
        tvKanale();
    }

    private static void kartenOhneEnum() {
        List<Karte> karten = Stream.of("Pik", "Kreuz", "Herz", "Karo")
                .flatMap(farbe -> IntStream.range(1, 14)
                        .mapToObj(wert -> new Karte(farbe, wert))).toList();

        //        List<String> farben = List.of("Pik", "Kreuz", "Herz", "Karo");
        //        List<Integer> werten = List.of(1,2,3,4,5,6,7,8,9,10,11,12,13);
        //
        //        List<Karte> karten2 = new ArrayList<>();
        //
        //        for(String farbe: farben){
        //            for(int wert: werten){
        //                karten2.add(new Karte(farbe,wert));
        //            }
        //        }

        Deck deck = new Deck(karten);

        System.out.println("Karten");

        for (Karte karte : deck) {
            printKarte(karte);
        }

        //        Iterator<Karte> iterator = deck.iterator();
        //
        //        while (iterator.hasNext()){
        //            printKarte(iterator.next());
        //        }
    }

    public static void kartenMitEnum() {
        List<enum_karte.Karte> karten = Arrays.stream(Farbe.values())
                .flatMap(farbe -> Arrays.stream(Wert.values())
                        .map(wert -> new enum_karte.Karte(farbe, wert))).toList();

        enum_karte.Deck deck = new enum_karte.Deck(karten);

        System.out.println("Karten mit Enum");

        for (enum_karte.Karte karte : deck) {
            System.out.println(karte);
        }
    }

    private static void printKarte(Karte iterator) {
        System.out.println(iterator);
    }

    public static void tvKanale() {
        List<Kanal> kanale = Stream.of("Kanal D", "Antena 1", "Pro TV").map(Kanal::new).toList();

        TV tv = new TV(kanale);
        Remote remote = new Remote(tv);

        System.out.println("Remote");
        changeChannels(remote);

        SmartTV smartTV = new SmartTV(kanale);
        Remote smartRemote = new Remote(smartTV);

        System.out.println("Smart Remote");
        changeChannels(smartRemote);

        System.out.println("TV channels");
        changeTVChannels(tv, remote);

        TV tv2 = new TV(kanale);

        System.out.println("Iteration up");

        while (tv2.hasNext()) {
            System.out.println(tv2.next());
        }

        System.out.println("Iteration down");

        while (tv2.hasPrevious()) {
            System.out.println(tv2.previous());
        }

    }

    private static void changeChannels(Remote remote) {
        System.out.println(remote.channelUp());
        System.out.println(remote.channelDown());
        System.out.println(remote.channelDown());
    }

    public static void changeTVChannels(TV tv, Remote remote) {

        System.out.println(tv.getChannel());
        remote.channelUp();
        System.out.println(tv.getChannel());
        remote.channelDown();
        System.out.println(tv.getChannel());
        remote.channelDown();
        System.out.println(tv.getChannel());

    }

}