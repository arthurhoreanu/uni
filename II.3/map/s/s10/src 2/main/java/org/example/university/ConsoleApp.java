package org.example.university;

import java.util.Scanner;
import java.util.stream.IntStream;

import org.example.university.model.Course;
import org.example.university.model.Student;
import org.example.university.model.Teacher;
import org.example.university.repository.CourseDBRepository;
import org.example.university.repository.InMemoryRepository;
import org.example.university.repository.Repository;
import org.example.university.repository.StudentDBRepository;

public class ConsoleApp {
    private final UniversityController universityController;

    /**
     * Constructs a new ConsoleApp with the given UniversityController.
     *
     * @param universityController
     *         The controller that handles the business logic for the university system.
     */
    public ConsoleApp(UniversityController universityController) {
        this.universityController = universityController;
    }

    /**
     * Starts the console application, displaying a menu and handling user input.
     */
    public void start() {
        Scanner scanner = new Scanner(System.in);
        boolean continueLoop = true;

        while (continueLoop) {
            System.out.print("""
                    Select an option:
                    
                    1. View students
                    2. View courses
                    3. View students enrolled in course
                    4. Delete course
                    5. Enroll student in a course
                    
                    0. Exit
                    """);

            String option = scanner.nextLine();

            switch (option) {
            case "0":
                continueLoop = false;
                break;
            case "1":
                universityController.getStudents();
                break;
            case "2":
                universityController.getCourses();
                break;
            case "3":
                universityController.getEnrolledStudents(readCourseId(scanner));
                break;
            case "4":
                universityController.removeCourse(readCourseId(scanner));
                break;
            case "5":
                universityController.enrollStudent(readStudentId(scanner), readCourseId(scanner));
                break;
            default:
            }
        }
    }

    /**
     * Reads a student ID from the user input.
     *
     * @param scanner
     *         The Scanner object used to read user input.
     * @return The student ID entered by the user.
     */
    private static int readStudentId(Scanner scanner) {
        System.out.println("Enter student ID: ");
        return Integer.parseInt(scanner.nextLine());
    }

    /**
     * Reads a course ID from the user input.
     *
     * @param scanner
     *         The Scanner object used to read user input.
     * @return The course ID entered by the user.
     */
    private static int readCourseId(Scanner scanner) {
        System.out.print("Enter course ID: ");
        return Integer.parseInt(scanner.nextLine());
    }

    public static void main(String[] args) {
        //        Repository<Course> courseRepo = createInMemoryCourseRepository();
        //        Repository<Student> studentRepo = createInMemoryStudentRepository();
        //        Repository<Course> courseRepo = new FileRepository<>("courses.db");
        //        Repository<Student> studentRepo = new FileRepository<>("students.db");

        String DB_URL = "jdbc:mysql://localhost:3306/db";
        String DB_USER = "user";
        String DB_PASSWORD = "password";

        Repository<Student> studentRepo = new StudentDBRepository(DB_URL, DB_USER, DB_PASSWORD);
        Repository<Course> courseRepo = new CourseDBRepository(DB_URL, DB_USER, DB_PASSWORD);

        UniversityService universityService = new UniversityService(studentRepo, courseRepo);
        UniversityController universityController = new UniversityController(universityService);

        ConsoleApp consoleApp = new ConsoleApp(universityController);
        consoleApp.start();
    }

    /**
     * Creates an in-memory repository for students and populates it with some initial data.
     *
     * @return The in-memory repository for students.
     */
    private static Repository<Student> createInMemoryStudentRepository() {
        Repository<Student> studentRepo = new InMemoryRepository<>();
        IntStream.range(1, 6).forEach(i -> studentRepo.create(new Student("Student" + i, i)));
        return studentRepo;
    }

    /**
     * Creates an in-memory repository for courses and populates it with some initial data.
     *
     * @return The in-memory repository for courses.
     */
    private static Repository<Course> createInMemoryCourseRepository() {
        Repository<Course> courseRepo = new InMemoryRepository<>();
        courseRepo.create(new Course(1, "Course1", new Teacher("Teacher1", 1), 25, 5));
        courseRepo.create(new Course(2, "Course2", new Teacher("Teacher1", 1), 35, 2));
        courseRepo.create(new Course(3, "Course3", new Teacher("Teacher2", 2), 35, 2));
        courseRepo.create(new Course(4, "Course4", new Teacher("Teacher2", 2), 15, 4));
        courseRepo.create(new Course(5, "Course5", new Teacher("Teacher2", 2), 65, 2));
        courseRepo.getAll().forEach(System.out::println);
        return courseRepo;
    }
}
