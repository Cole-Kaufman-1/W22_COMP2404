#include "Part.h"
#include <cmath>

ostream& operator<<(ostream& os, const Part& p){
    p.print(os);
    return os;
}

Part::Part(string n) : name(n), flightHours(0) {}

Part::~Part() {}

const string& Part::getName() const{
    return name;
}

void Part::addFlightHours(int hrs) {
    flightHours += hrs;
}

void Part::install(Date& d) {
    installationDate = d;
}

void Part::print(ostream& os) const{
        os << name << endl <<  "Hours of flight: " << flightHours << endl << "Installed on: " << installationDate;
}

FH_Part::FH_Part(string n, int flightHrs): fh_inspect(flightHrs), Part(n){}

FH_Part::~FH_Part() {};

bool FH_Part::inspection(Date& d) const{
    return flightHours >= fh_inspect;
}

void FH_Part::print(ostream& os) const{
    os <<"FH_Part: ";
    Part::print(os);
    os << "Must be inspected after " << fh_inspect << " hours" << endl ;
}

IT_Part::IT_Part(string n, int timeInstalled) : it_inspect(timeInstalled) , Part(n) {}

IT_Part::~IT_Part() {};

bool IT_Part::inspection(Date& d) const{
    return abs(d.toDays() - installationDate.toDays()) >= it_inspect;
}

void IT_Part::print(ostream& os) const{
    os <<"IT_Part: ";
    Part::print(os);
    os << "Must be inspected after " << it_inspect << " days installed" << endl;
}

FHIT_Part::FHIT_Part(string n, int flightHrs, int timeInstalled) : FH_Part(n, flightHrs), IT_Part(n, timeInstalled), Part(n) {}

FHIT_Part::~FHIT_Part() {};

bool FHIT_Part::inspection(Date& d) const{
    return (FH_Part::inspection(d) || IT_Part::inspection(d));
}

void FHIT_Part::print(ostream& os) const{
    os <<"FHIT_Part: ";
    Part::print(os);
    os << "Must be inspected after " << fh_inspect << " hours" << endl << "Must be inspected after " << it_inspect << " days installed" << endl;
}