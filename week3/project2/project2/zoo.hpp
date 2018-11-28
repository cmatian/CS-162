/*************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Function specification file for zoo.cpp
 *************************************************************************/

#ifndef zoo_hpp
#define zoo_hpp

#include "animal.hpp"
#include "simulation.hpp"

class zoo {
    
private:
    
    // Do-while loop tracker
    bool runGame = true;
    
    // Tracks the bank and the bonus values for the zoo
    int bank;
    int bonus;
    int payoff;
    
    // Tracking total animals in each cage
    int tigerCount;
    int turtleCount;
    int penguinCount;
    
    // Tracking the sizes of each cage
    int baseSize = 10;
    int tigerCage = 10;
    int turtleCage = 10;
    int penguinCage = 10;
    
public:
    
    // Objects Array
    Animal **animals;
    Tiger **tigers;
    Penguin **penguins;
    Turtle **turtles;
    
    
    // Zoo Constructor
    zoo();
    
    // Zoo Destructor
    ~zoo();
    
    // Run the Game
    void run();
    void randomEvent(); // In simulation.cpp
    void setNull();
    void beginDay();
    void endDay();
    
    // Tiger Handlers
    void addTiger();
    void removeTiger();
    void resizeTiger();
    
    // Penguin Handlers
    void addPenguin();
    void removePenguin();
    void resizePenguin();
    
    // Turtle Handlers
    void addTurtle();
    void removeTurtle();
    void resizeTurtle();
    
};

#endif 


