public class Aufgabe4 {
    public static void main(String[] args) {
        Aufgabe4 aufgabe4 = new Aufgabe4();
        int[] keyboards = {40, 35, 70, 15, 45};
        int[] keyboardsTwo = {15, 20, 10, 35};
        int[] USBs = {20, 15, 40, 15};

        System.out.println("Aufgabe 4:");
        System.out.println("Cheapest keyboard: " + aufgabe4.cheapest(keyboards));
        System.out.println("Most expensive keyboard: " + aufgabe4.mostExpensive(keyboardsTwo));
        System.out.println("Most expensive USB: " + aufgabe4.mostExpensive(USBs));
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

}
