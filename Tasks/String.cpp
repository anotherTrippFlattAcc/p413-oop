#include "String.h"
#include <iostream>
#include <cstring>

String::String(int s) : size(s) {
    str = new char[size + 1];
    str[0] = '\0';
}

String::String() : String(80) {}

String::String(const char* initStr) : String(strlen(initStr)) {
    strcpy(str, initStr);
}

String::String(String&& other) noexcept : str(other.str), size(other.size) {
    other.str = nullptr;
    other.size = 0;
}

String::String(const String& other) : size(other.size) {
    str = new char[size + 1];
    strcpy(str, other.str);
}

String::~String() {
    delete[] str;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        size = other.size;
        str = new char[size + 1];
        strcpy(str, other.str);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str;
        str = other.str;
        size = other.size;

        other.str = nullptr;
        other.size = 0;
    }
    return *this;
}

void String::input() {
    std::cout << "Введите строку: ";
    std::cin.getline(str, size + 1);
}

void String::print() const {
    std::cout << str << std::endl;
}

const char& String::operator[](int index) const {
    return str[index];
}

int String::operator()(char c) const {
    for (int i = 0; i < size; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

String::operator int() const {
    return strlen(str);
}
