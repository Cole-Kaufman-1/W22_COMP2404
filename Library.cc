#include "Library.h"

Library::Library() {
    numStudents = 0;
    numRooms = 0;
    numReservations = 0;
    students = new Student*[MAX_ARR_SIZE];
    reservations = new Reservation*[MAX_ARR_SIZE];
}

Library::~Library(){
    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }
    delete [] students;

    for (int i = 0; i < numReservations; ++i) {
        delete reservations[i];
    }
    delete [] reservations;

    
    for (int i = 0; i < numRooms; ++i) {
        delete rooms[i];
    }
}

bool Library::addStudent(const string& name, const string& number) {
    if (numStudents >= MAX_ARR_SIZE){
        return false;
    }
    students[numStudents] = new Student(name, number);
    ++numStudents;
    return true;
}

bool Library::addRoom(string name, int capacity, int computers, bool whiteboard) {
    if (numRooms >= MAX_ARR_SIZE){
        return false;
    }
    rooms[numRooms] = new Room(name, capacity, computers, whiteboard);
    ++numRooms;
    return true;
}

bool Library::getStudent(const string& name, Student** student){
    for (int i = 0; i < numStudents; ++i){
        if(name == students[i]->getName()){
            student = &students[i];
            return true;
        }
    }
    return false;
}

bool Library::getRoom(const string& roomName, Room** room) {
    for (int i = 0; i < numRooms; ++i){
        if(roomName == rooms[i]->getName()){
            room = &rooms[i];
            return true;
        }
    }
    return false;
}

bool Library::isFree(const string& room, Date& d){
    Room* tempRoom;
    if(getRoom(room, &tempRoom)){
        for (int i = 0; i < numReservations; i++) {
            if (reservations[i]->getRoom()->getName().compare(room) && reservations[i]->overlaps(room, d)){
                return false;
            }
        }

        return true;
    }
    return false;
}

bool Library::makeReservation(const string& student, const string& room, Date& d){
    Room* tempRoom;
    Student* tempStudent;
    if (getRoom(room, &tempRoom) && getStudent(student, &tempStudent)){
        if(isFree(room, d) && numReservations < MAX_ARR_SIZE){
            Room r1 = Room(*tempRoom);
            Student s1 = Student(*tempStudent);
            reservations[numReservations] = new Reservation(tempStudent, tempRoom, d);
            ++numReservations;
            return true;
        }
    }
    return false;
}


