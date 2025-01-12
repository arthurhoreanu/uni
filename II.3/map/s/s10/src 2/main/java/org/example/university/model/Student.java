package org.example.university.model;
import java.util.ArrayList;
import java.util.List;

public class Student extends Person {
    List<Course> courses = new ArrayList<>();

    public Student(String name, Integer ID) {
        super(ID, name);
    }

    public List<Course> getCourses() {
         return courses;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
//                ", courses=" + courses +
                ", ID=" + ID +
                '}';
    }
}
