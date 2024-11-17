package university.model;

/**
 * Represents a teacher in the university system.
 */
public class Teacher extends Person {

    /**
     * Constructs a new Teacher with the specified name and ID.
     *
     * @param name      The name of the teacher.
     * @param teacherId The unique identifier for the teacher.
     */
    public Teacher(String name, Integer teacherId) {
        super(teacherId, name);
    }

    /**
     * Returns a string representation of the Teacher object.
     *
     * @return A string representation of the Teacher.
     */
    @Override
    public String toString() {
        return "Teacher{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}