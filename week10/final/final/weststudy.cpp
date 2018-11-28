/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for weststudy derived class and functions
 **
 ** WESTSTUDY.CPP
 *****************************************************************/

#include "weststudy.hpp"

/******************************************************************
 ** Weststudy Constructor
 **
 ** Creates a weststudy class that is derived from the Space class
 **
 *****************************************************************/

Weststudy::Weststudy(string n) : Space(n) {
    
}

/******************************************************************
 ** Weststudy Destructor
 **
 ** Does Nothing
 **
 *****************************************************************/

Weststudy::~Weststudy() {
    
}

/******************************************************************
 ** entrance() function
 **
 ** Virtual function that runs each time the player enters a room
 ** for the first time. The flag for whether a player is entering
 ** a room for the first time is held in the Game class.
 **
 *****************************************************************/

void Weststudy::entrance() {
    
    cout << "You enter the western study from the hall and look around you to find a square room." << endl;
    cout << "There are assorted objects and books strewn about the room, and a familiar scene of paintings." << endl;
    
}

/******************************************************************
 ** observe() function
 **
 ** Virtual function that the player can call from the menu()
 ** function. Prints out information and clues about the room
 ** the player is in.
 **
 *****************************************************************/

void Weststudy::observe() {
    
    cout << "You look investigate the study room further and find a similar scene to the hallway before." << endl;
    cout << "There is a large pedastal towards the center of the room with a placard on it." << endl;
    cout << "On the walls surrounding the pedastal, you see several paintings that are all well lit by several torches." << endl;
    cout << "The first painting is a large painting forests with mountains in the horizon rising well above the trees and plants." << endl;
    cout << "The second painting is a post-modern painting of the Eiffel Tower. It soars above into the sky and fills the horizon with it's immense size." << endl;
    cout << "The third painting is an illustration of the Greek God Atlas, towering above a large stone slab and carrying the weight of the world on his back." << endl;
    cout << "You make a mental note of the paintings as they may come in handy." << endl;
    
}

/******************************************************************
 ** menu() function
 **
 ** Virtual function which returns an int based on the player's
 ** choice. The int that's returned is used in the Game class
 ** switch function for the various room function.
 **
 *****************************************************************/

int Weststudy::menu() {
    
    int poll;
    
    cout << "\n============== [ Western Study Menu ] ==============" << endl;
    cout << "\t[1]: Return to the Western Hall." << endl;
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

bool Weststudy::riddle() {
    
    bool answer = false;
    
    cout << "\nYou approach the pedastal in the center of the room." << endl;
    cout << "You spot a placard on the pedastal and read the following:" << endl;
    cout << "\"Riddle me this, riddle me that...\n What has roots as nobody sees,\n Is taller than trees,\n Up, up, up it goes!\n And yet it never grows.\n What am I?\"" << endl;
    
    cout << "\nPress any key to continue..." << endl;
    system("read");
    
    cout << "============= [ Riddle (East Study) ] =============" << endl;
    cout << "\t[1]: The Eiffel Tower." << endl;
    cout << "\t[2]: The Mountain." << endl;
    cout << "\t[3]: The Greek Titan Atlas" << endl;
    cout << "===================================================" << endl;
    cout << "Choose your answer wisely..." << endl;
    
    switch (validateBounds(1, 3)) {
        case 1: {
            answer = false;
            break;
        }
        case 2: {
            answer = true;
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

void Weststudy::showMap() {
    
    cout << endl;
    cout << "[====================================== [ ZONE MAP ] =====================================]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[                                                                                         ]" << endl;
    cout << "[    W. Study        W. Hall             Courtyard           E. Hall           E. Study   ]" << endl;
    cout << "[   [=======]     [=============]     [=============]     [=============]     [=======]   ]" << endl;
    cout << "[   [       -     -             -     -             -     -             -     -       ]   ]" << endl;
    cout << "[   [  YOU  | *** |             ] *** |             | *** |             | *** |       ]   ]" << endl;
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
