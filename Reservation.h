#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Date.h"

class Reservation {

    public:
        Reservation(Student* student, Room* room, Date& date);

        Student* getStudent();
        Room* getRoom();
        Date getDate();

        bool lessThan(Reservation& res);
        bool overlaps(const string& r, Date& d);
        void print();
        
    private:
        Student* student;
        Room* room;
        Date date;
};

#endif