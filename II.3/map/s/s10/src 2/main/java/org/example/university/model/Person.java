package org.example.university.model;

public abstract class Person implements HasID {
    protected Integer ID;
    protected String name;
    protected Person(Integer ID, String name) {
        this.ID = ID;
        this.name = name;
    }
    public Integer getID() {
        return ID;
    }
    public String getName() {
        return name;
    }
    public void setID(Integer ID) {
        this.ID = ID;
    }
    public void setName(String name) {
        this.name = name;
    }


}
