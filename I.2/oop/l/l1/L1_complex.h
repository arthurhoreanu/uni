#ifndef L1_COMPLEX_H
#define L1_COMPLEX_H

#include <cmath>
#include <string>

class Complex {
private:
    double real;
    double imag;
    int iterator;

public:
    Complex(double real = 0.0, double imag = 0.0);
    double getReal() const;
    double getImaginary() const;
    Complex add(const Complex& other) const;
    Complex subtract(const Complex& other) const;
    Complex multiply(const Complex& other) const;
    Complex divide(const Complex& other) const;
    double absolute() const;
    std::string computePolar() const;
    std::string text() const;
};

#endif
