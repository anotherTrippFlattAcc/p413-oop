#pragma once

class String {
private:
    char* str;
    int size;

public:
    explicit String(int s);
    String();
    explicit String(const char* initStr);
    String(String&& other) noexcept;
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    void input();
    void print() const;

    const char& operator[](int index) const;
    int operator()(char c) const;
    operator int() const;
};
