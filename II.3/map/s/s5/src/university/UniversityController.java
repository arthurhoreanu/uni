package university;

/**
 * A controller class that handles the business logic for the university system.
 */
public class UniversityController {
    private final UniversityService universityService;

    /**
     * Constructs a new UniversityController with the given UniversityService.
     *
     * @param universityService The service that provides the business logic for the university system.
     */
    public UniversityController(UniversityService universityService) {
        this.universityService = universityService;
    }

    /**
     * Enrolls a student in a course.
     *
     * @param studentId The unique identifier of the student.
     * @param courseId  The unique identifier of the course.
     */
    public void enrollStudent(Integer studentId, Integer courseId) {
        universityService.enroll(studentId, courseId);
        System.out.println("Enrolled student " + studentId + " with course " + courseId);
    }

    /**
     * Displays all available courses.
     */
    public void viewCourses() {
        StringBuilder output = new StringBuilder("Available courses:\n");
        universityService.getAvailableCourses().forEach(course -> output.append(course.toString()).append("\n"));
        System.out.println(output);
    }

    /**
     * Displays all available students.
     */
    public void viewStudents() {
        StringBuilder output = new StringBuilder("Available students:\n");
        universityService.getAllStudents().forEach(student -> output.append(student.toString()).append("\n"));
        System.out.println(output);
    }

    /**
     * Displays all students enrolled in a specific course.
     *
     * @param courseId The unique identifier of the course.
     */
    public void viewEnrolled(Integer courseId) {
        StringBuilder output = new StringBuilder("Enrolled students in the course:\n");
        universityService.getEnrolledStudents(courseId).forEach(student -> output.append(student.toString()).append("\n"));
        System.out.println(output);
    }

    /**
     * Deletes a course from the system.
     *
     * @param courseId The unique identifier of the course to delete.
     */
    public void deleteCourse(Integer courseId) {
        universityService.removeCourse(courseId);
        System.out.println("Removed course " + courseId);
    }
}