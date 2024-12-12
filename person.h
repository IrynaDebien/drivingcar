#pragma once
#include <iostream>
#include <cstring>
#include <windows.h>

class Person {
    int age;
    char* name;

    void createString(char*& destination, const char* source);

public:
    Person();
    Person(const char* name, int age);
    Person(const Person& p);
    ~Person();

    const char* getName() const;
    int getAge() const;

    void setName(const char* newName);
    void setAge(int newAge);
    void display() const;

    Person& operator=(const Person& p);
};


