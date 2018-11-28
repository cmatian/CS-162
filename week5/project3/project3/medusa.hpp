/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Derived class of the abstract character class - contains
 ** function prototypes for the Medusa characters.
 **
 ** MEDUSA.HPP
 *****************************************************************/

#ifndef medusa_hpp
#define medusa_hpp

#include "character.hpp"
#include "validation.hpp"

// DERIVED CLASS MEDUSA
class Medusa : public Character {
    
public:
    // Medusa Derived Class Constructor
    Medusa();
    virtual ~Medusa();
    
    // Overriding Virtual Functions
    virtual int attack();
    
    
};

#endif /* medusa_hpp */
