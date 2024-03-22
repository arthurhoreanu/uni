#include "L1_complex.h"
#include <cmath>
#include <iomanip>
#include <sstream>

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

Complex Complex::add(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::subtract(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::multiply(const Complex& other) const {
    return Complex(real * other.real - imaginary * other.imaginary,
                   real * other.imaginary + imaginary * other.real);
}

Complex Complex::divide(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    return Complex((real * other.real + imaginary * other.imaginary) / denominator,
                   (imaginary * other.real - real * other.imaginary) / denominator);
}

double Complex::absolute() const {
    double absoluteValue = sqrt(real * real + imaginary * imaginary);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << absoluteValue; // set precision at 2 decimals
    return std::stod(oss.str());
}

std::string Complex::text() const {
    std::stringstream ss;
    ss << real;
    if (imaginary > 0) {
        ss << " + " << imaginary << "i";
    } else if (imaginary < 0) {
        ss << " " << imaginary << "i";
    }
    return ss.str();
}

std::string Complex::computePolar() const {
    double absoluteValue = absolute();
    std::ostringstream oss_abs;
    oss_abs << std::fixed << std::setprecision(2) << absoluteValue;  // set precision at 2 decimals
    double angle = atan2(imaginary, real) * 180.0 / M_PI; // calculate theta
    std::ostringstream oss_angle;
    oss_angle << std::fixed << std::setprecision(2) << angle;  // set precision at 2 decimals
    std::string polarString = oss_abs.str() + "(";
    polarString += "cos(" + oss_angle.str() + ")";
    polarString += " + isin(" + oss_angle.str() + "))";
    return polarString; // formatted as absolute(cos(theta) + isin(theta)
}