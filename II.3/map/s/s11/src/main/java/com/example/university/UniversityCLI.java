package com.example.university;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.shell.standard.ShellComponent;
import org.springframework.shell.standard.ShellMethod;
import org.springframework.shell.standard.ShellOption;

@ShellComponent
public class UniversityCLI {

    @Autowired
    private UniversityService universityService;

    @ShellMethod(key = "students get", value = "Lists all students")
    public String getAllStudents() {
        return universityService.getAllStudents().toString();
    }

    @ShellMethod(key = "courses get", value = "Lists all courses")
    public String getAllCourses() {
        return universityService.getAllCourses().toString();
    }

    @ShellMethod(key = "courses students get", value = "Lists all students enrolled in the course")
    public String getEnrolledStudents(
            @ShellOption(value = "courseId", help = "The id of the course") Integer courseId
    ) {
        return universityService.getEnrolledStudents(courseId).toString();
    }

    @ShellMethod(key = "courses remove", value = "Removes a course")
    public String removeCourse(
            @ShellOption(value = "courseId", help = "The id of the course") Integer courseId
    ) {
        universityService.removeCourse(courseId);
        return "Course removed";
    }

    @ShellMethod(key = "courses students add", value = "Enrolls a student into a course")
    public String enrollStudent(
            @ShellOption(value = "courseId", help = "The id of the course") Integer courseId,
            @ShellOption(value = "studentId", help = "The id of the student") Integer studentId
    ) {
        universityService.enrollStudent(courseId, studentId);
        return "Student enrolled";
    }
}
