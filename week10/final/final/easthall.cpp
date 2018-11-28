/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for easthall derived class and functions
 **
 ** EASTHALL.CPP
 *****************************************************************/

#include "easthall.hpp"

/******************************************************************
 ** Easthall Constructor
 **
 ** Creates an easthall class that is derived from the Space class
 **
 *****************************************************************/

Easthall::Easthall(string n) : Space(n) {
    
}

/******************************************************************
 ** Easthall Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Easthall::~Easthall() {
    
}

/******************************************************************
 ** entrance() function
 **
 ** Virtual function that runs each time the player enters a room
 ** for the first time. The flag for whether a player is entering
 ** a room for the first time is held in the Game class.
 **
 *****************************************************************/

void Easthall::entrance() {
    
    cout << "You enter the eastern hall from the courtyard and the wind gradually dies out behind you as you continue deeper into the hall." << endl;
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

void Easthall::observe() {
    
    cout << "You look around the room slowly and spot what appears to be a dais or pedastal of some kind towards the end of the hall." << endl;
    cout << "Surrounding the pedastal on the adjacent walls are three paintings, all of which are well-lit by several torches." << endl;
    cout << "The first painting appears to be a close up shot of a stamp in the corner of an envelope." << endl;
    cout << "The second painting has a picture of a big, yellow sun." << endl;
    cout << "The third painting has a picture of a crescent moon above a rather large lake." << endl;
    cout << "You take note of the paintings and keep them in memory - they may serve as clues." << endl;
    
}

/******************************************************************
 ** menu() function
 **
 ** Virtual function which returns an int based on the player's
 ** choice. The int that's returned is used in the Game class
 ** switch function for the various room function.
 **
 *****************************************************************/


int Easthall::menu() {
    
    int poll;
    
    cout << "\n============= [ Eastern Hall Menu ] =============" << endl;
    cout << "\t[1]: Enter the Eastern Study." << endl;
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

bool Easthall::riddle() {
    
    bool answer = false;
    
    cout << "\nYou approach the pedastal in the center of the room." << endl;
    cout << "You spot a placard on the pedastal and read the following:" << endl;
    cout << "\"Riddle me this, riddle me that...\n I travel all around the world,\n but always stay in my corner.\n What am I?\"" << endl;
    
    cout << "\nPress any key to continue..." << endl;
    system("read");
    
    cout << "============= [ Riddle (East Hall) ] =============" << endl;
    cout << "\t[1]: A Stamp." << endl;
    cout << "\t[2]: The Sun." << endl;
    cout << "\t[3]: The Moon." << endl;
    cout << "==================================================" << endl;
    cout << "Choose your answer wisely..." << endl;
    
    switch (validateBounds(1, 3)) {
        case 1: {
            answer = true;
            break;
        }
        case 2: {
            answer = false;
            break;
            
        }
        case 3: {
            answer = false;
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

void Easthall::showMap() {
    
    cout << endl;
    cout << "[====================================== [ ZONE MAP ] =====================================]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[    W. Study        W. Hall             Courtyard           E. Hall           E. Study   ]" << endl;
    cout << "[   [=======]     [=============]     [=============]     [=============]     [=======]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [       | *** |             ] *** |             | *** |     YOU     | *** |       ]   ]" << endl;
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









