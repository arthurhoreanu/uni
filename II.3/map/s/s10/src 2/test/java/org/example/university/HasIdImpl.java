package org.example.university;

import org.example.university.model.HasID;

public class HasIdImpl implements HasID {
    Integer id;

    public HasIdImpl(Integer id) {
        this.id = id;
    }

    public Integer getID() {
        return id;
    }
}
