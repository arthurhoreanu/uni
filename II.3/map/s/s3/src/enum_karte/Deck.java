package enum_karte;

import java.util.Iterator;
import java.util.List;

public class Deck implements Iterable<Karte> {

    private final List<Karte> karten;

    public Deck(List<Karte> karten){
        this.karten = karten;
    }

    @Override
    public Iterator<Karte> iterator() {
        return new KartenIterator(karten);
    }

    public static class KartenIterator implements Iterator<Karte>{

        private final List<Karte> karten;
        private int index = 0;

        public KartenIterator(List<Karte> karten){
            this.karten = karten;
        }

        @Override
        public boolean hasNext() {
            return karten.size() > index;
        }

        @Override
        public Karte next() {
            return karten.get(index++);
        }
    }
}
