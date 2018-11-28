/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Derived class of the abstract character class - contains
 ** function prototypes for the Harry Potter characters.
 **
 ** HARRYPOTTER.HPP
 *****************************************************************/

#ifndef harrypotter_hpp
#define harrypotter_hpp

#include "character.hpp"
#include "validation.hpp"

// DERIVED CLASS HARRY POTTER
class Harrypotter : public Character {
    
private:
    bool hogwarts;
    
public:
    // Vampire Derived Class Constructor
    Harrypotter();
    virtual ~Harrypotter();
    
    // Overriding Virtual Functions
    virtual bool defend(int);
    
};


#endif /* harrypotter_hpp */
