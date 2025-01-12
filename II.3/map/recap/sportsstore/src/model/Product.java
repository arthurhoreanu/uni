package model;

/**
 * A product from the sports store.
 */
public class Product {

    private String name;
    private double price;
    private String season;

    public Product(String name, double price, String season) {
        this.name = name;
        this.price = price;
        this.season = season;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getSeason() {
        return season;
    }

    public void setSeason(String season) {
        this.season = season;
    }

    @Override
    public String toString() {
        return "Product{" +
                "name='" + name + '\'' +
                ", price=" + price +
                ", season='" + season + '\'' +
                '}';
    }
}
