package org.example.university.repository;

import java.util.List;

import org.example.university.model.HasID;

public interface Repository <T extends HasID> {
    void create(T obj);
    T read(Integer id);
    void update(T obj);
    void delete(Integer id);
    List<T> getAll();
}
