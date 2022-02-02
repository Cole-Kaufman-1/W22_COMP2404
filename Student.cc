#include "Student.h"

Student::Student(){
    setName("Default Value");
    setNumber("0");
}

Student::Student(string name, string number) {
    setName(name);
    setNumber(number);
}

void Student::setName(string n) {
    name = n;
}

void Student::setNumber(string num) {
    number = num;
}

string Student::getName(){
    return name;
}

string Student:: getNumber() {
    return number;
}

bool Student::lessThan(Student& s) {
    return this->number < s.number;
}