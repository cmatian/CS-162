/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function and Construction file for creating a player class
 ** and setting/getting information about the player.
 **
 ** PLAYER.CPP
 *****************************************************************/

#include "player.hpp"

/******************************************************************
 ** Player Constructor
 **
 ** Constructs the player and sets the name and the initial life.
 **
 *****************************************************************/

Player::Player() {
    
    this->name = setName();
    this->life = 5;
    
}

/******************************************************************
 ** Player Destructor
 **
 ** Calls the player destructor upon program exit
 **
 *****************************************************************/

Player::~Player() {
    
}

/******************************************************************
 ** getName()
 **
 ** Returns the name of the player
 **
 *****************************************************************/

string Player::getName() {
    
    return name;
    
}

/******************************************************************
 ** getLife()
 **
 ** Returns the life of the player
 **
 *****************************************************************/

int Player::getLife() {
    
    return life;
    
}

/******************************************************************
 ** reduceLife()
 **
 ** Function that reduces the player's life
 **
 *****************************************************************/

void Player::reduceLife() {
    
    life -= 1;
    
}

/******************************************************************
 ** setName()
 **
 ** When the player is constructed the user is asked to set a name
 ** for the character they are navigating the rooms with.
 **
 *****************************************************************/

string Player::setName() {
    
    string charName;
    
    cout << "Please enter a name for the adventurer." << endl;
    
    getline(cin, charName);
    while(!validString(charName)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid name - blank inputs not allowed." << endl;
        getline(cin, charName);
    }
    
    return charName;
    
}
