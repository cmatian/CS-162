/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for westhall derived class and functions
 **
 ** WESTHALL.CPP
 *****************************************************************/

#include "westhall.hpp"

/******************************************************************
 ** Westhall Constructor
 **
 ** Creates a Westhall class that is derived from the Space class
 **
 *****************************************************************/

Westhall::Westhall(string n) : Space(n) {
    
}

/******************************************************************
 ** Westhall Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Westhall::~Westhall() {
    
}

/******************************************************************
 ** entrance() function
 **
 ** Virtual function that runs each time the player enters a room
 ** for the first time. The flag for whether a player is entering
 ** a room for the first time is held in the Game class.
 **
 *****************************************************************/

void Westhall::entrance() {
    
    cout << "You enter the western hall from the courtyard and the wind gradually dies out behind you as you continue deeper into the hall." << endl;
    cout << "As you move forward, you begin to gradually warm up as various sconses on the side of the room light up and bathe you in light and heat." << endl;
    
}

/******************************************************************
 ** observe() function
 **
 ** Virtual function that the player can call from the menu()
 ** function. Prints out information and clues about the room
 ** the player is in.
 **
 *****************************************************************/

void Westhall::observe() {
    
    cout << "You look investigate the study room further and find a similar scene to the hallway before." << endl;
    cout << "There is a large pedastal towards the center of the room with a placard on it." << endl;
    cout << "On the walls surrounding the pedastal, you see several paintings that are all well lit by several torches." << endl;
    cout << "The first painting is a scene of planes flying overhead and dropping heavy bombs onto a city below." << endl;
    cout << "The second painting is what appears to be an irradiated wasteland, with various radioactive warning signs lining the side of a barbed wire fence nearby." << endl;
    cout << "The third painting is an abstract clock sitting on a desk. Everything around it has decayed or turned to dust." << endl;
    cout << "You make a mental note of the various paintings - they may come in handy for the puzzle." << endl;
    
}

/******************************************************************
 ** menu() function
 **
 ** Virtual function which returns an int based on the player's
 ** choice. The int that's returned is used in the Game class
 ** switch function for the various room function.
 **
 *****************************************************************/

int Westhall::menu() {
    
    int poll;
    
    cout << "\n============= [ Western Hall Menu ] =============" << endl;
    cout << "\t[1]: Enter the Western Study." << endl;
    cout << "\t[2]: Enter the Courtyard." << endl;
    cout << "\t[3]: Investigate the surrounding area." << endl;
    cout << "\t[4]: Approach the pedastal in the center." << endl;
    cout << "\t[5]: Consult your map." << endl;
    cout << "\t[6]: How am I feeling?" << endl;
    cout << "=================================================" << endl;
    cout << "Make a selection above..." << endl;
    
    poll = validateBounds(1, 6);
    
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

bool Westhall::riddle() {
    
    bool answer = false;
    
    cout << "\nYou approach the pedastal in the center of the room." << endl;
    cout << "You spot a placard on the pedastal and read the following:" << endl;
    cout << "\"Riddle me this, riddle me that...\n All things it devours,\n Birds, beasts, trees, flowers,\n Gnaws iron, bites steel,\n Grinds hard stones to meal.\n What am I?\"" << endl;
    
    cout << "\nPress any key to continue..." << endl;
    system("read");
    
    cout << "============= [ Riddle (East Hall) ] =============" << endl;
    cout << "\t[1]: Bombs." << endl;
    cout << "\t[2]: Radiation." << endl;
    cout << "\t[3]: Time." << endl;
    cout << "==================================================" << endl;
    cout << "Choose your answer wisely..." << endl;
    
    switch (validateBounds(1, 3)) {
        case 1: {
            answer = false;
            break;
        }
        case 2: {
            answer = false;
            break;
            
        }
        case 3: {
            answer = true;
            break;
        }
    }
    
    return answer;
}

/******************************************************************
 ** map() function
 **
 ** Virtual function for a map that the player can call in order
 ** to reference where they are in mansion. Very straight forward.
 **
 *****************************************************************/

void Westhall::showMap() {
    
    cout << endl;
    cout << "[====================================== [ ZONE MAP ] =====================================]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[    W. Study        W. Hall             Courtyard           E. Hall           E. Study   ]" << endl;
    cout << "[   [=======]     [=============]     [=============]     [=============]     [=======]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [       | *** |     YOU     ] *** |             | *** |             | *** |       ]   ]" << endl;
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
