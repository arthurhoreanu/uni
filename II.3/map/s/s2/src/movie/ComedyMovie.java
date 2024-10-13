package movie;

import java.util.List;

public class ComedyMovie extends Movie {

    public ComedyMovie(String title, int year, double rating, List<String> cast, double basePrice) {
        super(title, year, rating, cast, basePrice);
    }

    public double calculatePrice() {
        if (cast.contains("Adam Sandler")) {
            return basePrice * 0.5;
        } else {
            return basePrice;
        }
    }
}
