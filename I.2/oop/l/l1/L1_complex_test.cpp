#include <iostream>
#include <cassert>
#include <vector>
#include "L1_complex.h"

int main() {
    Complex z1(1, 2);
    Complex z2(3, 4);
    Complex sum = z1.add(z2);
    Complex diff = z1.subtract(z2);
    Complex prod = z1.multiply(z2);
    Complex division = z1.divide(z2);
    assert(sum.text()=="4 + 6i");
    assert(diff.text()=="-2 -2i");
    assert(prod.text()=="-5 + 10i");
    assert(division.text()=="0.44 + 0.08i");
    assert(z1.absolute()==2.24);
    std::string polarString = z1.computePolar();
    assert(polarString=="2.24(cos(63.43) + isin(63.43))");
    assert(z1.text()=="1 + 2i");

    std::vector<Complex> complexList;
    complexList.push_back(Complex(1, 2));
    complexList.push_back(Complex(3, 4));
    complexList.push_back(Complex(-1, 5));
    Complex sumList(0, 0);
    for (int iterator = 0; iterator < complexList.size(); iterator++){
        sumList = sumList.add(complexList[iterator]);
    };
    std::cout << sumList.text();
}