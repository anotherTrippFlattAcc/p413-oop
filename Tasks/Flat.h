#pragma once

class Flat {
private:
    double area;
    double price;

public:
    explicit Flat(double area = 0.0, double price = 0.0);

    double getArea() const;
    double getPrice() const;

    void setArea(double a);
    void setPrice(double p);

    bool operator==(const Flat& other) const;
    Flat& operator=(const Flat& other);
    bool operator>(const Flat& other) const;

    void print() const;
};
