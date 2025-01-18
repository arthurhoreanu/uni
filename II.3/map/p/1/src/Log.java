import java.time.LocalDate;
import java.util.Date;

public class Log {

    private int id;
    private String name;
    private House house;
    private String event;
    private LocalDate date;

    public Log(int id, String name, House house, String event, LocalDate date) {
        this.id = id;
        this.name = name;
        this.house = house;
        this.event = event;
        this.date = date;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public House getHouse() {
        return house;
    }

    public void setHouse(House house) {
        this.house = house;
    }

    public String getEvent() {
        return event;
    }

    public void setEvent(String event) {
        this.event = event;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return "Log{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", house=" + house +
                ", event='" + event + '\'' +
                ", date=" + date +
                '}';
    }
}
