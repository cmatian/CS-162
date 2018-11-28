/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main File for the Game
 **
 ** MAIN.CPP
 *****************************************************************/

#include "game.hpp"

int main() {
    
    bool starter = true;
    
    do {
        
        // Display the Main Menu
        cout << "================== [ MAIN MENU ] ==================" << endl;
        cout << "\t[1]: Start the \"Riddler's Mansion\" Game" << endl;
        cout << "\t[2]: How to play the game." << endl;
        cout << "\t[3]: Riddle Answers for the Grader" << endl;
        cout << "\t[4]: Exit the Game" << endl;
        cout << "===================================================" << endl;
        
        switch (validateBounds(1, 4)) {
            // Start the Game
            case 1: {
                
                Game startGame;
                
                startGame.enterNewRoom();
                
                starter = false; // only run the game once
                
                break;
            }
               
            // Print out Instructions about the game
            case 2: {
                
                cout << "\nThe Riddler's Mansion Game is a riddle based game." << endl;
                cout << "You will control an adventurer (who you will name) and" << endl;
                cout << "navigate your him/her through various rooms and hallways." << endl;
                cout << "You will have access to a map which will relay your current location." << endl;
                cout << endl;
                cout << "There are a total of 6 rooms - 5 of which contain special items/unlocks." << endl;
                cout << "Each study room contains a key piece for the chest in the courtyard," << endl;
                cout << "and each hallway provides access to their respective study rooms - granted" << endl;
                cout << "you need to solve the riddle to gain access." << endl;
                cout << endl;
                cout << "A word of warning though, answer incorrectly and you'll lose a point of health" << endl;
                cout << "for each bad answer. You only have 5 health!" << endl;
                cout << endl;
                cout << "With that said it's all fairly simple, solve riddles, get the key, unlock the chest" << endl;
                cout << "and claim your prize...enjoy!\n" << endl;
                
                break;
            }
              
            // Print out a cheat sheet for the answers
            case 3: {
                
                cout << endl;
                cout << "\nEast Hall Answer is: 'A STAMP'" << endl;
                cout << "East Study Answer is: 'TEETH'" << endl;
                cout << "West Hall Answer is: 'TIME'" << endl;
                cout << "West Study Answer is: 'THE MOUNTAIN'" << endl;
                cout << endl;
                
                break;
            }
                
            // Exit the Game
            case 4: {
                
                cout << "\nExiting the game..." << endl << endl;
                starter = false;
                break;
            }
        }
        
    } while ( starter );
    
    return 0;
}
