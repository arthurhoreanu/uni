public class RomanNumeralConverter {
    public int romanToArabicNumeral(String romisch){
        int number = 0;

        for(int i=0;i<romisch.length();i++){
            if(romisch.charAt(i) == 'I'){
                if( i < romisch.length()-1 && (romisch.charAt(i+1) == 'V' || romisch.charAt(i+1)=='X')) number-=1;
                else number+=1;
            }
            if(romisch.charAt(i) == 'V') number+=5;
            if(romisch.charAt(i) == 'X') number+=10;
        }

        return number;
    }

}
