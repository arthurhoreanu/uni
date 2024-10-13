package movie;

import java.util.List;

public class User {
    String firstName;

    String lastName;

    List<Order> orders;

    public User(String firstName, String lastName, List<Order> orders) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.orders = orders;
    }

    public double calculateAllOrders() {
        double sum = 0.0;
        for (Order ord : orders) {
            sum += ord.calculateTotalPrice();
        }
        return sum;
    }

}
