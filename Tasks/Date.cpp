#include "Date.h"

const int Date::daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool Date::isLeapYear(int y) const {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int Date::daysInCurrentMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    return daysInMonth[m - 1];
}

int Date::toDays() const {
    int totalDays = 0;
    for (int y = 0; y < year; ++y)
        totalDays += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < month; ++m)
        totalDays += daysInCurrentMonth(m, year);
    totalDays += day;
    return totalDays;
}

void Date::fromDays(int totalDays) {
    year = 0;
    while (true) {
        int yDays = isLeapYear(year) ? 366 : 365;
        if (totalDays > yDays) {
            totalDays -= yDays;
            ++year;
        } else break;
    }
    month = 1;
    while (true) {
        int mDays = daysInCurrentMonth(month, year);
        if (totalDays > mDays) {
            totalDays -= mDays;
            ++month;
        } else break;
    }
    day = totalDays;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::nextDay() {
    *this += 1;
}

Date& Date::operator+=(int days) {
    int total = toDays() + days;
    fromDays(total);
    return *this;
}

Date& Date::operator-=(int days) {
    int total = toDays() - days;
    fromDays(total);
    return *this;
}

int Date::operator-(const Date& other) const {
    return this->toDays() - other.toDays();
}

Date& Date::operator++() {
    nextDay();
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() {
    *this -= 1;
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    return toDays() < other.toDays();
}

bool Date::operator>(const Date& other) const {
    return toDays() > other.toDays();
}

Date& Date::operator=(const Date& other) {
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
}

void Date::operator()(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.day << "." << d.month << "." << d.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& d) {
    is >> d.day >> d.month >> d.year;
    return is;
}
