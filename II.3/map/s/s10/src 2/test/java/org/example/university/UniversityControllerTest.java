package org.example.university;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.verifyNoMoreInteractions;

@ExtendWith(MockitoExtension.class)
class UniversityControllerTest {

    @Mock
    private UniversityService universityService;

    @InjectMocks
    private UniversityController universityController;

    @Test
    void testGetStudents(){
        universityController.getStudents();
        verify(universityService).getStudents();
        verifyNoMoreInteractions(universityService);
    }

    @Test
    void testGetCourses() {
        universityController.getCourses();
        verify(universityService).getCourses();
        verifyNoMoreInteractions(universityService);
    }

    @Test
    void testGetEnrolledStudent() {
        Integer Id = 1;
        universityController.getEnrolledStudents(1);
        verify(universityService).getEnrolledStudents(Id);
        verifyNoMoreInteractions(universityService);
    }

    @Test
    void testEnrollStudent() {
        Integer studentId = 1;
        Integer courseId = 2;
        universityController.enrollStudent(studentId, courseId);
        verify(universityService).enrollStudent(studentId, courseId);
        verifyNoMoreInteractions(universityService);
    }

    @Test
    void testRemoveCourse() {
        Integer courseId = 1;
        universityController.removeCourse(courseId);
        verify(universityService).removeCourse(courseId);
        verifyNoMoreInteractions(universityService);
    }
}

