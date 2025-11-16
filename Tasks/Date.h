#pragma once
#include <iostream>

class Date {
private:
    int day, month, year;
    static const int daysInMonth[12];

    bool isLeapYear(int y) const;
    int daysInCurrentMonth(int m, int y) const;
    int toDays() const;
    void fromDays(int totalDays);

public:
    explicit Date(int d = 1, int m = 1, int y = 0);

    void nextDay();

    Date& operator+=(int days);
    Date& operator-=(int days);

    int operator-(const Date& other) const;

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    Date& operator=(const Date& other);
    void operator()(int d, int m, int y);

    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};
