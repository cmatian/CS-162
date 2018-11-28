/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for East Study derived class and functions
 **
 ** EASTSTUDY.HPP
 *****************************************************************/

#include "eaststudy.hpp"

/******************************************************************
 ** Eaststudy Constructor
 **
 ** Creates an eaststudy class that is derived from the Space class
 **
 *****************************************************************/

Eaststudy::Eaststudy(string n) : Space(n) {
    
}

/******************************************************************
 ** Eaststudy Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Eaststudy::~Eaststudy() {
    
}

/******************************************************************
 ** entrance() function
 **
 ** Virtual function that runs each time the player enters a room
 ** for the first time. The flag for whether a player is entering
 ** a room for the first time is held in the Game class.
 **
 *****************************************************************/

void Eaststudy::entrance() {
    
    cout << "You enter the East study from the hallway and find yourself in a rather square room." << endl;
    cout << "The torches in the room slowly light up as you step further into the room. You can faintly hear a brief creak above you as though someone is tracing your steps." << endl;
    
}

/******************************************************************
 ** observe() function
 **
 ** Virtual function that the player can call from the menu()
 ** function. Prints out information and clues about the room
 ** the player is in.
 **
 *****************************************************************/

void Eaststudy::observe() {
    
    cout << "Within the square room you identify a scene similar to the room before." << endl;
    cout << "There's a pedastal within the center of the room this time, and on the adjacent walls there are three large paintings." << endl;
    cout << "The first painting appears to be a picture of several rocks strewn about on a red concrete floor." << endl;
    cout << "The second painting is a picture of birds fluttering about on a red, wooden patio." << endl;
    cout << "The third and final painting is a picture of what looks to be a set of healthy, human teeth." << endl;
    cout << "You make a mental note of the pictures as they'll likely come in handy for the puzzle that is soon to follow." << endl;
    
}

/******************************************************************
 ** menu() function
 **
 ** Virtual function which returns an int based on the player's
 ** choice. The int that's returned is used in the Game class
 ** switch function for the various room function.
 **
 *****************************************************************/

int Eaststudy::menu() {
    
    int poll;
    
    cout << "\n============== [ Eastern Study Menu ] ==============" << endl;
    cout << "\t[1]: Return to the Eastern Hall." << endl;
    cout << "\t[2]: Investigate the surrounding area." << endl;
    cout << "\t[3]: Approach the pedastal in the center." << endl;
    cout << "\t[4]: Consult your map." << endl;
    cout << "\t[5]: How am I feeling?" << endl;
    cout << "====================================================" << endl;
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

bool Eaststudy::riddle() {
    
    bool answer = false;
    
    cout << "\nYou approach the pedastal in the center of the room." << endl;
    cout << "You spot a placard on the pedastal and read the following:" << endl;
    cout << "\"Riddle me this, riddle me that...\n Thirty white horses on a red hill,\n First they champ,\n Then they stamp,\n Then they stand still.\n What am I?\"" << endl;
    
    cout << "\nPress any key to continue..." << endl;
    system("read");
    
    cout << "============= [ Riddle (East Study) ] =============" << endl;
    cout << "\t[1]: Rocks." << endl;
    cout << "\t[2]: Birds." << endl;
    cout << "\t[3]: Teeth." << endl;
    cout << "===================================================" << endl;
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

void Eaststudy::showMap() {
    
    cout << endl;
    cout << "[====================================== [ ZONE MAP ] =====================================]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[    W. Study        W. Hall             Courtyard           E. Hall           E. Study   ]" << endl;
    cout << "[   [=======]     [=============]     [=============]     [=============]     [=======]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [       | *** |             ] *** |             | *** |             | *** |  YOU  ]   ]" << endl;
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
