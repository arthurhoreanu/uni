package org.example.university;

import java.util.List;

import org.example.university.model.Course;
import org.example.university.model.Student;

public class UniversityController {

    private UniversityService service;

    UniversityController(UniversityService service) {
        this.service = service;
    }

    public void getStudents(){
        List<Student> students = service.getStudents();
        System.out.println(students);

    }

    public void getCourses(){
        List<Course> courses = service.getCourses();
        System.out.println(courses);
    }

    public void enrollStudent(Integer studentId, Integer courseId){
        service.enrollStudent(studentId, courseId);
        System.out.println("Student enrolled !!!");
    }


    public void getEnrolledStudents(Integer courseId){
        List<Student> students = service.getEnrolledStudents(courseId);
        System.out.println(students);
    }

    public void removeCourse(Integer courseId){
        service.removeCourse(courseId);
        System.out.println("Course removed !!!");
    }
}
