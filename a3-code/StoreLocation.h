#ifndef STORELOCATION_H
#define STORELOCATION_H

#include "Location.h"

class StoreLocation : public Location {

    public:
        StoreLocation();
        void setProduct(const string& product);
        int getFreeSpace() const;
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
