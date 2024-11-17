package university;

import java.util.List;

import university.model.Course;
import university.model.Student;
import university.repository.Repository;

/**
 * A service class that provides the business logic for the university system.
 */
public class UniversityService {

    protected static final int CREDIT_LIMIT = 10;

    private final Repository<Course> courseRepo;

    private final Repository<Student> studentRepo;

    /**
     * Constructs a new UniversityService with the given repositories.
     *
     * @param courseRepo
     *         The repository for courses.
     * @param studentRepo
     *         The repository for students.
     */
    public UniversityService(Repository<Course> courseRepo, Repository<Student> studentRepo) {
        this.courseRepo = courseRepo;
        this.studentRepo = studentRepo;
    }

    /**
     * Enrolls a student in a course if the course has available slots and the student's credit limit is not exceeded.
     *
     * @param studentId
     *         The unique identifier of the student.
     * @param courseId
     *         The unique identifier of the course.
     */
    public void enroll(Integer studentId, Integer courseId) {
        Student student = studentRepo.get(studentId);
        Course course = courseRepo.get(courseId);
        if (course.getAvailableSlots() > course.getEnrolledStudents().size()
                && student.getEnrolledCredits() + course.getCredits() <= CREDIT_LIMIT) {
            course.getEnrolledStudents().add(student);
            student.getCourses().add(course);
            courseRepo.update(course);
            studentRepo.update(student);
        }
    }

    /**
     * Retrieves all available courses.
     *
     * @return A list of all available courses.
     */
    public List<Course> getAvailableCourses() {
        return courseRepo.getAll();
    }

    /**
     * Retrieves all students enrolled in a specific course.
     *
     * @param courseId
     *         The unique identifier of the course.
     * @return A list of students enrolled in the course.
     */
    public List<Student> getEnrolledStudents(Integer courseId) {
        Course course = courseRepo.get(courseId);
        return course.getEnrolledStudents();
    }

    /**
     * Removes a course from the system and unenrolls all students from the course.
     *
     * @param courseId
     *         The unique identifier of the course to remove.
     */
    public void removeCourse(Integer courseId) {
        courseRepo.get(courseId).getEnrolledStudents().forEach(student -> {
            student.getCourses().removeIf(course -> course.getId().equals(courseId));
            studentRepo.update(student);
        });
        courseRepo.delete(courseId);
    }

    /**
     * Retrieves all students in the system.
     *
     * @return A list of all students.
     */
    public List<Student> getAllStudents() {
        return studentRepo.getAll();
    }
}