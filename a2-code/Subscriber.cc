#include "Subscriber.h"

Subscriber::Subscriber(const string& name, const string& creditCard): name(name), creditCard(creditCard) {
}

bool Subscriber::matches(const string& name) const {
    return this->name == name;
}

void Subscriber::print() const {
    cout << "Subscriber: " << name << " with credit card: " << creditCard << endl;
}