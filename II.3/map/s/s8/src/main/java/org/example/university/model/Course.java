package org.example.university.model;

import java.util.ArrayList;
import java.util.List;

public class Course implements HasID {
    private Integer ID, availableSlots, credits;
    private String courseName;
    private Teacher teacher;
    private List<Student> enrolledStudents;

    public Course(Integer ID, String courseName, Teacher teacher, Integer availableSlots, Integer credits) {
        this.ID = ID;
        this.availableSlots = availableSlots;
        this.credits = credits;
        this.courseName = courseName;
        this.teacher = teacher;
        this.enrolledStudents = new ArrayList<>();
    }

    @Override
    public Integer getID() {
        return ID;
    }

    public void setID(Integer ID) {
        this.ID = ID;
    }

    public Integer getAvailableSlots() {
        return availableSlots;
    }

    public void setAvailableSlots(Integer availableSlots) {
        this.availableSlots = availableSlots;
    }

    public Integer getCredits() {
        return credits;
    }

    public void setCredits(Integer credits) {
        this.credits = credits;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public Teacher getTeacher() {
        return teacher;
    }

    public void setTeacher(Teacher teacher) {
        this.teacher = teacher;
    }

    public List<Student> getEnrolledStudents() {
        return enrolledStudents;
    }

    public void setEnrolledStudents(List<Student> enrolledStudents) {
        this.enrolledStudents = enrolledStudents;
    }

    @Override
    public String toString() {
        return "Course{" +
                "ID=" + ID +
                ", availableSlots=" + availableSlots +
                ", credits=" + credits +
                ", courseName='" + courseName + '\'' +
                ", teacher=" + teacher +
//                ", enrolledStudents=" + enrolledStudents +
                '}';
    }
}
