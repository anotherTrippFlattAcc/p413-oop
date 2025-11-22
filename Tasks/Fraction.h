#pragma once

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce();

public:
    explicit Fraction(int numerator = 1, int denominator = 1);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int value);
    void setDenominator(int value);

    void input();

    Fraction operator+(Fraction f) const;
    Fraction operator-(Fraction f) const;
    Fraction operator*(Fraction f) const;
    Fraction operator/(Fraction f) const;

    void print() const;
};
