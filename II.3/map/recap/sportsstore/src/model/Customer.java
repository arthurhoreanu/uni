package model;

import java.util.ArrayList;
import java.util.List;

public class Customer {

    private int id;
    private String name;
    private String place;
    private List<Product> products;

    public Customer(int id, String name, String place) {
        this.id = id;
        this.name = name;
        this.place = place;
        this.products = new ArrayList<>();
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

    public String getPlace() {
        return place;
    }

    public void setPlace(String place) {
        this.place = place;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", place='" + place + '\'' +
                ", products=" + products +
                '}';
    }
}
