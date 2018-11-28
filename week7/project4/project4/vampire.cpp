/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable virtual functions that will be overriding the
 ** base Character class
 **
 ** VAMPIRE.CPP
 *****************************************************************/

#include "vampire.hpp"

/******************************************************************
 ** Vampire Constructor
 **
 ** Simply passes in the stats of the Vampire class-object and 
 ** creates an object using the Character base-class as a template.
 **
 *****************************************************************/

Vampire::Vampire() : Character("Vampire", 1, 12, 1, 6, 1, 18) {
    // Default Constructor for Vampire
}

/******************************************************************
 ** Vampire Destructor
 **
 ** Default destructor for program to run on exit.
 **
 *****************************************************************/

Vampire::~Vampire() {
    
}


/******************************************************************
 ** Virtual Vampire Defend Function
 **
 ** The vampire function has a 50% chance of completely avoiding
 ** any attacks, so we roll for a value of 1 or 2. If it's 1, 
 ** nothing happens and we alert the user that the vampire used his
 ** charm ability and avoided damage. Otherwise, we run the base-class 
 ** defend function and return the result of that function.
 **
 *****************************************************************/

bool Vampire::defend(int dmgAttack) {
    
    int roll;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 2);
    
    roll = dis(gen);
    
    
    if (roll == 1) {
        cout << this->getName() << " [" << this->getType() << "] " << "has " << this->getStrength() << " strength." << endl << endl;
        cout << this->getName() << " [" << this->getType() << "] " << "used ~~CHARM~~ and completely avoided taking damage." << endl << endl;
        cout << this->getName() << " [" << this->getType() << "] " << "has " << this->getStrength() << " strength remaining." << endl << endl;
        
        return true;
        
    } else {
        
        return Character::defend(dmgAttack);
        
    }
}
