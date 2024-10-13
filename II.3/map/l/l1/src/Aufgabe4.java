public class Aufgabe4 {
    public static void main(String[] args) {
        Aufgabe4 aufgabe4 = new Aufgabe4();
        int[] keyboards = {40, 35, 70, 15, 45};
        int[] keyboardsTwo = {15, 20, 10, 35};
        int[] usbs = {20, 15, 40, 15};
        int[] usbsTwo = {15, 45, 20};

        System.out.println("Aufgabe 4:");
        System.out.println("Cheapest keyboard: " + aufgabe4.cheapest(keyboards));
        System.out.println("Most expensive keyboard: " + aufgabe4.mostExpensive(keyboardsTwo));
        System.out.println("Most expensive USB: " + aufgabe4.mostExpensive(usbs));
        System.out.println("Most expensive budget that I can buy: " + aufgabe4.mostExpensiveWithinBudget(usbsTwo, 30));
        System.out.println("");
    }

    public int cheapest(int[] items) {
        int min = Integer.MAX_VALUE;
        for (int item : items)
            if (item < min)
                min = item;
        return min;
    }

    public int mostExpensive(int[] items) {
        int max = Integer.MIN_VALUE;
        for (int item : items)
            if(item > max)
                max = item;
        return max;
    }

    public int mostExpensiveWithinBudget(int[] items, int budget) {
        int max = 0;
        for (int item : items)
            if (item > max && item <= budget)
                max = item;
        return max;
    }

}
