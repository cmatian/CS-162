/*************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Function specification file for animal.cpp
 *************************************************************************/

#ifndef animal_hpp
#define animal_hpp

#include "validation.hpp"

// Animal Class
class Animal {
    
protected:
    // Age of the animal
    int age;
    
    // Total babies possible per pregnancy
    int babies;
    
    // Cost of the animal (storing as a double for now)
    double cost;
    
    // Base Food Cost
    int foodCost = 10;
    
    // Base pay off
    double payoff;
    
    
    
    
public:
    // Animal Object Constructor
    Animal();
    
    // Getters
    int getAge();
    
    int getBabies();
    
    double getCost();
    
    int getFoodCost();
    
    double getPayoff();
    
    // Setters
    void setAge(int);
    
};

// TIGER Subclass - inheriting from animal class
class Tiger : public Animal {
    
public:
    // Tiger Constructor
    Tiger();
};

// TURTLES Subclass - inheriting from animal class
class Turtle : public Animal {
    
public:
    // Turtle Constructor
    Turtle();
};

// PENGUIN Subclass - inheriting from animal class
class Penguin : public Animal {
    
public:
    // Penguin Constructor
    Penguin();
};

#endif
