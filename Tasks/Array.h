#pragma once

class Array {
private:
    int* data;
    int size;

public:
    Array();
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    void insert(int index, int value);
    void erase(int index);
    void print() const;
};
