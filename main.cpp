#include <iostream>
#include <numeric>

class Fraction {
        private:
            int numerator;
            int denominator;

            void reduce() {
                int g = std::gcd(numerator, denominator);
                numerator /= g;
                denominator /= g;

                if (denominator < 0) {
                    numerator = -numerator;
                    denominator = -denominator;
                }
            }
        public:
            explicit Fraction(int numerator = 1, int denominator = 1) {
                this->numerator = numerator;
                this->denominator = denominator;
                reduce();
            }

            int getNumerator() const {
                return numerator;
            }

            int getDenominator() const {
                return denominator;
            }

            void setNumerator(int value) {
                this->numerator = value;
            }

            void setDenominator(int value) {
                this->denominator = value;
            }

            void input() {
                std::cout << "Enter numerator: ";
                std::cin >> numerator;
                std::cout << "Enter denominator: ";
                std::cin >> denominator;
                if (denominator == 0) {
                    std::cerr << "Error! Division by zero!";
                }
                reduce();
            }

            Fraction operator+(Fraction f) const {
                int n = this->numerator * f.denominator + this->denominator * f.numerator;
                int d = this->denominator * f.denominator;
                return Fraction(n, d);
            }

            Fraction operator-(Fraction f) const {
                int n = this->numerator * f.denominator - this->denominator * f.numerator;
                int d = this->denominator * f.denominator;
                return Fraction(n, d);
            }

            Fraction operator*(Fraction f) const {
                int n = this->numerator * f.numerator;
                int d = this->denominator * f.denominator;
                return Fraction(n, d);
            }

            Fraction operator/(Fraction f) const {
                if (f.numerator == 0) {
                    std::cerr << "Error! Division by zero!";
                }

                int n = this->numerator * f.denominator;
                int d = this->denominator * f.numerator;
                return Fraction(n, d);
            }

            void print() const {
                std::cout << numerator << "/" << denominator;
            }
};

class Complex {
private:
    double re;
    double im;

public:
    explicit Complex(double real, double imag) : re(real), im(imag) {}

    double getReal() const { return re; }

    double getImag() const { return im; }

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            re * other.re - im * other.im,
            re * other.im + im * other.re
        );
    }

    Complex operator/(const Complex& other) const {
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

    void print() const {
        if (im >= 0) {
            std::cout << re << " + " << im << "i";
        } else {
            std::cout << re << " - " << -im << "i";
        }
    }
};

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
    explicit Overcoat(CoatType type, double price): type(type), price(price) {}

    CoatType getType() const { return type; }
    double getPrice() const { return price; }

    void setType(CoatType t) { type = t; }
    void setPrice(double p) { price = p; }

    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this == &other) return *this;
        this->type = other.type;
        this->price = other.price;
        return *this;
    }

    bool operator>(const Overcoat& other) const {
        if (this->type != other.type) {
            std::cerr << "[ERROR] Different types of overcoat!\n";
            return false;
        }
        return this->price > other.price;
    }

    void print() const {
        static const char* names[] = { "JACKET", "COAT", "RAINCOAT", "FUR" };
        std::cout << "Type: " << names[type] << ", price: " << price << std::endl;
    }
};


class Flat {
private:
    double area;
    double price;

public:
    explicit Flat(double area = 0.0, double price = 0.0)
        : area(area), price(price) {}

    double getArea() const { return area; }
    double getPrice() const { return price; }

    void setArea(double a) { area = a; }
    void setPrice(double p) { price = p; }

    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }

    Flat& operator=(const Flat& other) {
        if (this == &other) return *this;

        this->area = other.area;
        this->price = other.price;

        return *this;
    }

    bool operator>(const Flat& other) const {
        return this->price > other.price;
    }

    void print() {
        std::cout << "Area: " << area << " Price: " << price << std::endl;
    }
};

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

int main() {
    fractionTest();
    complexTest();
    overcoatTest();
    flatTest();
}
