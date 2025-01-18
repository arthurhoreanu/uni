package model;

/**
 * A product from the sports store.
 */
public class Product {

    private int productID;
    private String name;
    private double price;
    private String season;

    public Product(int productID, String name, double price, String season) {
        this.productID = productID;
        this.name = name;
        this.price = price;
        this.season = season;
    }

    public int getProductID() {
        return productID;
    }

    public void setProductID(int productID) {
        this.productID = productID;
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
                "productID=" + productID +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", season='" + season + '\'' +
                '}';
    }
}