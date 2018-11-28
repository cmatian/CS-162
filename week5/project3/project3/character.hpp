/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Abstract class for characters and creatures during gameplay.
 **
 ** CHARACTER.HPP
 *****************************************************************/

#ifndef character_hpp
#define character_hpp

#include "validation.hpp"


class Character {
// Protected variable declarations
protected:
    string type;
    int atkDice[2];
    int defDice[2];
    int armor;
    int strength;
    
    
// Public Functions
public:
    Character(string, int, int, int, int, int, int);
    virtual ~Character();
    
    virtual int attack();
    virtual bool defend(int);
    
    int rollAttack();
    int rollDefend();
    
    // Getters
    string getType();
    int getArmor();
    int getStrength();
    
};



#endif /* character_hpp */
