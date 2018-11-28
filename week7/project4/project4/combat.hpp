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

#include "stack.hpp"
#include "queue.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

// Combat Function Prototype
void combat(Queue &, Queue &, Stack &);

#endif /* combat_hpp */
