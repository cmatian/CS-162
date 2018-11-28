/*************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Re-useable functions for program input validation
 *************************************************************************/

#include "validation.hpp"

// Validation Function for single input integers
bool validateOne(int value) {
    if (value > 0 && value % 1 == 0) {
        return true;
    } else {
        return false;
    }
}

// Validation Function to make sure the user enters a number between or equal to a min or a max value.
bool validateBounds(int input, int min, int max) {
    if (input >= min && input <= max) {
        return true;
    } else {
        return false;
    }
}
