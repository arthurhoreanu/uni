package log.model;

public class Message {
    private String file;

    private String text;

    public String getFile() {
        return file;
    }

    public void setFile(String file) {
        this.file = file;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    @Override
    public String toString() {
        return "log.model.Message{" +
                "file='" + file + '\'' +
                ", text='" + text + '\'' +
                '}';
    }
}

