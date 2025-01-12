package org.example.university;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

import org.example.university.model.Course;
import org.example.university.model.Student;
import org.example.university.repository.Repository;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
class UniversityServiceTest {
    @Mock
    private Repository<Course> courseRepository;

    @Mock
    private Repository<Student> studentRepository;

    private UniversityService universityService;

    @BeforeEach
    void setUp() {
        universityService = new UniversityService(studentRepository, courseRepository);
    }

    @Test
    void testEnrollStudent() {
        Course course = mock(Course.class);
        when(course.getEnrolledStudents()).thenReturn(new ArrayList<>());
        when(course.getAvailableSlots()).thenReturn(1);
        when(courseRepository.read(1)).thenReturn(course);

        Student student = mock(Student.class);
        when(student.getCourses()).thenReturn(new ArrayList<>());
        when(studentRepository.read(1)).thenReturn(student);

        universityService.enrollStudent(1, 1);

        verify(studentRepository).update(student);
        verify(courseRepository).update(course);
        verifyNoMoreInteractions(studentRepository, courseRepository);
    }

    @Test
    void testEnrollStudentNoMorePlaces() {
        Course course = mock(Course.class);
        when(course.getEnrolledStudents()).thenReturn(new ArrayList<>());
        when(course.getAvailableSlots()).thenReturn(0);
        when(courseRepository.read(1)).thenReturn(course);

        Student student = mock(Student.class);
        when(studentRepository.read(1)).thenReturn(student);

        universityService.enrollStudent(1, 1);

        verifyNoMoreInteractions(studentRepository, courseRepository);
    }

    @Test
    void testEnrollStudentTooManyCredits(){
        Course course = mock(Course.class);
        when(course.getEnrolledStudents()).thenReturn(new ArrayList<>());
        when(course.getAvailableSlots()).thenReturn(1);
        when(courseRepository.read(1)).thenReturn(course);

        Student student = mock(Student.class);
        List<Course> courses = IntStream.range(0, 4).mapToObj(i -> {
            Course course1 = mock(Course.class);
            when(course1.getCredits()).thenReturn(4);
            return course1;
        }).toList();
        when(student.getCourses()).thenReturn(courses);
        when(studentRepository.read(1)).thenReturn(student);

        universityService.enrollStudent(1, 1);

        verifyNoMoreInteractions(studentRepository, courseRepository);
    }

    @Test
    void getEnrolledStudents() {
        Course course = mock(Course.class);
        List<Student> students = IntStream.range(0, 5).mapToObj(i -> mock(Student.class)).toList();
        when(course.getEnrolledStudents()).thenReturn(students);
        when(courseRepository.read(1)).thenReturn(course);

        List<Student> enrolledStudents = universityService.getEnrolledStudents(1);

        verify(courseRepository).read(1);
        verifyNoMoreInteractions(courseRepository);
        verifyNoInteractions(studentRepository);

        assertThat(enrolledStudents).containsExactlyInAnyOrderElementsOf(students);
    }

    @Test
    void getStudents() {
        List<Student> students = mock(List.class);
        when(studentRepository.getAll()).thenReturn(students);

        List<Student> studentList = universityService.getStudents();

        verify(studentRepository).getAll();
        verifyNoMoreInteractions(studentRepository);
        verifyNoInteractions(courseRepository);

        assertThat(studentList).isEqualTo(students);
    }

    @Test
    void getCourses() {
        List<Course> courses = mock(List.class);
        when(courseRepository.getAll()).thenReturn(courses);

        List<Course> courseList = universityService.getCourses();

        verify(courseRepository).getAll();
        verifyNoMoreInteractions(courseRepository);
        verifyNoInteractions(studentRepository);
        assertThat(courseList).isEqualTo(courses);
    }

    @Test
    void removeCourse() {
        Course course = mock(Course.class);
        List<Student> students = IntStream.range(0, 5).mapToObj(i -> mock(Student.class)).toList();
        when(course.getEnrolledStudents()).thenReturn(students);
        when(courseRepository.read(1)).thenReturn(course);

        universityService.removeCourse(1);
        students.forEach(student -> verify(studentRepository).update(student));
        verify(courseRepository).delete(1);
        verifyNoMoreInteractions(courseRepository,studentRepository);
    }
}