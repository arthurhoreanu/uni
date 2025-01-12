package model;

/**
 * An entry from the log file.
 */
public class Log {
    private int id;
    private String studentName;
    private House house;
    private String authority;
    private int points;

    public Log(int id, String studentName, House house, String authority, int points) {
        this.id = id;
        this.studentName = studentName;
        this.house = house;
        this.authority = authority;
        this.points = points;
    }

    public int getId() {
        return id;
    }

    public String getStudentName() {
        return studentName;
    }

    public House getHouse() {
        return house;
    }

    public String getAuthority() {
        return authority;
    }

    public int getPoints() {
        return points;
    }

    @Override
    public String toString() {
        return "LogEntry{" +
                "id=" + id +
                ", studentName='" + studentName + '\'' +
                ", house=" + house +
                ", authority='" + authority + '\'' +
                ", points=" + points +
                '}';
    }
}
