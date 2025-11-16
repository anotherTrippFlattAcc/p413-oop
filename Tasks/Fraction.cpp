#include "Fraction.h"
#include <iostream>
#include <numeric>

void Fraction::reduce() {
    int g = std::gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int value) {
    numerator = value;
}

void Fraction::setDenominator(int value) {
    denominator = value;
}

void Fraction::input() {
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;
    if (denominator == 0) {
        std::cerr << "Error! Division by zero!";
    }
    reduce();
}

Fraction Fraction::operator+(Fraction f) const {
    int n = numerator * f.denominator + denominator * f.numerator;
    int d = denominator * f.denominator;
    return Fraction(n, d);
}

Fraction Fraction::operator-(Fraction f) const {
    int n = numerator * f.denominator - denominator * f.numerator;
    int d = denominator * f.denominator;
    return Fraction(n, d);
}

Fraction Fraction::operator*(Fraction f) const {
    int n = numerator * f.numerator;
    int d = denominator * f.denominator;
    return Fraction(n, d);
}

Fraction Fraction::operator/(Fraction f) const {
    if (f.numerator == 0) {
        std::cerr << "Error! Division by zero!";
    }
    int n = numerator * f.denominator;
    int d = denominator * f.numerator;
    return Fraction(n, d);
}

void Fraction::print() const {
    std::cout << numerator << "/" << denominator;
}
