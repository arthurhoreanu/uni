#include "L1_complex.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imag;
}

Complex Complex::add(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::subtract(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::multiply(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}

Complex Complex::divide(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denom,
                   (imag * other.real - real * other.imag) / denom);
}

double Complex::absolute() const {
    double abs_value = sqrt(real * real + imag * imag);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << abs_value;
    return std::stod(oss.str());  // Convert formatted string back to double
}

std::string Complex::computePolar() const {
    double abs = absolute();
    std::ostringstream oss_abs;
    oss_abs << std::fixed << std::setprecision(2) << abs;
    double angle = atan2(imag, real) * 180.0 / M_PI;
    std::ostringstream oss_angle;
    oss_angle << std::fixed << std::setprecision(2) << angle;
    std::string polarString = oss_abs.str() + "(";
    polarString += "cos(" + oss_angle.str() + ")";
    polarString += " + isin(" + oss_angle.str() + "))";
    return polarString;
}

std::string Complex::text() const {
    std::stringstream ss;
    ss << real;
    if (imag > 0) {
        ss << " + " << imag << "i";
    } else if (imag < 0) {
        ss << " " << imag << "i";
    }
    return ss.str();
}