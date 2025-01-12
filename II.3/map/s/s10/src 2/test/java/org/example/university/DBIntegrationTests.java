package org.example.university;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import org.assertj.core.data.MapEntry;
import org.example.university.model.Course;
import org.example.university.model.Student;
import org.example.university.repository.CourseDBRepository;
import org.example.university.repository.StudentDBRepository;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.ArgumentCaptor;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
public class DBIntegrationTests {
    private static final String URL = "jdbc:h2:mem:testdb;DB_CLOSE_DELAY=-1";

    private static final String USER = "sa";

    private static final String PASSWORD = "";

    private static Connection testConnection;

    @BeforeAll
    public static void init() throws SQLException {
        testConnection = DriverManager.getConnection(URL, USER, PASSWORD);
        testConnection.prepareStatement("""
                create table IF NOT EXISTS Course
                (
                    ID             int         null,
                    availableSlots int         null,
                    credits        int         null,
                    courseName     varchar(50) null,
                    teacherID      int         null
                );
                
                create table IF NOT EXISTS Student
                (
                    ID   int         null,
                    name varchar(50) null
                );
                
                create table IF NOT EXISTS StudentCourse
                (
                    studentID int null,
                    courseID  int null
                );
                
                create table IF NOT EXISTS Teacher
                (
                    ID   int         null,
                    name varchar(50) null
                );
                """).execute();
    }

    @AfterAll
    public static void tearDown() throws SQLException {
        testConnection.close();
    }

    @BeforeEach
    public void setUp() throws SQLException {
        testConnection.prepareStatement("""
                insert into Student(ID, name) 
                VALUES
                    (1,'Student1'),
                    (2,'Student2'),
                    (3,'Student3');
                
                insert into Teacher(ID,name) 
                VALUES
                    (1,'Teacher1'),
                    (2,'Teacher2'),
                    (3,'Teacher3');
                
                insert into Course(ID, availableSlots, credits, courseName, teacherID)
                VALUES
                    (1,10,5,'Course1',1),
                    (2,5,3,'Course2',2),
                    (3,10,4,'Course3',3),
                    (4,10,5,'Course4',1),
                    (5,10,6,'Course5',2);
                
                insert into StudentCourse(studentID, courseID)
                VALUES
                    (1,1),
                    (1,2),
                    (2,3),
                    (2,2),
                    (3,5);
                """).execute();
    }

    @AfterEach
    public void destroy() throws SQLException {
        testConnection.prepareStatement("""
                delete from Student;
                delete from Course;
                delete from Teacher;
                delete from StudentCourse;
                """).execute();
    }

    private final StudentDBRepository studentDBRepo = spy(new StudentDBRepository(URL, USER, PASSWORD));

    private final CourseDBRepository courseDBRepo = spy(new CourseDBRepository(URL, USER, PASSWORD));

    private final UniversityService service = spy(new UniversityService(studentDBRepo, courseDBRepo));

    private final UniversityController controller = new UniversityController(service);

    @Test
    void enrollStudent() throws SQLException {
        int studentId = 3;
        int courseId = 3;
        controller.enrollStudent(studentId, courseId);

        ResultSet studentCoursesResult = testConnection.prepareStatement("select * from StudentCourse where studentID = 3")
                .executeQuery();
        assertThat(studentCoursesResult.next()).isTrue();
        List<MapEntry<Integer,Integer>> studentCourses = new ArrayList<>();
        studentCourses.add(MapEntry.entry(studentCoursesResult.getInt("studentID"), studentCoursesResult.getInt("courseID")));
        assertThat(studentCoursesResult.next()).isTrue();
        studentCourses.add(MapEntry.entry(studentCoursesResult.getInt("studentID"), studentCoursesResult.getInt("courseID")));
        assertThat(studentCoursesResult.next()).isFalse();

        assertThat(studentCourses)
                .hasSize(2)
                .anySatisfy(entry->{
                    assertThat(entry.getKey()).isEqualTo(studentId);
                    assertThat(entry.getValue()).isEqualTo(courseId);
                })
                .anySatisfy(entry->{
                    assertThat(entry.getKey()).isEqualTo(studentId);
                    assertThat(entry.getValue()).isEqualTo(5);
                });

        verify(service).enrollStudent(studentId, courseId);

        verify(studentDBRepo).read(studentId);
        verify(courseDBRepo).read(courseId);

        ArgumentCaptor<Student> studentCaptor = ArgumentCaptor.forClass(Student.class);
        ArgumentCaptor<Course> courseCaptor = ArgumentCaptor.forClass(Course.class);

        verify(studentDBRepo).update(studentCaptor.capture());
        verify(courseDBRepo).update(courseCaptor.capture());

        assertThat(studentCaptor.getValue().getID()).isEqualTo(studentId);
        assertThat(studentCaptor.getValue().getCourses())
                .anySatisfy(course->assertThat(course.getID()).isEqualTo(courseId))
                .anySatisfy(course->assertThat(course.getID()).isEqualTo(5));

        assertThat(courseCaptor.getValue().getID()).isEqualTo(courseId);
        assertThat(courseCaptor.getValue().getEnrolledStudents()).contains(studentCaptor.getValue());
    }

}
