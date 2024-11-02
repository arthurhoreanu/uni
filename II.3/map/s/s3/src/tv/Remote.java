package tv;

public class Remote {
    private final TV tv;

    public Remote(TV tv){
        this.tv = tv;
    }

    public Kanal channelUp(){
        if (tv.hasNext()) return tv.next();
        else return null;
    }

    public Kanal channelDown(){
        if (tv.hasPrevious()) return tv.previous();
        else return null;
    }
}
