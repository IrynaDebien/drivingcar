#include <windows.h>
#include "date.h"
#include "person.h"
#include "driverlicense.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DriverLicense defaultLicense;
    defaultLicense.display();

    Date newDate(1, 1, 2025);
    defaultLicense.setSpeedViolations(3);
    defaultLicense.setDate(newDate);

    Person newPerson("Ivanov", 30);
    defaultLicense.setOwner(newPerson);

    cout << "Updated values:" << endl;
    cout << "Speed violations: " << defaultLicense.getSpeedViolations() << endl;
    cout << "Max speed: " << defaultLicense.getMaxSpeed() << endl;
    defaultLicense.getDate().display();
    cout << "Owner's name: " << defaultLicense.getOwner().getName() << ", Owner's age: " << defaultLicense.getOwner().getAge() << endl;

    return 0;
}
