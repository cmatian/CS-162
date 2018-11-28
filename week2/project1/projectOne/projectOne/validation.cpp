/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Reuseable function to be used for input validation
 *************************************************************************/

#include "validation.hpp"

// Validation Function for ONE integer that is above a value of 0.
// Returns True or False depending on whether or not the input is an integer.
bool validX(int param) {
    // Uses modulo operator to quickly determine whether the value is an integer or not.
    if (param > 0 && param % 1 == 0) {
        return true;
    } else {
        return false;
    }
}

// These validator functions differs slightly in that it allows for inputs of 0. This needs to be used for when we let the user set the Ant's XY position because
// 0, 0 is a completely valid input for the Ant position - but the validX() function above would flag it as an invalid input.
// Also, the param ensures that the input the user makes is LESS than the maximum height and width of the game board.
// I originally failed to check for this input and ended up with a segfault when I inputted something out of bounds. 
bool validW(int param, int width) {
    if (param >=  0 && param % 1 == 0 && param < width) {
        return true;
    } else {
        return false;
    }
}

bool validH(int param, int height) {
    if (param >=  0 && param % 1 == 0 && param < height) {
        return true;
    } else {
        return false;
    }
}


