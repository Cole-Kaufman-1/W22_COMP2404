#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {

    public:
        Room(string name, int capacity, int computers, bool whiteboard);
        Room(const Room& room);

        void setName(string);
        void setCapacity(int);
        void setComputers(int);
        void setWhiteboard(bool);

        string getName();
        int getCapacity();
        int getComputers();
        bool hasWhiteboard();

        bool meetsCriteria(int capacity, int computers=INT32_MIN, bool whiteboard=0);
        bool lessThan(Room&);
        void print();

    private:
        string name;
        int capacity;
        int computers;
        bool whiteboard;

};

#endif
