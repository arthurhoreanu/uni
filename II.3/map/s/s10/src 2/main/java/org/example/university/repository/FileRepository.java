package org.example.university.repository;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.List;
import java.util.Map;
import java.util.function.Consumer;

import org.example.university.model.HasID;

public class FileRepository<T extends HasID> implements Repository<T> {
    private final String path;

    public FileRepository(String path) {
        this.path = path;
    }

    public Map<Integer, T> readFromFile() {
        try (ObjectInputStream input = new ObjectInputStream(new FileInputStream(path))) {
            return (Map<Integer, T>) input.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return Map.of();
        }

    }

    public void writeToFile(Map<Integer, T> map) {
        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(path))) {
            output.writeObject(map);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    void doInFile(Consumer<Map<Integer, T>> consumer) {
        Map<Integer, T> integerTMap = readFromFile();
        consumer.accept(integerTMap);
        writeToFile(integerTMap);
    }

    @Override
    public void create(T obj) {
        doInFile(map -> map.putIfAbsent(obj.getID(), obj));
    }

    @Override
    public T read(Integer id) {
        return readFromFile().get(id);
    }

    @Override
    public void update(T obj) {
        doInFile(map -> map.replace(obj.getID(), obj));
    }

    @Override
    public void delete(Integer id) {
        doInFile(map -> map.remove(id));
    }

    @Override
    public List<T> getAll() {
        return readFromFile().values().stream().toList();
    }
}
