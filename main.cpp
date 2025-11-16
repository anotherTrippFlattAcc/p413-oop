#include <algorithm>
#include <iostream>
#include "Tasks/Fraction.h"
#include "Tasks/Complex.h"
#include "Tasks/Overcoat.h"
#include "Tasks/Flat.h"
#include "Tasks/String.h"
#include "Tasks/Array.h"

void fractionTest() {
    Fraction f1(1, 2);
    Fraction f2(3, 9);
    (f1 + f2).print();
    std::cout << std::endl;
}

void complexTest() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    (c1 + c2).print();
    std::cout << std::endl;
}

void overcoatTest() {
    Overcoat o1(COAT, 150);
    Overcoat o2(COAT, 200);
    Overcoat o3(FUR, 500);

    o1.print();
    o2.print();
    o3.print();

    std::cout << "o1 == o2: " << (o1 == o2) << std::endl;
    std::cout << "o1 == o3: " << (o1 == o3) << std::endl;

    std::cout << "o1 > o2: " << (o1 > o2) << std::endl;

    o1 = o3;
    o1.print();

    o1.setPrice(400);
    std::cout << "o3 > o1: " << (o3 > o1) << std::endl;
}

void flatTest() {
    Flat f1(45.0, 50000);
    Flat f2(45.0, 60000);
    Flat f3(60.0, 75000);

    std::cout << "f1: ";
    f1.print();
    std::cout << std::endl;
    std::cout << "f2: ";
    f2.print();
    std::cout << std::endl;
    std::cout << "f3: ";
    f3.print();
    std::cout << std::endl;

    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    std::cout << "f1 == f3: " << (f1 == f3) << std::endl;

    std::cout << "f1 > f2: " << (f1 > f2) << std::endl;

    f1 = f3;
    f1.print();

    f1.setPrice(400);
    std::cout << "o3 > o1: " << (f3 > f1) << std::endl;
}

void stringTest() {
    String s1("String 1");
    String s2("String 2");

    s1.print();
    s2.print();

    s1 = std::move(s2);
    s1.print();

    std::cout << s1[0] << std::endl;
    std::cout << s1('t') << std::endl;
    std::cout << (int)s1 << std::endl;
}

void arrayTest() {
    Array a1;
    Array a2;

    a1.insert(0, 4);
    a1.insert(1, 2);
    a1.insert(2, 0);

    a2.insert(0, 1);
    a2.insert(1, 2);

    a1.print();
    a2.print();

    a1 = std::move(a2);
    a1.print();
}

int main() {
    fractionTest();
    complexTest();
    overcoatTest();
    flatTest();
    stringTest();
    arrayTest();
}
