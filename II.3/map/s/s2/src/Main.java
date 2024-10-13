import java.util.Date;
import java.util.List;

import box.Hammer;
import box.Box;
import box.Nail;
import box.Saw;
import box.Scissor;
import movie.ComedyMovie;
import movie.HorrorMovie;
import movie.Movie;
import movie.Order;
import movie.OrderLine;
import movie.SciFiMovie;
import movie.User;
import strategy.AddStrategy;
import strategy.DivStrategy;
import strategy.MathStrategy;
import strategy.MulStrategy;
import strategy.SubStrategy;

public class Main {
    public static void main(String[] args) {
        Box kiste = new Box();

        kiste.add(new Hammer(1.2));
        kiste.add(new Hammer(0.8));
        kiste.add(new Nail());
        kiste.add(new Nail());
        kiste.add(new Nail());
        kiste.add(new Saw(1.2));
        kiste.add(new Scissor(0.8));

        System.out.println(kiste);
        System.out.println(kiste.heavyObject());
        System.out.println(kiste.canCut());

        String math = "3*2+1";

        double acc = Double.parseDouble(math.substring(0, 1));

        for (int i = 1; i < math.length(); i += 2) {
            acc = getStrategy(math.charAt(i)).op(acc, Double.parseDouble(math.substring(i + 1, i + 2)));
        }

        System.out.println(acc);

        Movie m1 = new ComedyMovie("Movie1", 2000, 4.1, List.of("Adam Sandler"), 20.0);
        Movie m2 = new HorrorMovie("Movie2", 2003, 3.2, List.of("xz"), 19.5);
        Movie m3 = new SciFiMovie("Movie 3", 2012, 5.0, List.of("abc"), 13.4);

        OrderLine ol1 = new OrderLine(m1, 2);
        OrderLine ol2 = new OrderLine(m2, 4);
        OrderLine ol3 = new OrderLine(m3, 6);

        Order o1 = new Order(new Date(1728477077), List.of(ol1, ol2, ol3));

        User u1 = new User("Abc", "Def", List.of(o1));

        System.out.println(u1.calculateAllOrders());

    }

    static MathStrategy getStrategy(char c) {
        return switch (c) {
            case '+' -> new AddStrategy();
            case '-' -> new SubStrategy();
            case '*' -> new MulStrategy();
            case '/' -> new DivStrategy();
            default -> null;
        };
    }
}