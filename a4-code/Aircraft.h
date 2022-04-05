#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include "Part.h"
#include "Array.h"

using namespace std;

class Aircraft {
    friend ostream& operator<<(ostream&, const Aircraft&);
    public:
        Aircraft(const string&, const string&);
        const string& getRegistration() const;
        void install(Part*, Date&);
        void takeFlight(int);
        void inspectionReport(Date&, Array<Part*>*) const;

    private:
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts;
};

#endif