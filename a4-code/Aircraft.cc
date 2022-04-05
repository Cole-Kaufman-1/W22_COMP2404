#include "Aircraft.h"

ostream& operator<<(ostream& os, const Aircraft& a){
    os << "Aircraft: " << a.type << endl << "Registration: " << a.registration << endl;
    return os;
}

Aircraft::Aircraft(const string& t, const string& reg) : type(t), registration(reg) {}

// check if needed after
Aircraft::~Aircraft() {
    for (int i = 0; i < parts.getSize(); i++){
        delete parts[i];
    }
}

const string& Aircraft::getRegistration() const {
    return registration;
}

void Aircraft::install(Part* pt, Date& d){
    if (pt == NULL) return;
    pt->install(d);
    parts.add(pt);
}

void Aircraft::takeFlight(int hours) {
    if (hours < 1) return;
    flighthours += hours;
    for (int i = 0; i < parts.getSize(); i++) {
        parts[i]->addFlightHours(hours);
    } 
}

void Aircraft::inspectionReport(Date& d, Array<Part*> *toInspect) {
    for (int i = 0; i < parts.getSize(); i++) {
        if (parts[i]->inspection(d)){
            toInspect->add(parts[i]);
        }
    } 
}
