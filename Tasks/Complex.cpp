#include "Complex.h"
#include <iostream>

Complex::Complex(double real, double imag) : re(real), im(imag) {}

double Complex::getReal() const {
    return re;
}

double Complex::getImag() const {
    return im;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        re * other.re - im * other.im,
        re * other.im + im * other.re
    );
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.re * other.re + other.im * other.im;

    if (denominator == 0) {
        std::cerr << "[ERROR] Dividing by zero!" << std::endl;
        return Complex(0, 0);
    }

    return Complex(
        (re * other.re + im * other.im) / denominator,
        (im * other.re - re * other.im) / denominator
    );
}

void Complex::print() const {
    if (im >= 0) {
        std::cout << re << " + " << im << "i";
    } else {
        std::cout << re << " - " << -im << "i";
    }
}
