public class Aufgabe4 {
    public static void main(String[] args) {
        Aufgabe4 aufgabe4 = new Aufgabe4();
        int[] keyboards = {40, 35, 70, 15, 45};

        System.out.println("Aufgabe 4:");
        System.out.println("Cheapest keyboard: " + aufgabe4.cheapest(keyboards));
        System.out.println("");
    }

    public int cheapest(int[] items) {
        int min = Integer.MAX_VALUE;
        for (int item : items)
            if (item < min)
                min = item;
        return min;
    }

}
