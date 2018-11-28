/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable virtual functions that can be overwritten by
 ** derived character classes
 **
 ** CHARACTER.CPP
 *****************************************************************/

#include "character.hpp"

/******************************************************************
 ** Abstract Character Class
 **
 ** This class creates an object that accepts the type,
 ** # of attack dice, attack dice sides, # of defense dice, defense dice sides,
 ** armor, and strength. This parameters are overridden by the derived classes.
 **
 *****************************************************************/

Character::Character(string type, int atkDiceNum, int atkDiceSide, int defDiceNum, int defDiceSide, int armor, int strength) {
    this->type = type;
    this->atkDice[0] = atkDiceNum;
    this->atkDice[1] = atkDiceSide;
    this->defDice[0] = defDiceNum;
    this->defDice[1] = defDiceSide;
    this->armor = armor;
    this->strength = strength;
}

/******************************************************************
 ** Virtual Character Destructor
 **
 ** Gets rid of makefile pedantic errors
 **
 *****************************************************************/

Character::~Character() {
    
}

/******************************************************************
 ** Virtual Attack Function
 **
 ** The attack function simply looks at the atk dice that the attacker has,
 ** runs a for loop for that amount, and increments the dmgDealt by 
 ** the final total. It then returns that value into the defend function 
 ** below when called.
 **
 *****************************************************************/

int Character::attack() {

    int dmgDealt = 0;
    
    cout << "The attacking " << this->getType() << " has " << this->getStrength() << " strength and " << this->getArmor() << " armor." << endl << endl;
    
    // Loop through and 
    for(int i = 0; i < this->atkDice[0]; i++) {
        dmgDealt += rollAttack();
    }
    cout << "The attacking " << this->getType() << " dealt " << dmgDealt << " damage total." << endl << endl;
    // Return the damage dealt by the attacker
    return dmgDealt;
}


/******************************************************************
 ** Virtual Defend Function
 **
 ** The defend function does several things. First, it displays information about
 ** the defender. It then runs a series of functions like rollDefend() within
 ** a for loop which is dependent on however many dice the defender can roll.
 ** It returns a boolean value for whether or not the character's strength is 
 ** above or below 1. If false, the character is effectively dead - if true the
 ** recursive function in the combat function will continue to run.
 **
 *****************************************************************/

bool Character::defend(int dmgAttack) {
    
    // Print out the defender's strength before the combat
    cout << "The defending " << this->getType() << " has " << this->getStrength() << " strength and " << this->getArmor() << " armor." << endl << endl;
    
    // Reduce the attack by the total value of the armor.
    dmgAttack -= armor;
    
    // Roll for the additional damage that can be saved.
    for(int i = 0; i < this->defDice[0]; i++) {
        
        dmgAttack -= rollDefend();
        
    }
    
    // Prevent the attack from dealing negative damage.
    if (dmgAttack < 1 ) {
        
        dmgAttack = 0;
        
    }
    
    cout << "The defending " << this->getType() << "'s armor reduced the attack by " << armor << endl;
    cout << "The defending " << this->getType() << " reduced the attack to " << dmgAttack << " damage." << endl;
    
    // Reduce the Defender's Strength by the dmgAttack.
    strength -= dmgAttack;
    
    if (strength < 1) {
        
        // Set the strength to 0 to ignore negative values.
        strength = 0;
        
        
        // Print that the character is dead
        cout << "The defending " << this->getType() << " has " << this->getStrength() << " strength remaining." << endl;
        cout << "The defending " << this->getType() << " has been slain in glorious combat!" << endl;
        
        // Character is dead - return false.
        return false;
        
    } else {
        
        cout << "The defending " << this->getType() << " has " << this->getStrength() << " strength remaining." << endl;
        // Character is alive - return true.
        return true;
        
    }
}

/******************************************************************
 ** Roll Attack Function
 **
 ** Calling this function will simulate a roll based on the max-bounds
 ** of the attack dice array. This is a cleaner, better method
 ** over rand() which has terrible results.
 **
 *****************************************************************/

int Character::rollAttack() {
    int roll;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, this->atkDice[1]);
    
    roll = dis(gen);
    
    cout << "The attacking " << this->getType() << " made an attack roll of " << roll << endl;
    return roll;
}

/******************************************************************
 ** Roll Defend Function
 **
 ** Calling this function will simulate a roll based on the max-bounds
 ** of the defend dice array. This is a cleaner, better method 
 ** over rand() which has terrible results.
 **
 *****************************************************************/


int Character::rollDefend() {
    int roll;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, this->defDice[1]);
    
    roll = dis(gen);
    
    cout << "The defending " << this->getType() << " made a defense roll of " << roll << endl;
    return roll;
}

/******************************************************************
 ** Various Getter Functions
 **
 ** These are utility functions for grabbing various bits of info
 ** about the derived classes. Things like the type, armor, and strength
 ** are all accessible.
 **
 *****************************************************************/

string Character::getType() {
    return type;
}

int Character::getArmor() {
    return armor;
}

int Character::getStrength() {
    return strength;
}
