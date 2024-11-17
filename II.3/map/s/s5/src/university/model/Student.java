package university.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Represents a student in the university system.
 */
public class Student extends Person {
    private final List<Course> courses = new ArrayList<>();

    /**
     * Constructs a new Student with the specified name and ID.
     *
     * @param name     The name of the student.
     * @param studentId The unique identifier for the student.
     */
    public Student(String name, Integer studentId) {
        super(studentId, name);
    }

    /**
     * Gets the total number of credits the student is currently enrolled in.
     *
     * @return The total number of credits.
     */
    public Integer getEnrolledCredits() {
        return getCourses().stream().mapToInt(Course::getCredits).sum();
    }

    /**
     * Gets the list of courses the student is enrolled in.
     *
     * @return The list of courses.
     */
    public List<Course> getCourses() {
        return courses;
    }

    /**
     * Returns a string representation of the Student object.
     *
     * @return A string representation of the Student.
     */
    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}