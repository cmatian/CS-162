/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Christopher Matian's Game of War Loaded Dice Game
 *************************************************************************/
// SOURCE CITATION
// Die Rolling: http://www.cplusplus.com/forum/beginner/108313/
// Loaded Die Weight: http://www.cplusplus.com/forum/beginner/132561/
// Object Creation in Constructor using a func(): https://stackoverflow.com/questions/11852645/how-to-create-an-object-inside-another-class-with-a-constructor

#include "dice.hpp"
#include "game.hpp"
#include "menu.hpp"

int main() {
    // Seeding srand();
    srand(time(NULL));
    
    // Menus
    int startMenu;
    
    // Player One
    int pOneDice,
        pOneSide;
    
    // Player Two
    int pTwoDice,
        pTwoSide;
    
    // Total Rounds
    int rounds;
    
    // Base Code
    cout << "[1]: Start 'Game of War' Loaded Dice Simulator" << endl;
    cout << "[2]: Exit the program" << endl;
    cin  >> startMenu;
    
    while (startMenu < 1 || startMenu > 2) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please select enter a value corresponding with the menu item." << endl;
        cin >> startMenu;
    }
    if (startMenu == 1) {
        // Main code body for running the game
        
        // Determine the type of Die that PLAYER ONE will use
        cout << "What kind of die will player one have?" << endl;
        cout << "[1]: Regular" << endl;
        cout << "[2]: Loaded" << endl << endl;
        cin >> pOneDice;
        // Validation for selection
        while(pOneDice < 1 || pOneDice > 2) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input, please select either [1] Regular or [2] Loaded." << endl;
            cin >> pOneDice;
        }
        
        // Determine the total sides that PLAYER ONE'S die will have
        cout << "How many sides does player one's die have?" << endl;
        cin >> pOneSide;
        // Validation for value input
        while(!validateOne(pOneSide)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid side value; Please enter a value greater than or equal to 1." << endl;
            cin >> pOneSide;
        }
        // Print out what Player One will be using.
        cout << "PLAYER ONE will be a using a " << playerDie(pOneDice) << " die with " << pOneSide << " sides." << endl << endl;
        
        
        
        // Determine the type of Die that PLAYER TWO will use
        cout << "What kind of die will PLAYER TWO have?" << endl;
        cout << "[1]: Regular" << endl;
        cout << "[2]: Loaded" << endl << endl;
        cin >> pTwoDice;
        // Validation for selection
        while(pTwoDice < 1 || pTwoDice > 2) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input, please select either [1] Regular or [2] Loaded." << endl;
            cin >> pTwoDice;
        }
        
        // Determine the total sides that PLAYER TWO'S die will have
        cout << "How many sides does player two's die have?" << endl;
        cin >> pTwoSide;
        // Validation for value input
        while(!validateOne(pTwoSide)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid side value; Please enter a value greater than or equal to 1." << endl;
            cin >> pTwoSide;
        }
        // Print out what Player Two will be using.
        cout << "PLAYER TWO will be a using a " << playerDie(pTwoDice) << " die with " << pTwoSide << " sides." << endl << endl;
        
        // Determine the total number of rounds
        cout << "How many rounds will be played total?" << endl;
        cin >> rounds;
        while(!validateOne(rounds)) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a value that is greater than or equal to 1 for the rounds to be played." << endl;
            cin >> rounds;
        }
        
        cout << "Players One and Two will be playing for a total of " << rounds << " round(s)." << endl << endl;
        
        cout << "=======================================================================" << endl << endl;
        
        // Begin the game
        
        Game newGame(pOneDice, pTwoDice, pOneSide, pTwoSide, rounds);
        
        
        // Run the game
        newGame.run();
        
        
        
    } else {
        // Display exit msg when finished
        exitMsg();
        return 0;
    }
    exitMsg();
    return 0;
}
