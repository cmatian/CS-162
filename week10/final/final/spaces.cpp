/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for spaces functions. Only contains
 ** two functions for setting the name of the room and a
 ** function for retrieving the name.
 **
 ** SPACES.CPP
 *****************************************************************/

#include "spaces.hpp"

/******************************************************************
 ** Space Constructor
 **
 ** Abstract class for space that serves as a template for other
 ** derived classes.
 **
 *****************************************************************/

Space::Space(string n ) {
    
    name = n;
    
}

/******************************************************************
 ** Space Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Space::~Space() {
    
}

/******************************************************************
 ** getRoom();
 **
 ** Returns the room that the player is in. Determined mostly
 ** by the derived class.
 **
 *****************************************************************/

string Space::getRoom() {
    
    return name;
    
}






