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
 ** Virtual Bluemen Destructor
 **
 ** Gets rid of makefile pedantic errors
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
    
    // We then look through their strength levels and the number of dice that they have.
    // If the health is below or equal to a certain value AND the dice equal to a certain value, we decrement the total defense dice by 1.
    // The reason we need to compare against the total value of dice is so the function doesn't run each time it finds they're below 8 or 4 strength.
    // It will only run when dice meet the criteria in addition to the strength criteria.
    
    if(strength <= 8 && defDice[0] == 3) {
        defDice[0]--;
        cout << "Due to the ~~MOB~~ special ability, the Bluemen have lost a blue man and their defense has been reduced to 2D6!" << endl;
    }
    
    if(strength <= 4 && defDice[0] == 2) {
        defDice[0]--;
        cout << "Due to the ~~MOB~~ special ability, the Bluemen have lost a blue man and their defense has been reduced to 1D6!" << endl;
    }
    
    // Return the result of the combat.
    return doCombat;
}
