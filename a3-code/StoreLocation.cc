#include "StoreLocation.h"

int StoreLocation::nextId = 0;
const int StoreLocation::capacity = SLOC_CAPACITY;
const char StoreLocation::code = 'A';

StoreLocation::StoreLocation() : Location(code, ++nextId){}

void StoreLocation::setProduct(const string& product) {
    this->product = product; 
}

int StoreLocation::getFreeSpace() const {
    return capacity - quantity;
}

int StoreLocation::getCapacity() const {
    return capacity;
}

bool StoreLocation::add(const string& productName, int amount) {
    if (isAvailable() && amount <= getCapacity()){
        setProduct(productName);
        quantity += amount;
        return true;
    }
    else if(getProduct() == productName && amount + getQuantity() <= getCapacity()){
        quantity += amount;
        return true;
    }
    return false;
}

bool StoreLocation::remove(int amount){
    if (!isAvailable() && amount <= getQuantity()) {
        quantity -= amount;
        return true;
    }
    return false;
}

void StoreLocation::print() {
    cout << "StoreLocation class with id: " << id << ", product: " << product << " quantity: " << quantity << " and capacity: " << capacity << endl;

}