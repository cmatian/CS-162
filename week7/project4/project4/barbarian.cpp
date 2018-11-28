/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable virtual functions that will be overriding the
 ** base Character class
 **
 ** BARBARIAN.CPP
 *****************************************************************/

#include "barbarian.hpp"

/******************************************************************
 ** Barbarian Constructor
 **
 ** Simply passes in the stats of the Barbarian class and
 ** creates an object using the Character base-class as a template.
 **
 *****************************************************************/

Barbarian::Barbarian() : Character("Barbarian", 2, 6, 2, 6, 0, 12) {
    // Default Constructor for Barbarian
}

/******************************************************************
 ** Barbarian Destructor
 **
 ** Default destructor for program to run on exit.
 **
 *****************************************************************/

Barbarian::~Barbarian() {
    
}
