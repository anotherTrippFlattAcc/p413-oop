#include <iostream>
#include <numeric>

class BaseException : public std::exception {
protected:
    std::string message;
public:
    explicit BaseException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class MathException : public BaseException {
public:
    explicit MathException(const std::string& msg) : BaseException(msg) {}
};

class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("[ERROR] Dividing by zero!") {}
};

class NegativeSqrtException : public MathException {
public:
    NegativeSqrtException() : MathException("[ERROR] Root of a negative number!") {}
};

class OverflowException : public MathException {
public:
    OverflowException() : MathException("[ERROR] Overflow!") {}
};

class MemoryException : public BaseException {
public:
    explicit MemoryException(const std::string& msg) : BaseException(msg) {}
};

class OutOfMemoryCustomException : public MemoryException {
public:
    OutOfMemoryCustomException() : MemoryException("[ERROR] Out of memory!") {}
};

class MemoryAllocationException : public MemoryException {
public:
    MemoryAllocationException() : MemoryException("[ERROR] Failed to allocate memory!") {}
};

class FileException : public BaseException {
public:
    explicit FileException(const std::string& msg) : BaseException(msg) {}
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException() : FileException("[ERROR] File not found!") {}
};

class FileReadException : public FileException {
public:
    FileReadException() : FileException("[ERROR] Cannot read file!") {}
};

class FileWriteException : public FileException {
public:
    FileWriteException() : FileException("[ERROR] Cannot write file!") {}
};

class DataStructureException : public BaseException {
public:
    explicit DataStructureException(const std::string& msg) : BaseException(msg) {}
};

class EmptyContainerException : public DataStructureException {
public:
    EmptyContainerException() : DataStructureException("[ERROR] Data structure is empty!") {}
};

class IndexOutOfRangeException : public DataStructureException {
public:
    IndexOutOfRangeException() : DataStructureException("[ERROR] Index out of range!") {}
};

class InvalidOperationException : public DataStructureException {
public:
    InvalidOperationException() : DataStructureException("[ERROR] Invalid operation with data structure!") {}
};

namespace Math {
    namespace Fractions {
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

            Fraction add(Fraction f) {
                int n = this->numerator * f.denominator + this->denominator * f.numerator;
                int d = this->denominator * f.denominator;
                return Fraction(n, d);
            }

            Fraction subtract(Fraction f) {
                int n = this->numerator * f.denominator - this->denominator * f.numerator;
                int d = this->denominator * f.denominator;
                return Fraction(n, d);
            }

            Fraction multiply(Fraction f) {
                int n = this->numerator * f.numerator;
                int d = this->denominator * f.denominator;
                return Fraction(n, d);
            }

            Fraction divide(Fraction f) {
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
    }
    namespace Geometry {
        namespace Geometry2D {
            class Point2D {
            private:
                double x, y;

            public:
                explicit Point2D(const double x = 0, const double y = 0) : x(x), y(y) {}

                double getX() const { return x; }

                double getY() const { return y; }
            };
        }
        namespace Geometry3D {
            class Point3D {
            private:
                double x, y, z;

            public:
                explicit Point3D(const double x = 0, const double y = 0, const double z = 0): x(x), y(y), z(z) {}

                double getX() const { return x; }

                double getY() const { return y; }

                double getZ() const { return z; }
            };
        }
    }
}

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        while (head) pop_front();
    }

    int getSize() const { return size; }

    void push_front(int value) {
        Node* newNode = nullptr;

        try {
            newNode = new Node(value);
        } catch (std::bad_alloc&) {
            throw MemoryAllocationException();
        }

        newNode->next = head;

        if (head) head->prev = newNode;
        else tail = newNode;

        head = newNode;
        size++;
    }

    void push_back(int value) {
        Node* newNode = nullptr;

        try {
            newNode = new Node(value);
        } catch (std::bad_alloc&) {
            throw MemoryAllocationException();
        }

        newNode->prev = tail;

        if (tail) tail->next = newNode;
        else head = newNode;

        tail = newNode;
        size++;
    }

    void pop_front() {
        if (!head) throw EmptyContainerException();

        Node* temp = head;
        head = head->next;

        if (head) head->prev = nullptr;
        else tail = nullptr;

        delete temp;
        size--;
    }

    void pop_back() {
        if (!tail) throw EmptyContainerException();

        Node* temp = tail;
        tail = tail->prev;

        if (tail) tail->next = nullptr;
        else head = nullptr;

        delete temp;
        size--;
    }

    int at(int index) const {
        if (index >= size) throw IndexOutOfRangeException();

        Node* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        return current->data;
    }

    void print() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        DoublyLinkedList list;

        list.push_back(10);
        list.push_back(20);
        list.push_front(5);

        list.print();

        std::cout << "Element with index 1: " << list.at(1) << std::endl;

        list.pop_front();
        list.pop_back();
        list.pop_back();

        list.pop_back();

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    using Math::Fractions::Fraction;
    using Math::Geometry::Geometry2D::Point2D;
    using Math::Geometry::Geometry3D::Point3D;

    std::cout << "Fraction" << std::endl;
    Fraction a(1, 2);
    Fraction b(2, 10);
    a.print();
    std::cout << " + ";
    b.print();
    std::cout << " = ";
    a.add(b).print();
    std::cout << std::endl;

    std::cout << "Point2D" << std::endl;
    Point2D p2d(1, 2);
    std::cout << p2d.getX() << ", " << p2d.getY() << std::endl;

    std::cout << "Point3D" << std::endl;
    Point3D p3d(1, 2, 3);
    std::cout << p3d.getX() << ", " << p3d.getY() << ", " << p3d.getZ() << std::endl;
}