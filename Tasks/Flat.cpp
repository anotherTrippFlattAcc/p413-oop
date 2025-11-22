#include "Flat.h"
#include <iostream>

Flat::Flat(double area, double price) : area(area), price(price) {}

double Flat::getArea() const {
    return area;
}

double Flat::getPrice() const {
    return price;
}

void Flat::setArea(double a) {
    area = a;
}

void Flat::setPrice(double p) {
    price = p;
}

bool Flat::operator==(const Flat& other) const {
    return this->area == other.area;
}

Flat& Flat::operator=(const Flat& other) {
    if (this == &other) return *this;

    this->area = other.area;
    this->price = other.price;

    return *this;
}

bool Flat::operator>(const Flat& other) const {
    return this->price > other.price;
}

void Flat::print() const {
    std::cout << "Area: " << area << " Price: " << price << std::endl;
}
