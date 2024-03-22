#include "L1_complex.h"
#include <cassert>
#include <vector>
#include <iostream>

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex sum = c1.add(c2);
    Complex difference = c1.subtract(c2);
    Complex product = c1.multiply(c2);
    Complex division = c1.divide(c2);

    assert(sum.getReal()==4 && sum.getImaginary()==6);
    assert(difference.getReal() == -2 && difference.getImaginary() == -2);
    assert(product.getReal() == -5 && product.getImaginary() == 10);
    assert(division.getReal() == 0.44 && division.getImaginary() == 0.08);
    assert(c1.absolute()==2.24);
    assert(c1.text()=="1 + 2i");
    assert(c1.computePolar()=="2.24(cos(63.43) + isin(63.43))");

    std::vector<Complex> complexList; // an empty vector of complex numbers
    complexList.push_back(Complex(1, 2)); // add at the end of the vector
    complexList.push_back(Complex(3, 4));
    complexList.push_back(Complex(-1, 5));
    Complex sumList(0, 0); // initialize an empty complex sum
    for (int iterator = 0; iterator < complexList.size(); iterator++){
        sumList = sumList.add(complexList[iterator]);
    }
    std::cout << sumList.getReal() << " + " << sumList.getImaginary() << "i";
    return 0;
}
