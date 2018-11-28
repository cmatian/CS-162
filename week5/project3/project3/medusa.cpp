/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable virtual functions that will be overriding the
 ** base Character class
 **
 ** MEDUSA.CPP
 *****************************************************************/

#include "medusa.hpp"

/******************************************************************
 ** Medusa Constructor
 **
 ** Simply passes in the stats of the Medusa class-object and
 ** creates an object using the Character base-class as a template.
 **
 *****************************************************************/

Medusa::Medusa() : Character("Medusa", 2, 6, 1, 6, 3, 8) {
    // Default Constructor for Medusa
}

/******************************************************************
 ** Virtual Medusa Destructor
 **
 ** Gets rid of makefile pedantic errors
 **
 *****************************************************************/

Medusa::~Medusa() {
    
}

/******************************************************************
 ** Virtual Medusa Attack Function
 **
 ** Medusa's attack function simply grabs the result of the base-class
 ** attack function, and stores it into a variable. We then check the value of the 
 ** variable and if it's 12 we abstract the glare ability as doing lots of damage.
 ** The damage will kill most characters except those like the Vampire 
 ** or Harry Potter who have special survival abilities.
 **
 *****************************************************************/

int Medusa::attack() {
    // Medusa makes an attack and we pull in her value to a variable.
    int medusaAttack = Character::attack();
    
    // If the attack is equal to 12 we set her attack to 50 and return that result
    // We are abstracting Medusa's Glare ability as doing an enormous amount of damage that _most_ characters cannot survive.
    if (medusaAttack == 12) {
        cout << "Medusa rolled a total of 12 with both dice and successfully used her ~~GLARE~~ ability. Avert your gaze - quickly!" << endl;
        medusaAttack = 50;
    }
    
    // Return the attack damage
    return medusaAttack;
    
}
