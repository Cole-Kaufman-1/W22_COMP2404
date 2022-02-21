#include "Student.h"

Student::Student(){
    name = "Default Value";
    number = "0";
}

Student::Student(string n, string num) {
    name = n;
    number = num;
}

Student::Student(const Student& s){
    name = s.name;
    number = s.number;
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

void Student::print() {
    cout<<"Student name: " << getName() << " Student number: " << getNumber() <<endl;
}