#include "date.h"

using namespace std;

void Date::createString(char*& destination, const char* source) {
    int length = strlen(source);
    destination = new char[length + 1];
    strcpy_s(destination, length + 1, source);
}

Date::Date() : day(0), month(0), year(0), monthString(nullptr) {
    createString(monthString, "Unknown");
    cout << "Date constructor()" << endl;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y), monthString(nullptr) {
    createString(monthString, "Mon");
    cout << "Date constructor(int d, int m, int y)" << endl;
}

Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year), monthString(nullptr) {
    createString(monthString, d.monthString);
    cout << "Copy constructor Date(const Date& d)" << endl;
}

Date::~Date() {
    if (monthString != nullptr) {
        delete[] monthString;
        monthString = nullptr;
    }
    cout << "Destructor called" << endl;
}

const char* Date::getMonthString() const { return monthString; }
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setMonthString(const char* newString) {
    if (monthString != nullptr) {
        delete[] monthString;
    }
    createString(monthString, newString);
}

void Date::setDay(int newDay) {
    if (newDay > 0) {
        day = newDay;
    }
}

void Date::setMonth(int newMonth) {
    if (newMonth > 0) {
        month = newMonth;
    }
}

void Date::setYear(int newYear) {
    if (newYear > 0) {
        year = newYear;
    }
}

void Date::constTest(Date& dt) const {
    dt.day = 1;
    dt.month = 1;
    dt.year = 1;
}

void Date::display() const {
    cout << day << " / " << month << " / " << year << endl;
}

Date& Date::operator=(const Date& d) {
    if (this == &d) return *this;
    if (monthString != nullptr) {
        delete[] monthString;
    }
    day = d.day;
    month = d.month;
    year = d.year;
    createString(monthString, d.monthString);
    return *this;
}
