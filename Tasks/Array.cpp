#include "Array.h"
#include <iostream>

Array::Array() : data(nullptr), size(0) {}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

Array::Array(Array&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

Array::~Array() {
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

void Array::insert(int index, int value) {
    if (index < 0 || index > size) return;
    int* newData = new int[size + 1];

    for (int i = 0; i < index; i++) newData[i] = data[i];
    newData[index] = value;
    for (int i = index; i < size; i++) newData[i + 1] = data[i];

    delete[] data;
    data = newData;
    size++;
}

void Array::erase(int index) {
    if (index < 0 || index >= size) return;
    int* newData = new int[size - 1];

    for (int i = 0, j = 0; i < size; i++) {
        if (i != index)
            newData[j++] = data[i];
    }

    delete[] data;
    data = newData;
    size--;
}

void Array::print() const {
    for (int i = 0; i < size; i++) std::cout << data[i] << " ";
    std::cout << std::endl;
}
