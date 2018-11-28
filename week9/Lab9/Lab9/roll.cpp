/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for simulating random rolls
 **
 ** ROLL.CPP
 *****************************************************************/

#include "roll.hpp"


/******************************************************************
 ** roll() function
 **
 ** Roll function takes in a min and max and uses the mersenne 
 ** twister random engine to generate a number between the min
 ** and max values. Returns that value.
 **
 *****************************************************************/

int roll( int min, int max) {
    int roll;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    
    roll = dis(gen);

    return roll;
}
