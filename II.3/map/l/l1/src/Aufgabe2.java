public class Aufgabe2 {

    int n;
    int[] array;

    // Constructor
    public Aufgabe2(int n, int[] array) {
        this.n = n;
        this.array = array;
    }

    public static void main(String[] args) {
        Aufgabe2 aufgabe2 = new Aufgabe2(5, new int[]{4, 8, 3, 10, 17});

        System.out.println("Aufgabe 2:");
        System.out.println("Array: [4, 8, 3, 10, 17]");
        System.out.println("1. Maximum number: " + aufgabe2.maximumNumber());
        System.out.println("2. Minimum number: " + aufgabe2.minimumNumber());
        System.out.println("3. Maximum sum of n-1 numbers: " + aufgabe2.maximumSumWithoutOneNumber());
        System.out.println("4. Mininum sum of n-1 numbers: " + aufgabe2.minimumSumWithoutOneNumber());
        System.out.println("");
    }

    public int maximumNumber() {
        int max = Integer.MIN_VALUE;
        for (int number : array)
            if (number > max)
                max = number;
        return max;
    }

    public int minimumNumber() {
        int min = Integer.MAX_VALUE;
        for (int number : array)
            if (number < min)
                min = number;
        return min;
    }

    public int maximumSumWithoutOneNumber() {
        int maxSum = 0;
        for (int number : array)
                maxSum += number;
        return maxSum - minimumNumber();
    }

    public int minimumSumWithoutOneNumber() {
        int minSum = 0;
        for (int number : array)
                minSum += number;
        return minSum - maximumNumber();
    }
}