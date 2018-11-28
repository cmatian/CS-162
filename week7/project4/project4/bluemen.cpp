/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable virtual functions that will be overriding the
 ** base Character class
 **
 ** BLUEMEN.CPP
 *****************************************************************/

#include "bluemen.hpp"

/******************************************************************
 ** Bluemen Constructor
 **
 ** Simply passes in the stats of the Bluemen class-object and
 ** creates an object using the Character base-class as a template.
 **
 *****************************************************************/

Bluemen::Bluemen() : Character("Blue Men", 2, 10, 3, 6, 3, 12) {
    // Default Constructor for Bluemen
}

/******************************************************************
 ** Bluemen Destructor
 **
 ** Default destructor for program to run on exit.
 **
 *****************************************************************/

Bluemen::~Bluemen() {
    
}

/******************************************************************
 ** Virtual Bluemen Defend Function
 **
 ** The bluemen virtual function is explained in greater detail below.
 ** Simply put, I needed a means to reduce the Bluemen's dice when they
 ** fell below a certain strength threshold.
 **
 *****************************************************************/


bool Bluemen::defend(int dmgAttack) {
    
    // If Bluemen don't go first we need to first calculate whether they've taken damage.
    bool doCombat = Character::defend(dmgAttack);
    
    // Refactored Bluemen defend function to simply set the dice rather than decrement it. Decrementing the values was really
    // pointless and could lead to unintended behavior in the program.
    
    if(strength < 9 && strength > 4) {
        defDice[0] = 2;
        
        cout << "Due to the ~~MOB~~ special ability, the Bluemen have lost a blue man and their defense has been reduced to 2D6!" << endl;
        
    }
    
    else if(strength < 5) {
        
        defDice[0] = 1;
        
        cout << "Due to the ~~MOB~~ special ability, the Bluemen have lost a blue man and their defense has been reduced to 1D6!" << endl;
        
    }
    
    // Return the result of the combat.
    return doCombat;
}

/******************************************************************
 ** Virtual Bluemen Restore Function
 **
 ** Overrides the Character recovery function and ensures that
 ** the Bluemen defense dice are restored if and when they meet
 ** certain strength thresholds.
 **
 *****************************************************************/


void Bluemen::restore() {
    
    // Restore health to Bluemen
    Character::restore();
    
    // If the strength is less than 9 but greater than 4 set defDice to 2.
    if ( strength < 9 && strength > 4) {
        
        defDice[0] = 2;
        
    // If the strength is less than 5 we set the defDice to 1.
    } else if ( strength < 5 ) {
        
        defDice[0] = 1;
        
        
    // Otherwise the strength is at or near the max strength value and we set defDice back to 3.
    } else {
        
        defDice[0] = 3;
        
    }
    
    
}

