/****************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Re-useable functions for animal class and related objects
 ****************************************************************************/

#include "animal.hpp"

// Animal Constructor
Animal::Animal() {
    
}

// get the age
int Animal::getAge() {
    return age;
}

// get the max babies
int Animal::getBabies() {
    return babies;
}

// get the cost
double Animal::getCost() {
    return cost;
}

// Get the food cost
int Animal::getFoodCost() {
    return foodCost;
}

// Get the payoff
double Animal::getPayoff() {
    return payoff;
}


// Set Age
void Animal::setAge(int age) {
    this->age = age;
}


// Tiger Constructor
Tiger::Tiger() : Animal() {
    this->age = 1;
    this->babies = 1;
    this->cost = 10000;
    this->foodCost = foodCost * 5;
    this->payoff = cost * .20;
}

// Penguin Constructor
Penguin::Penguin() : Animal() {
    this->age = 1;
    this->babies = 5;
    this->cost = 1000;
    this->foodCost = foodCost;
    this->payoff = cost * .10;
}

// Turtle Constructor
Turtle::Turtle() : Animal() {
    this->age = 1;
    this->babies = 10;
    this->cost = 100;
    this->foodCost = foodCost * .50;
    this->payoff = cost * .05;
}
