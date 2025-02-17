


public class Main {
    public static void main(String[] args) {

        MatheAufgabe operation = new MatheAufgabe();

        double x = 1.3;
        double y = 0.9;

        System.out.println("1.1 add(1.3,0.9): "+operation.add(x, y));
        System.out.println("1.2 sub(1.3,0.9): "+operation.sub(x, y));
        System.out.println("1.3 mul(1.3,3): "+operation.mul(x, 3));

        StringOps stringOps = new StringOps();

        System.out.println("2. reverse(\"Hello World\"): "+stringOps.reverse("Hello World"));
        System.out.println("3. wordCount(\"Die Sonne ging hinter den Bergen unter und malte alles golden.\"): "
                + stringOps.wordCount("Die Sonne ging hinter den Bergen unter und malte alles golden."));

        System.out.println("4. isPerfekt(6): "+ operation.isPerfect(6));

        Temperature temperature = new Temperature(new int[] { 12, 14, 9, 12, 15, 16, 15, 15, 11, 8, 13, 13, 15, 12 });

        System.out.println("5.1 average: " + temperature.average());
        System.out.println("5.2 min: " + temperature.min());
        System.out.println("5.2 max: " + temperature.max());
        System.out.println("5.2 maxDiff: " + temperature.maxDiff()[0]+","+temperature.maxDiff()[1]);
        System.out.println("5.3 print:");
        temperature.print();


        System.out.println("6. romanToArabic(\"XIV\"): "+new RomanNumeralConverter().romanToArabicNumeral("XIV"));
    }

}