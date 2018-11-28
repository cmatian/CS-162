/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Reuseable Menu Functions for Game of War
 *************************************************************************/

#include "menu.hpp"

string playerDie(int die) {
    if (die == 1) {
        return "regular";
    } else {
        return "loaded";
    }
}

// Validation Function for single input integers
bool validateOne(int value) {
    if (value > 0 && value % 1 == 0) {
        return true;
    } else {
        return false;
    }
}

// Exit Message that is played when the user is exiting the program
void exitMsg() {
    cout << "The program is now closing." << endl;
}
