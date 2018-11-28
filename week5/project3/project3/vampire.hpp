/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Derived class of the abstract character class - contains 
 ** function prototypes for the Vampire character.
 **
 ** VAMPIRE.HPP
 *****************************************************************/

#ifndef vampire_hpp
#define vampire_hpp

#include "character.hpp"
#include "validation.hpp"

// DERIVED CLASS VAMPIRE
class Vampire : public Character {
    
public:
    // Vampire Derived Class Constructor
    Vampire();
    virtual ~Vampire();
    
    // Overriding Virtual Functions
    virtual bool defend(int);

};

#endif /* vampire_hpp */
