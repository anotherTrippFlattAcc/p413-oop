#include "Overcoat.h"
#include <iostream>

Overcoat::Overcoat(CoatType type, double price) : type(type), price(price) {}

CoatType Overcoat::getType() const {
    return type;
}

double Overcoat::getPrice() const {
    return price;
}

void Overcoat::setType(CoatType t) {
    type = t;
}

void Overcoat::setPrice(double p) {
    price = p;
}

bool Overcoat::operator==(const Overcoat& other) const {
    return this->type == other.type;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
    if (this == &other) return *this;
    this->type = other.type;
    this->price = other.price;
    return *this;
}

bool Overcoat::operator>(const Overcoat& other) const {
    if (this->type != other.type) {
        std::cerr << "[ERROR] Different types of overcoat!\n";
        return false;
    }
    return this->price > other.price;
}

void Overcoat::print() const {
    static const char* names[] = { "JACKET", "COAT", "RAINCOAT", "FUR" };
    std::cout << "Type: " << names[type] << ", price: " << price << std::endl;
}
