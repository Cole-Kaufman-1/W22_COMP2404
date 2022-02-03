#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {

    public:
        Student();
        Student(string name, string number);
        Student(const Student&);

        void setName(string);
        void setNumber(string);

        string getName();
        string getNumber(); 

        bool lessThan(Student&);
        void print();

    private:
        string name;
        string number;
};

#endif