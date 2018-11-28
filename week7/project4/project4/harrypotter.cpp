/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable virtual functions that will be overriding the
 ** base Character class
 **
 ** HARRYPOTTER.CPP
 *****************************************************************/

#include "harrypotter.hpp"

/******************************************************************
 ** Harry Potter Constructor
 **
 ** Simply passes in the stats of the Harry Potter class-object and
 ** creates an object using the Character base-class as a template.
 ** Harry Potter also has a private boolean variable called hogwarts
 ** which is initialized to true.
 **
 *****************************************************************/

Harrypotter::Harrypotter() : Character("Harry Potter", 2, 6, 2, 6, 0, 10) {
    // Default Constructor for Harry Potter
    this->hogwarts = true;
}

/******************************************************************
 ** Harry Potter Destructor
 **
 ** Default destructor for program to run on exit.
 **
 *****************************************************************/

Harrypotter::~Harrypotter() {
    
}

/******************************************************************
 ** Virtual Harry Potter Defend Function
 **
 ** First we check the results of doCombat which is just calling the
 ** base-class defend function. If the result is false but Harry's hogwarts ability
 ** is still true, we set doCombat to true, and hogwarts to false. 
 ** We then set his health to 20 and print that he used his special ability
 ** to survive the killing blow. This only occurs once, however. 
 **
 *****************************************************************/


bool Harrypotter::defend(int dmgAttack) {
    
    bool doCombat = Character::defend(dmgAttack);
    
    if(doCombat == false && hogwarts == true) {
        hogwarts = false;
        doCombat = true;
        strength = 20;
        cout << this->getName() << " [" << this->getType() << "] " << "was slain but managed to use ~~HOGWARTS~~. He came back to life with 20 hitpoints - wicked!" << endl;
    }
    
    return doCombat;
    
    

}
