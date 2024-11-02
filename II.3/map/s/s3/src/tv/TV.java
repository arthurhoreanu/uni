package tv;

import java.util.List;
import java.util.ListIterator;

public class TV implements ListIterator<Kanal> {
    protected List<Kanal> kanale;
    protected int index;
    public TV(List<Kanal> kanale){
        this.kanale = kanale;
        this.index = 0;
    }

    public Kanal getChannel(){
        return kanale.get(index);
    }

    @Override
    public boolean hasNext() {
        return this.kanale.size() > this.index;
    }

    @Override
    public Kanal next() {
        return kanale.get(index++);
    }

    @Override
    public boolean hasPrevious() {
        return this.index > 0;
    }

    @Override
    public Kanal previous() {
        return kanale.get(--index);
    }

    @Override
    public int nextIndex() {
        return index;
    }

    @Override
    public int previousIndex() {
        return index - 1;
    }

    @Override
    public void remove() {
        this.kanale.remove(index);
    }

    @Override
    public void set(Kanal kanal) {
        this.kanale.set(index, kanal);
    }

    @Override
    public void add(Kanal kanal) {
        this.kanale.add(index, kanal);
    }
}
