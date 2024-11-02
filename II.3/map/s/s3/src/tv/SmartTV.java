package tv;

import java.util.List;
import java.util.ListIterator;

public class SmartTV extends TV implements ListIterator<Kanal> {

    private final ListIterator<Kanal> kanalListIterator;

    public SmartTV(List<Kanal> kanale) {
        super(kanale);
        this.kanalListIterator = kanale.listIterator();
    }

    @Override
    public boolean hasNext() {
        return this.kanalListIterator.hasNext();
    }

    @Override
    public Kanal next() {
        return this.kanalListIterator.next();
    }

    @Override
    public boolean hasPrevious() {
        return this.kanalListIterator.hasPrevious();
    }

    @Override
    public Kanal previous() {
        return this.kanalListIterator.previous();
    }

    @Override
    public int nextIndex() {
        return this.kanalListIterator.nextIndex();
    }

    @Override
    public int previousIndex() {
        return this.kanalListIterator.previousIndex();
    }

    @Override
    public void remove() {
        this.kanalListIterator.remove();
    }

    @Override
    public void set(Kanal kanal) {
        this.kanalListIterator.set(kanal);
    }

    @Override
    public void add(Kanal kanal) {
        this.kanalListIterator.add(kanal);
    }
}
