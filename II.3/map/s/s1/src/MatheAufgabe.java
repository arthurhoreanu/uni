public class MatheAufgabe {

    public double add(double x, double y){
        return x+y;
    }

    public double sub(double x, double y){
        return x-y;
    }

    public double mul(double x, int m){
        double result=0;
        for (int i = 0; i < m; i++) {
            result+=x;
        }
        return result;
    }

    public boolean isPerfect(int nr){
        int[] factors = new int[]{};

        for(int i=1; i < nr ; i++){
            if(nr%i == 0){
                factors=add(factors,i);
            }
        }

        int sum=0;
        for (int i = 0; i < factors.length; i++) {
            sum+=factors[i];
        }

        return nr == sum;
    }

    public int[] add(int[] array, int value){
        int[] result = new int[array.length+1];

        for (int i = 0; i < array.length; i++) {
            result[i] = array[i];
        }

        result[result.length-1] = value;

        return result;
    }
}
