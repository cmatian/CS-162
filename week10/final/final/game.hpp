/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for the game class that is called
 ** which starts the game and runs.
 **
 ** GAME.HPP
 *****************************************************************/

#ifndef game_hpp
#define game_hpp

#include "player.hpp"
#include "spaces.hpp"
#include "lobby.hpp"
#include "courtyard.hpp"
#include "easthall.hpp"
#include "westhall.hpp"
#include "weststudy.hpp"
#include "eaststudy.hpp"

class Game {
    
private:
    
    // Chest Key
    char chestKeyOne = 'c';
    char chestKeyTwo = '=';
    
    // Initial Message Display for Various Rooms
    bool initialMsg = true;
    bool lobbyTrigger = true;
    bool courtyardTrigger = true;
    bool easthallTrigger = true;
    bool eaststudyTrigger = true;
    bool westhallTrigger = true;
    bool weststudyTrigger = true;
    
    // Riddle Trigger
    bool riddleOne = false;
    bool riddleTwo = false;
    bool riddleThree = false;
    bool riddleFour = false;
    
    // Exit Game Loop Trigger
    bool runGame = true;
    
    // Player
    Player *player;
    
    // Player Bag
    vector <char> bag;
    
    // Space Pointers
    Space *lobby;
    Space *courtyard;
    Space *easthall;
    Space *eaststudy;
    Space *westhall;
    Space *weststudy;
    
    
    struct RoomNode {
        
        Space *space;
        string roomName;
        RoomNode *north;
        RoomNode *south;
        RoomNode *east;
        RoomNode *west;
        
        RoomNode(Space *type, string nm, RoomNode *n = nullptr, RoomNode *s = nullptr, RoomNode *e = nullptr, RoomNode *w = nullptr) {
            
            space = type;
            roomName = nm;
            north = n;
            south = s;
            east = e;
            west = w;
            
        }
    
    };
    
    RoomNode *currentArea;
    
public:
    Game();
    ~Game();
    
    Space *currentSpace();
    
    void enterNewRoom();
    
    void moveToLobby();
    void moveToCourtYard();
    
    void moveToWestHall();
    void moveToWestStudy();
    
    void moveToEastHall();
    void moveToEastStudy();
    
    void showStatus();
    
};



#endif /* game_hpp */
