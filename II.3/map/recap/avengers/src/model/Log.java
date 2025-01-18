package model;

public class Log {

    private int id;
    private String name;
    private Group group;
    private String task;
    private Difficulty difficulty;
    private int points;
    private String success;

    public Log(int id, String name, Group group, String task, Difficulty difficulty, int points, String success) {
        this.id = id;
        this.name = name;
        this.group = group;
        this.task = task;
        this.difficulty = difficulty;
        this.points = points;
        this.success = success;
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

    public Group getGroup() {
        return group;
    }

    public void setGroup(Group group) {
        this.group = group;
    }

    public String getTask() {
        return task;
    }

    public void setTask(String task) {
        this.task = task;
    }

    public Difficulty getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(Difficulty difficulty) {
        this.difficulty = difficulty;
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public String getSuccess() {
        return success;
    }

    public void setSuccess(String success) {
        this.success = success;
    }

    @Override
    public String toString() {
        return "Log{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", group=" + group +
                ", task='" + task + '\'' +
                ", difficulty=" + difficulty +
                ", points=" + points +
                ", success=" + success +
                '}';
    }
}
