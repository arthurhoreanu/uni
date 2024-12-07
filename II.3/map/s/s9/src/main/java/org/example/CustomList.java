package org.example;

import java.util.ArrayList;
import java.util.List;

public class CustomList<T> {
    private final List<T> list = new ArrayList<>();

    public void add(T element) {
        list.add(element);
    }

    public T get(int index) {
        if (index < 0 || index >= list.size()) {
            throw new IndexOutOfBoundsException("Index out of range");
        }
        return list.get(index);
    }

    public int size() {
        return list.size();
    }
}