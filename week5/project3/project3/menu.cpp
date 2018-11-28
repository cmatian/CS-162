/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for creating and controlling menus
 **
 ** MENU.CPP
 *****************************************************************/

#include "menu.hpp"

// Menu Constructor
Menu::Menu() {
    // Main Menu Options
    mainMenu.push_back("Begin Fantasy Combat Simulation");
    mainMenu.push_back("Exit the program");
    
    // Character Menu Selection
    charMenu.push_back("VAMPIRE -- Suave, debonair, but vicious and surprisingly resilient.");
    charMenu.push_back("BARBARIAN -- Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.");
    charMenu.push_back("BLUEMEN -- They are small, 6 inches tall, but fast and tough. They are hard to hit so they can take some damage.");
    charMenu.push_back("MEDUSA -- Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!");
    charMenu.push_back("HARRY POTTER -- Harry Potter is a wizard; The boy who lived.");
    
    // Play Again Menu
    loopMenu.push_back("Play another Fantasy Combat Simulation");
    loopMenu.push_back("Exit the program");
}

/******************************************************************
 ** Show Menu Function
 **
 ** This function simply takes in the vector menu we want to display
 ** and the menu title string. This effectively allows us to output and display
 ** vector menus that we've created.
 **
 *****************************************************************/

void Menu::showMenu(vector<string> menuIn, string menuTitle) {
    cout << "================= [ " << menuTitle << " ] =================" << endl;
    // Loop through each menu item and display it for the user
    for(int i = 0; i < menuIn.size(); i++) {
        cout << setw(2) << ' ' << "[" << i + 1 << "]: " << menuIn[i] << endl;
    }
    // Matches length of the bottom bar to the top bar
    cout << "====================";
    for(int i = 0; i < menuTitle.length(); i++) {
        cout << "=";
    }
    cout << "====================" << endl << endl << endl;
}





