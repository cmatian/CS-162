/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Combat Simulation class that controls the creation of a combat
 ** object and runs a function to simulate combat between
 ** two characters.
 **
 ** CHARACTER.HPP
 *****************************************************************/

#ifndef combat_hpp
#define combat_hpp

#include "menu.hpp"
#include "validation.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

// Combat Function Prototype
void combat(Character*, string, Character*, string, int);


#endif /* combat_hpp */
