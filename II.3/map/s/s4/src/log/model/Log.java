package log.model;

import java.time.LocalDateTime;
import java.util.List;

public class Log implements Comparable<Log> {
    private LocalDateTime timestamp;

    private List<Visibility> visibility;

    private Message message;

    private Severity severity;

    public LocalDateTime getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public List<Visibility> getVisibility() {
        return visibility;
    }

    public void setVisibility(List<Visibility> visibility) {
        this.visibility = visibility;
    }

    public Message getMessage() {
        return message;
    }

    public void setMessage(Message message) {
        this.message = message;
    }

    public Severity getSeverity() {
        return severity;
    }

    public void setSeverity(Severity severity) {
        this.severity = severity;
    }

    @Override
    public String toString() {
        return "log.model.Log{" +
                "timestamp=" + timestamp +
                ", Visibility=" + visibility +
                ", message=" + message +
                ", severity=" + severity +
                '}';
    }

    @Override
    public int compareTo(Log o) {
        return this.getSeverity().compareTo(o.getSeverity());
    }
}

