#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_ARR_SIZE 100

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Reservation.h"
#include "Date.h"

using namespace std;

class Library {

    public:
        Library();
        ~Library();

        bool addStudent(const string& name, const string& number);
        bool addRoom(string name, int capacity=1, int computers=0, bool whiteboard=false);
        bool getStudent(const string& name, Student** student);
        bool getRoom(const string& roomName, Room** room);
        bool isFree(const string&, Date&);
        bool makeReservation(const string& student, const string& room, Date&);
        //void update(Date&) implement for bonus marks if enough time
        
    private:
        Student** students;
        Room* rooms[MAX_ARR_SIZE];
        Reservation** reservations;
        int numStudents;
        int numRooms;
        int numReservations;
};

#endif