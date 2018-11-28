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
    this->name = setName();
    this->atkDice[0] = atkDiceNum;
    this->atkDice[1] = atkDiceSide;
    this->defDice[0] = defDiceNum;
    this->defDice[1] = defDiceSide;
    this->armor = armor;
    this->strength = strength;
    this->max = strength;
}

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
    
    cout << endl;
    cout << "===================================================================" << endl;
    cout << this->getName() << " [" << this->getType() << " - " << this->getTeam() << "] " << " is now attacking..." << endl;
    cout << "===================================================================" << endl;
    
    
    int dmgDealt = 0;
    
    cout << endl;
    cout << this->getName() << " [" << this->getType() << "] " << "has " << this->getStrength() << " strength and " << this->getArmor() << " armor." << endl;
    
    // Loop through and 
    for(int i = 0; i < this->atkDice[0]; i++) {
        dmgDealt += rollAttack();
    }
    cout << this->getName() << " [" << this->getType() << "] " << "dealt " << dmgDealt << " damage total." << endl << endl;
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
    
    cout << "===================================================================" << endl;
    cout << this->getName() << " [" << this->getType() << " - " << this->getTeam() << "] " << " is now defending..." << endl;
    cout << "===================================================================" << endl << endl;
    
    // Print out the defender's strength before the combat
    cout << this->getName() << " [" << this->getType() << "] " << "has " << this->getStrength() << " strength and " << this->getArmor() << " armor." << endl << endl;
    
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
    
    cout << this->getName() << " [" << this->getType() << "]'s armor reduced the attack by " << armor << " point." << endl;
    cout << this->getName() << " [" << this->getType() << "] " << "reduced the attack to " << dmgAttack << " damage." << endl;
    
    // Reduce the Defender's Strength by the dmgAttack.
    strength -= dmgAttack;
    
    if (strength < 1) {
        
        // Set the strength to 0 to ignore negative values.
        strength = 0;
        
        
        // Print that the character is dead
        cout << this->getName() << " [" << this->getType() << "] " << "has " << this->getStrength() << " strength remaining." << endl << endl;
        cout << this->getName() << " [" << this->getType() << "] " << "has been slain in glorious combat!" << endl << endl;
        
        // Character is dead - return false.
        return false;
        
    } else {
        
        cout << this->getName() << " [" << this->getType() << "] " << "has " << this->getStrength() << " strength remaining." << endl;
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
    
    cout << this->getName() << " [" << this->getType() << "] " << "made an attack roll of " << roll << endl;
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
    
    cout <<  this->getName() << " [" << this->getType() << "] " << "made a defense roll of " << roll << endl;
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

string Character::getName() {
    return name;
}

string Character::getTeam() {
    return team;
}

int Character::getArmor() {
    return armor;
}

int Character::getStrength() {
    return strength;
}

void Character::setTeam(string foo) {
    this->team = foo;
}

/******************************************************************
 ** setName Function
 **
 ** Each time a character is created, the setName() function is called
 ** immediately after and the user is prompted to create a name
 ** for the character.
 **
 *****************************************************************/

string Character::setName() {
    
    string charName;
    
    cout << "Please enter a name for " << this->getType() << endl;
    
    getline(cin, charName);
    while(!validString(charName)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid name - blank inputs not allowed." << endl;
        getline(cin, charName);
    }
    
    return charName;
    
}

/******************************************************************
 ** Restore Function
 **
 ** Checks the current health of the character first. If it's below
 ** the max limit it will restore a certain amount of hp. The amount
 ** restored will never exceed the max health, however.
 **
 *****************************************************************/

void Character::restore() {
    
    // Had to comment out the mersenne uniform int distribution device because it was causing a stack overflow
    // Valgrind was literally hitting the 8mb cap each time the recovery function ran...
    
    // int roll;
    
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<> dis(1, (max - strength));
    
    // roll = dis(gen);
    
    if ( strength >= max ) {
        
        cout << this->getName() << " [" << this->getType() << "]" << " is already at full health. No need for a medicus." << endl;
        
    } else {
        
        //cout << this->getName() << " [" << this->getType() << "]" << " had their health restored by " << roll << " points." << endl;
        
        strength += (rand() % (max - strength)) + 1;
        
    }
    
}
