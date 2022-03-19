#ifndef WHLOCATION_H
#define WHLOCATION_H

#include "Location.h"

class WHLocation : public Location {

    public:
        WHLocation();
        virtual int getCapacity() const;
        virtual bool add(const string& productName, int amount);
        virtual bool remove(int amount);
        virtual void print();

    private:
        static const char code;
        static const int capacity;
        static int nextId;
};

#endif