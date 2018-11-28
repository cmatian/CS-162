/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Derived class of the abstract character class - contains
 ** function prototypes for the Bluemen characters.
 **
 ** BLUEMEN.HPP
 *****************************************************************/

#ifndef bluemen_hpp
#define bluemen_hpp

#include "character.hpp"
#include "validation.hpp"

// DERIVED CLASS BLUEMEN
class Bluemen : public Character {
    
public:
    // Bluemen Derived Class Constructor
    Bluemen();
    virtual ~Bluemen();
    
    // Overriding Virtual Functions
    virtual bool defend(int);
    
};


#endif /* bluemen_hpp */
