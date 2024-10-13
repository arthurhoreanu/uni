package movie;

import java.util.Date;
import java.util.List;

public class Order {
    private Date orderDate;

    private List<OrderLine> orderLines;

    public Order(Date orderDate, List<OrderLine> orderLines) {
        this.orderDate = orderDate;
        this.orderLines = orderLines;
    }

    public double calculateTotalPrice() {
        double sum = 0.0;
        for (OrderLine ol : this.orderLines) {
            sum += ol.calculatePrice();
        }
        return sum;
    }
}
