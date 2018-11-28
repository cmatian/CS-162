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
    mainMenu.push_back("Add a new node to the head"); // 1
    mainMenu.push_back("Add a new node to the tail"); // 2
    mainMenu.push_back("Delete the first node in the list"); // 3
    mainMenu.push_back("Delete the last node in the list"); //4
    mainMenu.push_back("Traverse the list from the tail"); //5
    mainMenu.push_back("Check first node value"); // 6
    mainMenu.push_back("Check last node value"); // 7
    mainMenu.push_back("Insert values from text file"); // 8
    mainMenu.push_back("Exit the program"); // 9
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
    cout << "====================" << endl << endl;
}





