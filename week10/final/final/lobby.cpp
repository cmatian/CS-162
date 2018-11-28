/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Functions for the lobby derived class
 **
 ** LOBBY.CPP
 *****************************************************************/

#include "lobby.hpp"

/******************************************************************
 ** Lobby Constructor
 **
 ** Creates a lobby class that is derived from the Space class
 **
 *****************************************************************/

Lobby::Lobby(string n) : Space(n) {
    
}

/******************************************************************
 ** Lobby Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Lobby::~Lobby() {

}

/******************************************************************
 ** entrance() function
 **
 ** Virtual function that runs each time the player enters a room
 ** for the first time. The flag for whether a player is entering
 ** a room for the first time is held in the Game class.
 **
 *****************************************************************/

void Lobby::entrance() {
    
    cout << "You step forward into the study further until you're towards the center of the room." << endl;
    cout << "Cobwebs and dust adorn the various pieces of furniture and paintings strewn about the room." << endl;
    
}

/******************************************************************
 ** observe() function
 **
 ** Virtual function that the player can call from the menu()
 ** function. Prints out information and clues about the room
 ** the player is in.
 **
 *****************************************************************/

void Lobby::observe() {
    
    cout << "You look around the lobby and spot various, large paintings of various individuals." << endl;
    cout << "There are several couches in the lobby as well as love seats and several dressers. It would be rather lavish if not for the dust." << endl;
    cout << "Besides the backpack and map that you picked up as you walked into the lobby, there doesn't appear to be anything of note." << endl;
    
}

/******************************************************************
 ** menu() function
 **
 ** Virtual function which returns an int based on the player's
 ** choice. The int that's returned is used in the Game class
 ** switch function for the various room function.
 **
 *****************************************************************/

int Lobby::menu() {
    
    int poll;
    
    cout << "\n================= [ Lobby Menu ] =================" << endl;
    cout << "\t[1]: Enter the Courtyard." << endl;
    cout << "\t[2]: Investigate the surrounding area." << endl;
    cout << "\t[3]: Consult your map." << endl;
    cout << "\t[4]: How am I feeling?" << endl;
    cout << "\t[5]: Leave the Estate (Exit Game)." << endl;
    cout << "==================================================" << endl;
    cout << "Make a selection above..." << endl;
    
    poll = validateBounds(1, 5);
    
    return poll;
}

/******************************************************************
 ** riddle() function
 **
 ** Virtual function that is called when the player wants to
 ** approach the pedastal in either of the study or hall spaces.
 ** There are a total of 4 riddles that the player solves, and this
 ** function returns true or false based on whether the player
 ** solves the riddle correctly. If they fail to solve the riddle, 
 ** the Game class interprets the false result and reduces
 ** the player's health by 1 point.
 **
 *****************************************************************/

bool Lobby::riddle() {
    
    // DOES NOTHING - LOBBY DOESN'T USE A RIDDLE
    
    return true;
}

/******************************************************************
 ** map() function
 **
 ** Virtual function for a map that the player can call in order
 ** to reference where they are in mansion. Very straight forward.
 **
 *****************************************************************/

void Lobby::showMap() {
    
    cout << endl;
    cout << "[====================================== [ ZONE MAP ] =====================================]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[    W. Study        W. Hall             Courtyard           E. Hall           E. Study   ]" << endl;
    cout << "[   [=======]     [=============]     [=============]     [=============]     [=======]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [       | *** |             ] *** |             | *** |             | *** |       ]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [=======]     [=============]     [=====[-]=====]     [=============]     [=======]   ]" << endl;
    cout << "[                                           ***                                           ]" << endl;
    cout << "[                                           ***                                           ]" << endl;
    cout << "[                                       [===[-]===]                                       ]" << endl;
    cout << "[                                       [         ]                                       ]" << endl;
    cout << "[                                       [   YOU   ]  Lobby                                ]" << endl;
    cout << "[                                       [         ]                                       ]" << endl;
    cout << "[                                       [===[-]===]                                N      ]" << endl;
    cout << "[                                     Front Entrance                             W   E    ]" << endl;
    cout << "[                                                                                  S      ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[=========================================================================================]" << endl;
    cout << endl;
}



