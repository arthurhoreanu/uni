public class Aufgabe4 {
    public static void main(String[] args) {
        Aufgabe4 aufgabe4 = new Aufgabe4();
        int[] keyboards = {40, 35, 70, 15, 45};
        int[] keyboardsTwo = {15, 20, 10, 35};
        int[] usbs = {20, 15, 40, 15};
        int[] usbsTwo = {15, 45, 20};
        int[] keyboardsThree = {40, 50, 60};
        int[] usbsThree = {8, 12};
        int[] keyboardsFour = {60};
        int[] keyboardsFive = {40, 60};

        System.out.println("Aufgabe 4:");
        System.out.println("Cheapest keyboard: " + aufgabe4.cheapest(keyboards));
        System.out.println("Most expensive keyboard: " + aufgabe4.mostExpensive(keyboardsTwo));
        System.out.println("Most expensive USB: " + aufgabe4.mostExpensive(usbs));
        System.out.println("Budget: 30, Most expensive within budget: " + aufgabe4.mostExpensiveWithinBudget(usbsTwo, 30));
        System.out.println("Budget: 60, Markus spends: " +aufgabe4.withinBudget(keyboardsThree, usbsThree, 60));
        System.out.println("Budget: 60, Markus spends: " +aufgabe4.withinBudget(keyboardsFour, usbsThree, 60));
        System.out.println("Budget: 60, Markus spends: " +aufgabe4.withinBudget(keyboardsFive, usbsThree, 60));
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

    public int withinBudget(int[] keyboards, int[] usbs, int budget){
        int max = -1;
        for(int keyboard : keyboards){
            for(int usb: usbs) {
                int total = keyboard + usb;
                if(max < total && total <= budget)
                    max = total;
            }
        }
        return max;
    }

}
