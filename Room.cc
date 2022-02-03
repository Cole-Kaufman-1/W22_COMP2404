#include "Room.h"

Room::Room(string name, int capacity, int computers, bool whiteboard) {
    setName(name);
    setCapacity(capacity);
    setComputers(computers);
    setWhiteboard(whiteboard);
}

Room::Room(const Room& r){
    setName(r.name);
    setCapacity(r.capacity);
    setComputers(r.computers);
    setWhiteboard(r.whiteboard);
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

bool Room::lessThan(Room& s) {
    return this->name < s.name; 
}

void Room::print(){
    string wb = "no whiteboard";
    if(hasWhiteboard){
        wb = "a whiteboard";
    }
    cout<< "Room " << getName() << " has a capacity of " << getCapacity() << " with " << getComputers() << " computers and " << wb << endl;  
}