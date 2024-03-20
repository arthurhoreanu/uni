#include <string>

#ifndef L1__L1__COMPLEX_H
#define L1__L1__COMPLEX_H

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary);
    double getReal() const;
    double getImaginary() const;
    Complex add(const Complex& other) const;
    Complex subtract(const Complex& other) const;
    Complex multiply(const Complex& other) const;
    Complex divide(const Complex& other) const;
    double absolute() const;
    std::string text() const;
    std::string computePolar() const;
};

#endif