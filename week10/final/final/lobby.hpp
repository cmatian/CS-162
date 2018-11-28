/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for lobby derived class and functions
 **
 ** LOBBY.HPP
 *****************************************************************/

#ifndef lobby_hpp
#define lobby_hpp

#include "spaces.hpp"

class Lobby : public Space {
    
public:
    
    Lobby(string n);
    ~Lobby();
    
    void entrance();
    
    void observe();
    
    int menu();
    
    bool riddle();
    
    void showMap();
    
};

#endif /* lobby_hpp */
