#pragma once

enum CoatType {
    JACKET,
    COAT,
    RAINCOAT,
    FUR
};

class Overcoat {
private:
    CoatType type;
    double price;

public:
    explicit Overcoat(CoatType type, double price);

    CoatType getType() const;
    double getPrice() const;

    void setType(CoatType t);
    void setPrice(double p);

    bool operator==(const Overcoat& other) const;
    Overcoat& operator=(const Overcoat& other);
    bool operator>(const Overcoat& other) const;

    void print() const;
};
