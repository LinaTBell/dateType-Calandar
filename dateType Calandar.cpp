#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int month, int day, int year) {
    if (isValidDate(month, day, year)) {
        this->month = month;
        this->day = day;
        this->year = year;
    }
    else {
        // Default to 1/1/1900 if the provided date is invalid
        this->month = 1;
        this->day = 1;
        this->year = 1900;
    }
}

void Date::setDate(int month, int day, int year) {
    if (isValidDate(month, day, year)) {
        this->month = month;
        this->day = day;
        this->year = year;
    }
    else {
        cerr << "Invalid date. Setting to default (1/1/1900)." << endl;
        this->month = 1;
        this->day = 1;
        this->year = 1900;
    }
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

bool Date::isLeapYear(int year) const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int Date::getDaysInMonth(int month, int year) const {
    if (month == 2) {
        return (isLeapYear(year)) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

void Date::printDate() const {
    cout << month << "-" << day << "-" << year << endl;
}

int Date::daysPassed() const {
    int totalDays = 0;
    for (int i = 1; i < month; ++i) {
        totalDays += getDaysInMonth(i, year);
    }
    totalDays += day;
    return totalDays;
}

int Date::daysRemaining() const {
    int remainingDays = 0;
    for (int i = month + 1; i <= 12; ++i) {
        remainingDays += getDaysInMonth(i, year);
    }
    remainingDays += (getDaysInMonth(month, year) - day);
    return remainingDays;
}

void Date::setDateFromDays(int days) {
    int remainingDays = days;
    int i = 1;
    while (remainingDays > getDaysInMonth(i, year)) {
        remainingDays -= getDaysInMonth(i, year);
        ++i;
    }
    month = i;
    day = remainingDays;
}

bool Date::isValidDate(int month, int day, int year) {
    if (year < 1900)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > getDaysInMonth(month, year))
        return false;
    return true;
}
