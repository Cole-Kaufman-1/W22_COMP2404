#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
#include "Defs.h"

using namespace std;

class Location{
    
    public:
        Location(char charCode, int num);
        const string& getId() const;
        const string& getProduct() const;
        int getQuantity() const;
        bool isEmpty() const;
        bool isAvailable() const;
        virtual void print() const;
        virtual int getCapacity() const = 0;
        virtual bool add(const string& productName, int amount) = 0;
        virtual bool remove(int) = 0;
    
    protected:
        static const string& NONE;
        string id, product;
        int quantity;

};

#endif