package org.example.university.repository;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.example.university.model.HasID;

public class InMemoryRepository<T extends HasID> implements Repository<T> {
    Map<Integer,T> map = new HashMap<>();
    @Override
    public void create(T obj) {
        map.putIfAbsent(obj.getID(), obj);

    }

    @Override
    public T read(Integer id) {
        return map.get(id);
    }

    @Override
    public void update(T obj) {
        map.replace(obj.getID(), obj);
    }

    @Override
    public void delete(Integer id) {
        map.remove(id);

    }

    @Override
    public List<T> getAll() {
        return map.values().stream().toList();
    }
}
