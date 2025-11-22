#pragma once

class Complex {
private:
    double re;
    double im;

public:
    explicit Complex(double real = 0.0, double imag = 0.0);

    double getReal() const;
    double getImag() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    void print() const;
};
