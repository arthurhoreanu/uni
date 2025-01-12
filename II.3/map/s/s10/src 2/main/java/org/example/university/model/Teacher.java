package org.example.university.model;

public class Teacher extends Person {

    public Teacher(String name, Integer ID) {
        super(ID, name);
    }

    @Override
    public String toString() {
        return "Teacher{" +
                "ID=" + ID +
                ", name='" + name + '\'' +
                '}';
    }
}
