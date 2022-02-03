#include <iostream>
#include <string>

//#include "Library.h"
#include "Student.h"
#include "Date.h"
#include "Room.h"

using namespace std;

int main(){
    Room r1 = Room("AB", 5, 3, 1);
    Room r2 = Room("BC", 2, 1, 0);
    Student s1 = Student("Cole", "123");
    cout<<r1.lessThan(r2)<<endl;
    cout<<r2.lessThan(r1)<<endl;
    return 0;
};