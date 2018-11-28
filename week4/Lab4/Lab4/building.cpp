/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for the Building class
 **
 ** BUILDING.CPP
 *****************************************************************/

#include "building.hpp"

// Building Constructor
Building::Building(string name, int size, string address) {
    this->name = name;
    this->size = size;
    this->address = address;
}

// Destructor unusued
Building::~Building() {
    
}

// Get the Building Name
string Building::bName() {
    return name;
}

// Get the Building Size
int Building::bSize() {
    return size;
}

// Get the building Address
string Building::bAddress() {
    return address;
}
