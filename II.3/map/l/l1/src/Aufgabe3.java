import java.util.Arrays; // Needed for the Array toString conversion.

public class Aufgabe3 {
    public static void main(String[] args) {
        Aufgabe3 aufgabe3 = new Aufgabe3();
        int[] firstNumber = {1, 3, 0, 0, 0, 0, 0, 0, 0};
        int[] secondNumber = {8, 7, 0, 0, 0, 0, 0, 0, 0};

        System.out.println("130000000 + 870000000 = " + Arrays.toString(aufgabe3.sum(firstNumber, secondNumber)));
    }

        public int[] sum ( int[] number, int[] otherNumber){
            int carry = 0;
            int[] result = new int[number.length];
            for (int i = number.length - 1; i >= 0; i--) {
                int sum = number[i] + otherNumber[i] + carry;
                result[i] = sum % 10;
                carry = sum / 10;
            }
            if (carry > 0) {
                int[] extendedResult = new int[number.length + 1];
                for (int i = 0; i < result.length; i++)
                    extendedResult[i + 1] = result[i];
                extendedResult[0] = carry;
                return extendedResult;
            }
            return result;
        }
}