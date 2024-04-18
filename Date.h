#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month;
    int day;
    int year;

    bool isValidDate(int month, int day, int year);

public:
    Date(int month = 1, int day = 1, int year = 1900);

    void setDate(int month, int day, int year);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    bool isLeapYear(int year) const;
    int getDaysInMonth(int month, int year) const;
    void printDate() const;
    int daysPassed() const;
    int daysRemaining() const;
    void setDateFromDays(int days);
};

#endif // DATE_H