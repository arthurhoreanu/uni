package movie;

import java.util.List;

public class SciFiMovie extends Movie {

    public SciFiMovie(String title, int year, double rating, List<String> cast, double basePrice) {
        super(title, year, rating, cast, basePrice);
    }

    @Override
    public double calculatePrice() {
        return basePrice;
    }
}