#include "WHLocation.h"

int WHLocation::nextId = 0;
const int WHLocation::capacity = WHLOC_CAPACITY;
const char WHLocation::code = 'B';

WHLocation::WHLocation(): Location(code, ++nextId){}

int WHLocation::getCapacity() const {
    return capacity;
}

bool WHLocation::add(const string& productName, int amount) {
    if (isAvailable() && amount <= getCapacity()){
        product = productName;
        quantity += amount;
        return true;
    }
    return false;
}

bool WHLocation::remove(int amount) {
    if (!isAvailable() && amount <= getQuantity()) {
        quantity -= amount;
        if (quantity == 0) {
            product = NONE;
        }
        return true;
    }
    return false;
}

void WHLocation::print() {
    cout << "WHLocation class with id: " << id << ", product: " << product << " quantity: " << quantity << " and capacity: " << capacity << endl;

}
