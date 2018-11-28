/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for menu class and functions
 **
 ** MENU.CPP
 *****************************************************************/

#ifndef menu_hpp
#define menu_hpp

#include "validation.hpp"

class Menu {
    
private:
    
    
public:
    // Various Vector Menus to be used in the program
    vector<string> mainMenu;
    vector<string> charMenu;
    vector<string> loopMenu;

    
    // Menu Constructor
    Menu();
    
    // Display Menu Function Prototype
    void showMenu(vector<string>, string);
    
};

#endif /* menu_hpp */

