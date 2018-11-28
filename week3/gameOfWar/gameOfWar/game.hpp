/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Header specification files for game functions
 *************************************************************************/

#include "dice.hpp"

#include <time.h> // Needed for rand
#include <cstdlib> // Needed for rand
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


#ifndef game_hpp
#define game_hpp

class Game {
    
private:
    int p1Type,
        p2Type;
    
    int p1Side,
        p2Side;
    
    int numRounds;
    
    Die *d1, *d2;
    
public:
    // Game Constructor
    Game(int, int, int, int, int);
    
    // Score Update
    void updateScore();
    
    // Run the Game
    void run();
    
    // Create the Relative Die Classes
    void createDie();
    
    
};


#endif
