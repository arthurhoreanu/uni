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
        System.out.println("Maximum number: " + aufgabe2.maximumNumber());
    }

    public int maximumNumber() {
        int max = 0;
        for (int number : array)
            if (number > max)
                max = number;
        return max;
    }
}
