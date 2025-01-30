#include "addressType.h"
#include <iostream>

addressType::addressType(string street, string city, string state, int zip)
    : streetAddress(street), city(city), state(state), zipCode(zip) {}

void addressType::setAddress(string street, string city, string state, int zip) {
    streetAddress = street;
    city = city;
    state = state;
    zipCode = zip;
}

void addressType::printAddress() const {
    cout << streetAddress << ", " << city << ", " << state << " " << zipCode << endl;
}
