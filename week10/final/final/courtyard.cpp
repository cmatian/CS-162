/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for courtyard derived class functions
 **
 ** COURTYARD.CPP
 *****************************************************************/

#include "courtyard.hpp"

/******************************************************************
 ** Courtyard Constructor
 **
 ** Creates a courtyard class that is derived from the Space class
 **
 *****************************************************************/

Courtyard::Courtyard(string n) : Space(n) {
    
}

/******************************************************************
 ** Courtyard Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Courtyard::~Courtyard() {
    
}

/******************************************************************
 ** entrance() function
 **
 ** Virtual function that runs each time the player enters a room
 ** for the first time. The flag for whether a player is entering
 ** a room for the first time is held in the Game class.
 **
 *****************************************************************/

void Courtyard::entrance() {
    
    cout << "The cold, bitter wind nips at your body as you step into the courtyard from the lobby." << endl;
    cout << "It's adorned with plants, flowers, and chest-high hedgerows." << endl;
    
}

/******************************************************************
 ** observe() function
 **
 ** Virtual function that the player can call from the menu()
 ** function. Prints out information and clues about the room
 ** the player is in.
 **
 *****************************************************************/

void Courtyard::observe() {
    
    cout << "You briefly peek around the courtyard and you spot various benches and Greco-Roman busts along the sides of the garden." << endl;
    cout << "At the center of the courtyard you spot what appears to be a rather ordane yet antiquated chest." << endl;
    cout << "The chest has a rather large outer lock, and beneath the mechanism you can spot what appears to be a secondary, inner lock." << endl;
    cout << "It appears as though you may need to search for keys in order to unlock the inner and outer locks." << endl;
    
}

/******************************************************************
 ** menu() function
 **
 ** Virtual function which returns an int based on the player's
 ** choice. The int that's returned is used in the Game class
 ** switch function for the various room function.
 **
 *****************************************************************/

int Courtyard::menu() {
    
    int poll;
    
    cout << "\n================= [ Courtyard Menu ] =================" << endl;
    cout << "\t[1]: Enter the Western Hall." << endl;
    cout << "\t[2]: Enter the Eastern Hall." << endl;
    cout << "\t[3]: Enter the Lobby." << endl;
    cout << "\t[4]: Investigate the surrounding area." << endl;
    cout << "\t[5]: Approach the chest in the center of the room." << endl;
    cout << "\t[6]: Consult your map." << endl;
    cout << "\t[7]: How am I feeling?" << endl;
    cout << "======================================================" << endl;
    cout << "Make a selection above..." << endl;
    
    poll = validateBounds(1, 7);
    
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

bool Courtyard::riddle() {
    
    // DOES NOTHING - COURTYARD DOESN'T USE A RIDDLE
    
    return true;
}

/******************************************************************
 ** map() function
 **
 ** Virtual function for a map that the player can call in order
 ** to reference where they are in mansion. Very straight forward.
 **
 *****************************************************************/

void Courtyard::showMap() {
    
    cout << endl;
    cout << "[====================================== [ ZONE MAP ] =====================================]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[    W. Study        W. Hall             Courtyard           E. Hall           E. Study   ]" << endl;
    cout << "[   [=======]     [=============]     [=============]     [=============]     [=======]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [       | *** |             ] *** |     YOU     | *** |             | *** |       ]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [=======]     [=============]     [=====[-]=====]     [=============]     [=======]   ]" << endl;
    cout << "[                                           ***                                           ]" << endl;
    cout << "[                                           ***                                           ]" << endl;
    cout << "[                                       [===[-]===]                                       ]" << endl;
    cout << "[                                       [         ]                                       ]" << endl;
    cout << "[                                       [         ]  Lobby                                ]" << endl;
    cout << "[                                       [         ]                                       ]" << endl;
    cout << "[                                       [===[-]===]                                N      ]" << endl;
    cout << "[                                     Front Entrance                             W   E    ]" << endl;
    cout << "[                                                                                  S      ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[=========================================================================================]" << endl;
    cout << endl;
    
}
