public class Main {
    public static void main(String[] args) {
        MatheAufgabe op = new MatheAufgabe();
        System.out.println(op.add(1, 2));
        System.out.println(op.sub(2, 1));
        System.out.println(op.isPerfect(6));

        System.out.println(reverse("string"));
        System.out.println(wordCount("This is a sentence"));

        int[] temperatures = { 12, 14, 9, 12, 15, 16, 15, 15, 11, 8, 13, 13, 15, 12 };
        System.out.println("Average Temperature: " + Temperature.avgTemperature(temperatures));

        int[] minMax = Temperature.minMaxTemperature(temperatures);
        System.out.println("Min Temperature: " + minMax[0]);
        System.out.println("Max Temperature: " + minMax[1]);

        int[] maxDiff = Temperature.maxTemperatureDifference(temperatures);
        System.out.println("Day with Max Temperature Difference: " + maxDiff[0] + " to " + maxDiff[1]);

        Temperature.printTable(temperatures);

    }

    public static StringBuilder builder = new StringBuilder();

    public static String reverse(String input) {
        for (int i = input.length() - 1; i >= 0; i--) {
            char ch = input.charAt(i);
            builder.append(ch);
        }
        return builder.toString();
    }

    public static int wordCount(String sentence) {
        int count = 0;
        boolean inWord = false;
        for (char ch : sentence.toCharArray()) {
            if (Character.isLetter(ch)) {
                inWord = true;
            } else {
                if (inWord) {
                    count++;
                    inWord = false;
                }
            }
        }
        if (inWord) {
            count++;
        }
        return count;
    }

}