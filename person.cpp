#include "person.h"

using namespace std;

void Person::createString(char*& destination, const char* source) {
    int length = strlen(source);
    destination = new char[length + 1];
    strcpy_s(destination, length + 1, source);
}

Person::Person() : age(0), name(nullptr) {
    createString(name, "Unknown");
    cout << "Person constructor()" << endl;
}

Person::Person(const char* name, int age) : age(age), name(nullptr) {
    createString(this->name, name);
    cout << "Person constructor(const char* name, int age)" << endl;
}

Person::Person(const Person& p) : age(p.age), name(nullptr) {
    createString(name, p.name);
    cout << "Copy constructor Person(const Person& p)" << endl;
}

Person::~Person() {
    if (name != nullptr) {
        delete[] name;
        name = nullptr;
    }
    cout << "Destructor called" << endl;
}

const char* Person::getName() const { return name; }
int Person::getAge() const { return age; }

void Person::setName(const char* newName) {
    if (name != nullptr) {
        delete[] name;
    }
    createString(name, newName);
}

void Person::setAge(int newAge) {
    if (newAge > 0) {
        age = newAge;
    }
}

void Person::display() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}

Person& Person::operator=(const Person& p) {
    if (this == &p) return *this;
    if (name != nullptr) {
        delete[] name;
    }
    age = p.age;
    createString(name, p.name);
    return *this;
}
