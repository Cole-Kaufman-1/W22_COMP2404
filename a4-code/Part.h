#ifndef PART_H
#define PART_H

#include <string>
#include "Date.h"

using namespace std;

class Part {
    friend ostream& operator<<(ostream&, const Part&);
    public:
        Part(string);
        virtual ~Part();
        const string& getName() const;
        void addFlightHours (int);
        void install(Date&);
        virtual bool inspection(Date&) const = 0;
        
    protected:
        virtual void print(ostream&) const;
        int flightHours;
        Date installationDate;
        string name;
};

class FH_Part : virtual public Part {
    public:
        FH_Part(string, int);
        virtual ~FH_Part();
        virtual bool inspection(Date&) const;
        
    protected:
        virtual void print(ostream&) const;
        int fh_inspect;
};

class IT_Part : virtual public Part {
    public:
        IT_Part(string, int);
        virtual ~IT_Part();
        virtual bool inspection(Date&) const;
        
    protected:
        virtual void print(ostream&) const;
        int it_inspect;
};

class FHIT_Part : public FH_Part, public IT_Part {
    public:
        FHIT_Part(string, int, int);
        virtual ~FHIT_Part();
        virtual bool inspection(Date&) const;
    
    protected:
        virtual void print(ostream&) const;
};
#endif