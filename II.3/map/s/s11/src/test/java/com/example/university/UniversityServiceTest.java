package com.example.university;

import java.util.List;

import com.example.university.model.Course;
import com.example.university.model.Student;
import com.example.university.model.Teacher;
import com.example.university.repository.CourseRepository;
import com.example.university.repository.StudentRepository;
import com.example.university.repository.TeacherRepository;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

@SpringBootTest
class UniversityServiceTest {

    @Autowired
    StudentRepository studentRepository;

    @Autowired
    CourseRepository courseRepository;

    @Autowired
    TeacherRepository teacherRepository;

    @Autowired
    UniversityService universityService;

    @BeforeEach
    public void setUp() {
        Student student1 = new Student(1, "Student1", List.of());
        studentRepository.save(student1);

        Teacher teacher1 = new Teacher(2, "Teacher1");
        teacherRepository.save(teacher1);

        Course course1 = new Course(1, 10, "Course1", 10, teacher1, List.of());
        courseRepository.save(course1);
    }

    @AfterEach
    public void destroy() {
        courseRepository.deleteAll();
        studentRepository.deleteAll();
        teacherRepository.deleteAll();
    }

    @Test
    void testGetAllStudents() {
        List<Student> students = universityService.getAllStudents();

        assertNotNull(students);
        assertEquals(1, students.size());
    }

    @Test
    void testGetAllCourses() {
        List<Course> courses = universityService.getAllCourses();

        assertNotNull(courses);
        assertEquals(1, courses.size());
    }

    @Test
    void removeCourse() {
        universityService.removeCourse(1);

        assertEquals(0, universityService.getAllCourses().size());
    }

    @Test
    void testEnrollStudent() {
        universityService.enrollStudent(1, 1);
        assertEquals(1, universityService.getAllStudents().size());
    }

    @Test
    void testGetEnrolledStudents() {
        universityService.enrollStudent(1, 1);
        List<Student> students = universityService.getEnrolledStudents(1);

        assertNotNull(students);
    }
}
