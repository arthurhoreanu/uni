#include "L1_rational.h"
#include <numeric>
#include <iostream>

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    if (denominator == 0) {
        std::cout << "Error: Denominator cannot be zero." << std::endl;
    }
}

int Rational::getNumerator() {
    return numerator;
}

int Rational::getDenominator() {
    return denominator;
}

Rational Rational::add(const Rational& other) const {
    int resultNumerator = numerator * other.denominator + other.numerator * denominator;
    int resultDenominator = denominator * other.denominator;
    if (resultNumerator == 0) {
        return Rational(0, 1);
    } else if (resultDenominator == 0) {
        std::cerr << "Error: Denomination by zero." << std::endl;
        return Rational(0, 1);
    } else if (resultNumerator == resultDenominator) {
        return Rational(1, 1);
    } else
        return Rational(resultNumerator, resultDenominator);
}

Rational Rational::substract(const Rational& other) const {
    int resultNumerator = numerator * other.denominator - other.numerator * denominator;
    int resultDenominator = denominator * other.denominator;
    if (resultNumerator == 0) {
        return Rational(0, 1);
    } else if (resultDenominator == 0) {
        std::cerr << "Error: Denomination by zero." << std::endl;
        return Rational(0, 1);
    } else if (resultNumerator == resultDenominator) {
        return Rational(1, 1);
    } else
        return Rational(resultNumerator, resultDenominator);
}

Rational Rational::multiply(const Rational& other) const {
    int resultNumerator = numerator * other.numerator;
    int resultDenominator = denominator * other.denominator;
    if (resultNumerator == 0) {
        return Rational(0, 1);
    } else if (resultDenominator == 0) {
        std::cerr << "Error: Denomination by zero." << std::endl;
        return Rational(0, 1);
    } else if (resultNumerator == resultDenominator) {
        return Rational(1, 1);
    } else
        return Rational(resultNumerator, resultDenominator);
}

Rational Rational::divide(const Rational& other) const {
    int resultNumerator = numerator * other.denominator;
    int resultDenominator = denominator * other.numerator;
    if (resultNumerator == 0) {
        return Rational(0, 1);
    } else if (resultDenominator == 0) {
        std::cerr << "Error: Denomination by zero." << std::endl;
        return Rational(0, 1);
    } else if (resultNumerator == resultDenominator) {
        return Rational(1, 1);
    } else
        return Rational(resultNumerator, resultDenominator);
}

Rational Rational::reduce() {
    int simplifiedNumerator = numerator / std::gcd(numerator, denominator);
    int simplifiedDenominator = denominator / std::gcd(numerator, denominator);
    return Rational(simplifiedNumerator, simplifiedDenominator);
}

Rational Rational::inverse() const {
    return Rational(denominator, numerator);
}

int Rational::compare(const Rational &other) const {
    if(numerator * other.denominator < other.numerator * denominator)
        return -1;
    else if (numerator * other.denominator > other.numerator * denominator)
        return 1;
    else
        return 0;
}
