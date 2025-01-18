package model;

import java.util.ArrayList;
import java.util.List;

public class Customer {

    private int id;
    private String name;
    private List<Film> films = new ArrayList<>();

    public Customer(int id, String name) {
        this.id = id;
        this.name = name;
        this.films = films;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Film> getFilms() {
        return films;
    }

    public void setFilms(List<Film> films) {
        this.films = films;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", films=" + films +
                '}';
    }
}
