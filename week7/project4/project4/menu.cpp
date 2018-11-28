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
    charMenu.push_back("VAMPIRE");
    charMenu.push_back("BARBARIAN");
    charMenu.push_back("BLUEMEN");
    charMenu.push_back("MEDUSA");
    charMenu.push_back("HARRY POTTER");
    
    // Display Loser Stack
    loserMenu.push_back("Display Losers");
    loserMenu.push_back("Skip");
    
    // Play Again Menu
    loopMenu.push_back("Start over and play another tournament");
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





