public class Temperature {
    public int[] temperature;
    public Temperature(int[] temp){
        this.temperature = temp;
    }
    public static int avgTemperature(int[] temperatures) {
        int sum = 0;
        for (int temp : temperatures) {
            sum += temp;
        }
        return sum / temperatures.length;
    }

    public static int[] minMaxTemperature(int[] temperatures) {
        int min = temperatures[0];
        int max = temperatures[0];
        for (int temp : temperatures) {
            if (temp < min) {
                min = temp;
            }
            if (temp > max) {
                max = temp;
            }
        }
        return new int[] { min, max };
    }

    public static int[] maxTemperatureDifference(int[] temperatures) {
        int difference = 0;
        int[] numbers = { 0, 0 };

        for (int i = 1; i < temperatures.length; i++) {
            if (temperatures[i] - temperatures[i - 1] > difference) {
                numbers[0] = temperatures[i - 1];
                numbers[1] = temperatures[i];
                difference = temperatures[i] - temperatures[i - 1];
            }
        }
        return numbers;
    }

    public static void printTable(int[] temperatures) {
        System.out.println("Tag\tTemperatur");
        for (int i = 0; i < temperatures.length; i++) {
            System.out.println((i + 1) + "\t" + temperatures[i]);
        }
    }
}
