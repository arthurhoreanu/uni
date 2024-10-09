public class Temperature {

    public int[] temperatures;

    public Temperature(int[] temperatures) {
        this.temperatures = temperatures;
    }

    public double average() {
        double sum = 0;

        for (int i = 0; i < temperatures.length; i++) {
            sum += temperatures[i];
        }

        return sum / temperatures.length;
    }

    public int[] maxDiff() {
        int maxdif = 0;
        int index = 0;
        for (int i = 0; i < temperatures.length - 1; i++) {
            if (temperatures[i + 1] - temperatures[i] > maxdif) {
                index = i;
                maxdif = temperatures[i + 1] - temperatures[i];
            }
            if (temperatures[i] - temperatures[i + 1] > maxdif) {
                index = i;
                maxdif = temperatures[i] - temperatures[i + 1];
            }
        }
        return new int[]{index+1, index+2};
    }

    public int min() {
        int min = temperatures[0];
        for (int i = 1; i < temperatures.length; i++) {
            if (temperatures[i] < min) {
                min = temperatures[i];
            }
        }
        return min;
    }

    public int max() {
        int max = temperatures[0];
        for (int i = 1; i < temperatures.length; i++) {
            if (temperatures[i] > max) {
                max = temperatures[i];
            }
        }

        return max;
    }

    public void print() {
        String days = "Tag:";
        String temperatures = "Temperatur:";
        int difference = temperatures.length() - days.length();
        for (int i = 0; i < difference; i++) {
            days += " ";
        }
        for (int i = 0; i < this.temperatures.length; i++) {
            String day = String.valueOf(i + 1);
            String temp = String.valueOf(this.temperatures[i]);

            if (day.length() > temp.length()) {
                for (int ii = 0; ii < day.length() - temp.length(); ii++) {
                    temperatures += " ";
                }
            } else if (temp.length() > day.length()) {
                for (int ii = 0; ii < temp.length() - day.length(); ii++) {
                    days += " ";
                }
            }
            temperatures += " ";
            days += " ";

            temperatures += temp;
            days += day;

        }
        System.out.println(days);
        System.out.println(temperatures);
    }
}
