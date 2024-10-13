package movie;

import java.util.List;

public abstract class Movie {
    public String title;

    public int year;

    public double rating;

    public List<String> cast;

    public double basePrice;

    public Movie(String title, int year, double rating, List<String> cast, double basePrice) {
        this.title = title;
        this.year = year;
        this.rating = rating;
        this.cast = cast;
        this.basePrice = basePrice;
    }

    abstract double calculatePrice();
}
