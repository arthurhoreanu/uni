package university.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Represents a course in the university system.
 */
public class Course implements HasId {

    private Integer id;
    private String courseName;
    private Teacher teacher;
    private List<Student> enrolledStudents;
    private Integer availableSlots;
    private Integer credits;

    /**
     * Constructs a new Course with the specified details.
     *
     * @param id           The unique identifier for the course.
     * @param courseName   The name of the course.
     * @param teacher      The teacher responsible for the course.
     * @param maxStudents  The maximum number of students that can enroll in the course.
     * @param credits      The number of credits for the course.
     */
    public Course(Integer id, String courseName, Teacher teacher, Integer maxStudents, Integer credits) {
        this.id = id;
        this.courseName = courseName;
        this.teacher = teacher;
        this.credits = credits;
        this.availableSlots = maxStudents;
        this.enrolledStudents = new ArrayList<>();
    }

    /**
     * Sets the unique identifier for the course.
     *
     * @param id The unique identifier to set.
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * Gets the name of the course.
     *
     * @return The name of the course.
     */
    public String getCourseName() {
        return courseName;
    }

    /**
     * Sets the name of the course.
     *
     * @param courseName The name of the course to set.
     */
    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    /**
     * Gets the teacher responsible for the course.
     *
     * @return The teacher responsible for the course.
     */
    public Teacher getTeacher() {
        return teacher;
    }

    /**
     * Sets the teacher responsible for the course.
     *
     * @param teacher The teacher to set.
     */
    public void setTeacher(Teacher teacher) {
        this.teacher = teacher;
    }

    /**
     * Gets the list of students currently enrolled in the course.
     *
     * @return The list of enrolled students.
     */
    public List<Student> getEnrolledStudents() {
        return enrolledStudents;
    }

    /**
     * Sets the list of students currently enrolled in the course.
     *
     * @param enrolledStudents The list of enrolled students to set.
     */
    public void setEnrolledStudents(List<Student> enrolledStudents) {
        this.enrolledStudents = enrolledStudents;
    }

    /**
     * Gets the number of available slots for the course.
     *
     * @return The number of available slots.
     */
    public Integer getAvailableSlots() {
        return availableSlots;
    }

    /**
     * Sets the number of available slots for the course.
     *
     * @param availableSlots The number of available slots to set.
     */
    public void setAvailableSlots(Integer availableSlots) {
        this.availableSlots = availableSlots;
    }

    /**
     * Gets the number of credits for the course.
     *
     * @return The number of credits.
     */
    public Integer getCredits() {
        return credits;
    }

    /**
     * Sets the number of credits for the course.
     *
     * @param credits The number of credits to set.
     */
    public void setCredits(Integer credits) {
        this.credits = credits;
    }

    /**
     * Returns a string representation of the Course object.
     *
     * @return A string representation of the Course.
     */
    @Override
    public String toString() {
        return "Course{" +
                "id=" + id +
                ", courseName='" + courseName + '\'' +
                ", teacher=" + teacher +
                ", availableSlots=" + availableSlots +
                ", credits=" + credits +
                '}';
    }

    /**
     * Gets the unique identifier for the course.
     *
     * @return The unique identifier.
     */
    @Override
    public Integer getId() {
        return id;
    }
}