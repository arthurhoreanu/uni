#include "L1_rational.h"
#include <cassert>
#include <vector>
#include <iostream>

int main() {
    Rational fractionOne(2, 5);
    Rational fractionTwo(7, 10);
    Rational fractionThree(2, 4);
    Rational fractionFour(1,2);
    Rational sum = fractionOne.add(fractionTwo);
    Rational difference = fractionThree.substract(fractionFour);
    Rational product = fractionThree.multiply(fractionThree);
    Rational division = fractionFour.divide(fractionThree);
    Rational reduction = fractionThree.reduce();
    Rational inversion = fractionTwo.inverse();
    assert(sum.getNumerator()==55 && sum.getDenominator()==50);
    assert(difference.getNumerator()==0);
    assert(product.getNumerator()==4 && product.getDenominator()==16);
    assert(division.getNumerator()==1 && division.getDenominator()==1);
    assert(reduction.getNumerator()==1 && reduction.getDenominator()==2);
    assert(inversion.getNumerator()==10 && inversion.getDenominator()==7);
    assert(fractionThree.compare(fractionFour)==0);

    std::vector<Rational> rationalList;  // an empty vector of rational numbers
    rationalList.push_back(Rational(7, 3)); // add at the end of the vector
    rationalList.push_back(Rational(2, 5));
    rationalList.push_back(Rational(1, 4));
    Rational sumList(0, 1);
    for (int iterator = 0; iterator < rationalList.size(); iterator++){
        sumList = sumList.add(rationalList[iterator]);
    }
    std::cout << sumList.getNumerator() << "/" << sumList.getDenominator();
    return 0;
}