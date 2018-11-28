/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Reuseable dice functions for Game of War
 *************************************************************************/

#include "dice.hpp"

// Die Constructor

Die::Die(int sides) {
    type = "Regular";
    this->sides = sides;
}

int Die::roll() {
    return rand() % sides + 1;
}

int Die::getSide() {
    return sides;
}

string Die::getType() {
    return type;
}


// loadedDie Constructor

loadedDie::loadedDie(int sides) : Die(sides) {
    type = "Loaded";
    this->sides = sides;
}

int loadedDie::roll() {
    // 50% chance of either returning a normal roll or weighing the Die towards max value
    if (rand() % 2 + 1 == 1) {
        return rand() % sides + 1;
    } else {
        return sides;
    }
}
