#include "Room.h"

Room::Room(string n, int cap, int comp, bool wb) {
    name = n;
    capacity = cap;
    computers = comp;
    whiteboard = wb;
}

Room::Room(const Room& r){
    name = r.name;
    capacity = r.capacity;
    computers = r.computers;
    whiteboard = r.whiteboard;
}

void Room::setName(string n){
    name = n;
}

void Room::setCapacity(int c) {
    capacity = c;
}

void Room::setComputers(int c) {
    computers = c;
}

void Room::setWhiteboard(bool w){
    whiteboard = w;
}

string Room::getName(){
    return name;
}

int Room::getCapacity(){
    return capacity;
}

int Room::getComputers(){
    return computers;
}

bool Room::hasWhiteboard() {
    return whiteboard;
}

bool Room::meetsCriteria(int capacity, int computer, bool whiteboard){
    return (this->capacity >= capacity) && (this->computers >= computer) && (this->whiteboard >= whiteboard);
}

bool Room::lessThan(Room& r) {
    return this->name < r.name; 
}

void Room::print(){
    string wb = "no whiteboard";
    if(hasWhiteboard){
        wb = "a whiteboard";
    }
    cout<< "Room " << name << " has a capacity of " << capacity << " with " << computers << " computers and " << wb << endl;  
}