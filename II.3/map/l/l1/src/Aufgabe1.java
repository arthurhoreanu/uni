import java.util.Arrays; // needed for the Array toString conversion

public class Aufgabe1 {
    public static void main(String[] args) {
        Aufgabe1 aufgabe1 = new Aufgabe1();
        int[] array = {29, 37, 38, 41, 84, 67};
        int[] insufficientScoreArray = aufgabe1.insufficientScore(array);

        System.out.println("1. Grades with insufficient score: " + Arrays.toString(insufficientScoreArray));
    }

    public int[] insufficientScore(int[] gradesArray) {
        int[] result = new int[0];
        int size = 0;
        for(int grade : gradesArray){
            if(grade < 40){
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
}
