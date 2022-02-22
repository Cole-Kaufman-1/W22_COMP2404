#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>
using namespace std;

class Subscriber {
    public:
        Subscriber(const string&, const string&);
        bool matches(const string&) const;
        void print() const;

    private:
        const string name, creditCard;
};

#endif