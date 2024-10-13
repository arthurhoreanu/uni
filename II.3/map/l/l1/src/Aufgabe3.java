import java.util.Arrays; // Needed for the Array toString conversion

public class Aufgabe3 {
    public static void main(String[] args) {
        Aufgabe3 aufgabe3 = new Aufgabe3();
        int[] firstNumber = {1, 3, 0, 0, 0, 0, 0, 0, 0};
        int[] secondNumber = {8, 7, 0, 0, 0, 0, 0, 0, 0};
        int[] thirdNumber = {8, 3, 0, 0, 0, 0, 0, 0, 0};
        int[] fourthNumber = {5, 4, 0, 0, 0, 0, 0, 0, 0};
        int[] fifthNumber = {2, 3, 6, 0, 0, 0, 0, 0, 0};

        System.out.println("130000000 + 870000000 = " + Arrays.toString(aufgabe3.add(firstNumber, secondNumber)));
        System.out.println("830000000 - 540000000 " + Arrays.toString(aufgabe3.subtract(thirdNumber, fourthNumber)));
        System.out.println("236000000 * 2 = " + Arrays.toString(aufgabe3.multiply(fifthNumber, 2)));
        System.out.println("236000000 / 2 = " + Arrays.toString(aufgabe3.divide(fifthNumber, 2)));
    }

        public int[] add(int[] addendOne, int[] addendTwo){
            int carry = 0;
            int[] result = new int[addendOne.length];
            for (int i = addendOne.length - 1; i >= 0; i--) {
                int sum = addendOne[i] + addendTwo[i] + carry;
                result[i] = sum % 10;
                carry = sum / 10;
            }
            if (carry > 0) {
                int[] extendedResult = new int[addendOne.length + 1];
                for (int i = 0; i < result.length; i++)
                    extendedResult[i + 1] = result[i];
                extendedResult[0] = carry;
                return extendedResult;
            }
            return result;
        }

    public int[] subtract(int[] minuend, int[] subtrahend) {
        int borrow = 0;
        int[] result = new int[minuend.length];
        for (int i = minuend.length - 1; i >= 0; i--) {
            int diff = minuend[i] - subtrahend[i] - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else
                borrow = 0;
            result[i] = diff;
        }
        return result;
    }

    public int[] multiply(int[] multiplicand, int multiplier) {
        int carry = 0;
        int[] result = new int[multiplicand.length];
        for (int i = multiplicand.length - 1; i >= 0; i--) {
            int mul = multiplicand[i] * multiplier + carry;
            result[i] = mul % 10;
            carry = mul / 10;
        }
        if (carry > 0) {
            int[] extendedResult = new int[multiplicand.length + 1];
            for (int i = 0; i < result.length; i++)
                extendedResult[i + 1] = result[i];
            extendedResult[0] = carry;
            return extendedResult;
        }
        return result;
    }

    public int[] divide(int[] dividend, int divisor) {
        if (divisor == 0) {
            throw new IllegalArgumentException("Divisor cannot be zero.");
        }
        if (dividend == null || dividend.length == 0) {
            return new int[]{0};
        }

        int[] result = new int[dividend.length];
        int remainder = 0;
        for (int i = 0; i < dividend.length; i++) {
            int current = remainder * 10 + dividend[i];
            result[i] = current / divisor;
            remainder = current % divisor;
        }

        // Getting rid of the zeros at the end
        int nonZeroIndex = 0;
        while (nonZeroIndex < result.length && result[nonZeroIndex] == 0) {
            nonZeroIndex++;
        }

        // Finding the last non-zero index
        int end = result.length - 1;
        while (end >= nonZeroIndex && result[end] == 0) {
            end--;
        }

        // If all elements are zero, return [0]
        if (nonZeroIndex > end) {
            return new int[]{0};
        }

        // Copying the non-zero range from start to end
        return Arrays.copyOfRange(result, nonZeroIndex, end + 1);
    }
}