#include "Location.h"

const string& Location::NONE = "Empty";

Location::Location(char charCode, int num): product("Empty"), quantity(0){
    id = charCode + to_string(num);
}

const string& Location::getId() const {
    return id;
}

const string& Location::getProduct() const {
    return product;
}

int Location::getQuantity() const {
    return quantity;
}

bool Location::isEmpty() const {
    return quantity == 0;
}

bool Location::isAvailable() const {
    return product == NONE;
}

void Location::print() const {
    cout << "Location class with id: " << id << ", product: " << product << " and quantity: " << quantity << endl;
}