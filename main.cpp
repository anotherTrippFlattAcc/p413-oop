#include <iostream>
#include <math.h>

class Employer {
public:
    virtual void Print() const = 0;
    virtual ~Employer() {}
};

class President: public Employer {
public:
    void Print() const override {
        std::cout << "President: head of the company, responsible for strategic decisions." << std::endl;
    }
};

class Manager: public Employer {
public:
    void Print() const override {
        std::cout << "Manager: manages departments and coordinates employee work." << std::endl;
    }
};

class Worker: public Employer {
public:
    void Print() const override {
        std::cout << "Worker: performs operational tasks assigned by management." << std::endl;
    }
};

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class RightTriangle : public Shape {
private:
    double a, b;
public:
    RightTriangle(double a, double b) : a(a), b(b) {}
    double area() const override {
        return a * b / 2;
    }
};

class Trapezoid : public Shape {
private:
    double a, b, h;
public:
    Trapezoid(double a, double b, double h) : a(a), b(b), h(h) {}
    double area() const override {
        return (a + b) * h / 2;
    }
};

void firstTask() {
    Employer* e;

    e = new President();
    e->Print();
    delete e;

    e = new Manager();
    e->Print();
    delete e;

    e = new Worker();
    e->Print();
    delete e;
}

void secondTask() {
    Shape* shapes[4] {
        new Rectangle(5, 10),
        new Circle(3),
        new RightTriangle(6, 8),
        new Trapezoid(4, 10, 5)
    };

    for (int i = 0; i < 4; i++) {
        std::cout << "Area = " << shapes[i]->area() << std::endl;
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }
}

int main() {
    firstTask();
    secondTask();
}