#pragma once
#include <iostream>
#include <cstring>
#include <windows.h>
#include "date.h"
#include "person.h"

class DriverLicense {
    const double max_speed;
    int speed_violations;
    Date date;
    Person* owner;

public:
    DriverLicense();
    DriverLicense(int violations, double speed, const Date& date, const Person& person);
    ~DriverLicense();

    void setDate(const Date& newDate);
    void setOwner(const Person& newOwner);
    void setSpeedViolations(int violations);

    const Date& getDate() const;
    Person& getOwner() const;
    int getSpeedViolations() const;
    double getMaxSpeed() const;

    void display() const;
};


