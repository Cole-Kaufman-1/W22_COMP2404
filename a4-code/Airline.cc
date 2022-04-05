#include "Airline.h"

Airline::Airline(const string& name) : name(name) {}

Airline::~Airline() {
    for (int i = 0; i < parts.getSize(); i++) {
        delete parts[i];
    }
    for (int j = 0; j < aircrafts.getSize(); j++){
        delete aircrafts[j];
    }
}

Aircraft* Airline::getAircraft(const string& reg) const{
    for (int i = 0; i < aircrafts.getSize(); i++){
        if(aircrafts[i]->getRegistration().compare(reg) == 0){
            return aircrafts[i];
        }
    }
    return 0;
}

Part* Airline::getPart(const string& name) const{
    for (int i = 0; i < parts.getSize(); i++){
        if(parts[i]->getName().compare(name) == 0){
            return parts[i];
        }
    }
    return 0;
}

void Airline::addAircraft(const string& type, const string& reg) {
    Aircraft *newAircraft = new Aircraft(type, reg);
    aircrafts.add(newAircraft);
}


void Airline::addPart(const string& part, int fh_inspect, int it_insepct) {
    if(fh_inspect && it_insepct){
        FHIT_Part *newPart = new FHIT_Part(part, fh_inspect , it_insepct);
        parts.add(newPart);
    }
    else if(fh_inspect != 0 && it_insepct == 0){
        FH_Part *newPart = new FH_Part(part, fh_inspect);
        parts.add(newPart);
    }
    else {
        IT_Part *newPart = new IT_Part(part, it_insepct);
        parts.add(newPart);
    }
}

void Airline::takeFlight(const string& reg, int hours) {
    Aircraft *tmpAircraft = getAircraft(reg);
    if (tmpAircraft == NULL){
        cerr<<"In takeFlight: Aircraft with registration " << reg << " does not exist." << endl;
        return;
    }
    tmpAircraft->takeFlight(hours);
}

void Airline::printAircraft() const{
    for (int i = 0; i < aircrafts.getSize(); i++){
        cout << *aircrafts[i];
    }
}

void Airline::printParts() const{
     for (int i = 0; i < parts.getSize(); i++){
        cout << *parts[i] << endl;
    }
}

void Airline::inspectionReport(const string& reg, Date& d) const{
    Aircraft *tmpAircraft;
    tmpAircraft = getAircraft(reg);
    if (tmpAircraft == NULL){
        cerr<<"In inspectionReport: Aircraft with registration " << reg << " does not exist." << endl;
        return;
    }
    Array<Part*> toInspect;
    tmpAircraft->inspectionReport(d, &toInspect);
    // customize print since we only want to print parts requiring inspection
    cout << "The following parts from " << tmpAircraft->getRegistration() << " require inspection:" << endl;
    for (int i = 0; i < toInspect.getSize(); i++){
        cout << *toInspect[i] << endl;
    }
    cout << endl;
}

bool Airline::install(const string& reg, const string& partName, Date& d) {
    Aircraft *tmpAircraft = getAircraft(reg);
    if (tmpAircraft == NULL){
        cerr<<"In install: Aircraft with registration " << reg << " does not exist." << endl;
        return false;
    }
    Part *tmpPart = getPart(partName);
    if (tmpPart == NULL){
        cerr<<"In install: Part with name " << name << " does not exist." << endl;
        return false;
    }
    tmpAircraft->install(tmpPart, d);
    return true;
}

void Airline::print() const{
    cout << "Airline : "  << name << " has Aircrafts: " << endl;
    printAircraft();
    cout << " and Parts: " << endl;
    printParts();
}