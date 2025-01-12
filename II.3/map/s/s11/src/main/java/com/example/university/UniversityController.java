package com.example.university;

import java.util.List;

import com.example.university.model.Course;
import com.example.university.model.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class UniversityController {

    @Autowired
    UniversityService universityService;

    @GetMapping("/students")
    public List<Student> getStudents() {
        return universityService.getAllStudents();
    }

    @GetMapping("/courses")
    public List<Course> getCourses() {
        return universityService.getAllCourses();
    }

    @DeleteMapping("/courses/{clientId}")
    public void deleteCourse(@PathVariable Integer clientId) {
        universityService.removeCourse(clientId);
    }

    @GetMapping("/courses/{courseId}/students")
    public List<Student> getStudentsByCourse(@PathVariable Integer courseId) {
        return universityService.getEnrolledStudents(courseId);
    }

    @PostMapping("/courses/enroll")
    public void enrollStudent(@RequestParam Integer courseId, @RequestParam Integer studentId) {
        universityService.enrollStudent(courseId, studentId);
    }
}
