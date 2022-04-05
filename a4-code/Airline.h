#ifndef AIRLINE_H
#define AIRLINE_H

#include "Array.h"
#include "Part.h"
#include "Aircraft.h"

class Airline {
    public:
        Airline(const string&);
        ~Airline();
        void addAircraft(const string&, const string&);
        void addPart(const string&, int, int);
        void takeFlight(const string&, int);
        void printAircraft() const;
        void printParts() const;
        void inspectionReport(const string&, Date&) const;
        bool install(const string&, const string&, Date&);
    
    private:
        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircrafts;

        //getters
        Aircraft* getAircraft(const string&) const;
        Part* getPart(const string&) const;
};

#endif