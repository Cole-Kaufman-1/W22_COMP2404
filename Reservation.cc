#include "Reservation.h"

Reservation::Reservation(Student* s, Room* r, Date& d) {
    student = s;
    room = r;
    date.setDate(d);
    cout<< "In reservations cstor"<<endl;
    print();
}

Student* Reservation::getStudent() {
    return student;
}

Room* Reservation::getRoom() {
    return room;
}

Date Reservation::getDate(){
    return date;
}

bool Reservation::lessThan(Reservation& r){
    return date.lessThan(r.date);
}

bool Reservation::overlaps(const string& r, Date& d) {
    if (r == room->getName() && date.overlaps(d)){
        return true;
    }
    return false;
}

void Reservation::print() {
    cout<< "Reservation for : \n\t";
    student->print();
    cout<< "On: \n\t";
    date.print();
    cout<< "In room: \n\t";
    room->print();
}