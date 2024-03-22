#include <string>

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int numerator, int denominator);

    int getNumerator();
    int getDenominator();

    Rational add(const Rational& other) const;
    Rational substract(const Rational& other) const;
    Rational multiply(const Rational& other) const;
    Rational divide(const Rational& other) const;
    Rational reduce();
    Rational inverse() const;
    int compare(const Rational& other) const;
};



