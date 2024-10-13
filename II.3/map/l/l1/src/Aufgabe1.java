import java.util.Arrays; // Needed for the Array toString conversion

public class Aufgabe1 {

    public static void main(String[] args) {
        Aufgabe1 aufgabe1 = new Aufgabe1();
        int[] array = {29, 37, 38, 41, 84, 67};
        int[] insufficientScoreArray = aufgabe1.insufficientScore(array);
        int[] roundedArray = aufgabe1.rounded(array);

        System.out.println("Aufgabe 1:");
        System.out.println("1. Grades with insufficient score: " + Arrays.toString(insufficientScoreArray));
        System.out.println("2. Average of the grades: " + aufgabe1.average(array));
        System.out.println("3. Rounded grades: " + Arrays.toString(roundedArray));
        System.out.println("4. Maximum rounded grade: " + aufgabe1.maxRounded(array));
        System.out.println("");
    }

    public int[] insufficientScore(int[] gradesArray) {
        int[] result = new int[0];
        int size = 0;
        for (int grade : gradesArray) {
            if (grade < 40) {
                int[] temporary = new int[size + 1];
                for (int i = 0; i < size; i++) {
                    temporary[i] = result[i];
                }
                temporary[size] = grade;
                result = temporary;
                size++;
            }
        }
        return result;
    }

    public double average(int[] gradesArray) {
        double sum = 0;
        for (int i = 0; i < gradesArray.length; i++)
            sum += gradesArray[i];
        double average = sum / gradesArray.length;
        return Math.round(average * 100.0) / 100.0;
    }

    public int[] rounded(int[] gradesArray) {
        int[] result = new int[gradesArray.length];
        int i = 0;
        for (int grade : gradesArray) {
            if (grade >= 38) {
                int nextFiveMultiple = ((grade / 5) + 1) * 5;
                if (nextFiveMultiple - grade < 3)
                    grade = nextFiveMultiple;
            }
            result[i++] = grade;
        }
        return result;
    }

    public int maxRounded(int[] gradesArray) {
        int[] temporaryArray = rounded(gradesArray);
        int max = 0;
        for (int grade : temporaryArray)
            if (grade > max)
                max = grade;
        return max;
    }
}
