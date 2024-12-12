#pragma once
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Date {
    int day;
    int month;
    int year;
    char* monthString;

    void createString(char*& destination, const char* source);

public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& d);
    ~Date();

    const char* getMonthString() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setMonthString(const char* newString);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void constTest(Date& dt) const;
    void display() const;

    Date& operator=(const Date& d);
};