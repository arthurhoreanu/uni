package karte;

import javax.smartcardio.Card;
import java.util.Iterator;
import java.util.List;

public class Deck implements Iterable<Card> {
    @Override
    public Iterator<Card> iterator() {
        return null;
    }

    public static class KartenIterator implements Iterator<Karte> {

        private List<Karte> karten;

        public Deck(List<Karte> karten){
            this.karten = karten;
        }

        @Override
        public Iterator<Karte>  iterator(){
            return new KartenIterator(karten);
        }

        private List<Karte> karten;>
        private int index = 0;

        public KartenIterator(List<Karte> karten) {
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
