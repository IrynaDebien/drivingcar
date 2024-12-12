#include "driverlicense.h"


DriverLicense::DriverLicense() : max_speed(0.0), speed_violations(0), date(), owner(new Person()) {
    cout << "DriverLicense constructor()" << endl;
}

DriverLicense::DriverLicense(int violations, double speed, const Date& date, const Person& person)
    : max_speed(speed), speed_violations(violations), date(date), owner(new Person(person)) {
    cout << "DriverLicense constructor(int violations, double speed, const Date& date, const Person& person)" << endl;
}

DriverLicense::~DriverLicense() {
    delete owner;
    cout << "DriverLicense destructor()" << endl;
}

void DriverLicense::setDate(const Date& newDate) {
    date = newDate;
}

void DriverLicense::setOwner(const Person& newOwner) {
    if (owner != nullptr) {
        delete owner;
    }
    owner = new Person(newOwner);
}

void DriverLicense::setSpeedViolations(int violations) {
    speed_violations = violations;
}

const Date& DriverLicense::getDate() const { return date; }
Person& DriverLicense::getOwner() const { return *owner; }
int DriverLicense::getSpeedViolations() const { return speed_violations; }
double DriverLicense::getMaxSpeed() const { return max_speed; }

void DriverLicense::display() const {
    cout << "Speed violations: " << speed_violations << endl;
    cout << "Max speed: " << max_speed << endl;
    date.display();
    owner->display();
}
