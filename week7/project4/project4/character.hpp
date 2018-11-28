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
    string name;
    string team;
    int atkDice[2];
    int defDice[2];
    int armor;
    int strength;
    int max;
    
    
// Public Functions
public:
    Character(string, int, int, int, int, int, int);
    virtual ~Character();
    
    virtual int attack();
    virtual bool defend(int);
    virtual void restore();
    
    int rollAttack();
    int rollDefend();
    
    // Getters
    string getType();
    string getName();
    string getTeam();
    int getArmor();
    int getStrength();
    
    // Setter
    string setName();
    void setTeam(string);
    
};



#endif /* character_hpp */
