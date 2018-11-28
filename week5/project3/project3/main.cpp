/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main Function File for playing the game.
 **
 ** MAIN.CPP
 *****************************************************************/

#include "validation.hpp"
#include "menu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "combat.hpp"

/******************************************************************
 ** Main
 **
 ** This is where all the magic happens. We use a number of nested switch
 ** cases to run through the game and enter a do-while loop that repeats
 ** everything if the player desires.
 **
 *****************************************************************/

int main() {
    
    // Declare Menu Object
    Menu menu;
    
    // Declare and Initialize the attack round to 1
    int round = 1;
    
    // Declare and initialize menu inputs and boolean for playAgain
    bool playAgain = true;
    
    // Declare the Character Objects
    Character *c1;
    Character *c2;
    
    // Show the Main Menu First
    menu.showMenu(menu.mainMenu, "Main Menu");
    switch (validateBounds(1, 2)) {
        
        // Case 1 = Continue into the game
        case 1: {
            
            // Do While Loop that runs the game in within Case 1
            do {
                // Show the Character Selection Menu for Character 1
                menu.showMenu(menu.charMenu, "Select Character 1");
                cout << "Please select the first character (this character will be the first one to attack)." << endl;
                switch (validateBounds(1, 5)) {
                    case 1: {
                        cout << "Vampire is Character 1." << endl;
                        c1 = new Vampire;
                        break;
                    }
                        
                    case 2: {
                        cout << "Barbarian is Character 1." << endl;
                        c1 = new Barbarian;
                        break;
                    }
                        
                    case 3: {
                        cout << "Bluemen is Character 1." << endl;
                        c1 = new Bluemen;
                        break;
                    }
                        
                    case 4: {
                        cout << "Medusa is Character 1." << endl;
                        c1 = new Medusa;
                        break;
                    }
                        
                    case 5: {
                        cout << "Harry Potter is Character 1." << endl;
                        c1 = new Harrypotter;
                        break;
                    }
                }
                
                // Show the Character Selection Menu for Character 2
                menu.showMenu(menu.charMenu, "Select Character 2");
                cout << "Please select the second character." << endl;
                switch (validateBounds(1, 5)) {
                    case 1: {
                        cout << "Vampire is Character 2." << endl;
                        c2 = new Vampire;
                        break;
                    }
                        
                    case 2: {
                        cout << "Barbarian is Character 2." << endl;
                        c2 = new Barbarian;
                        break;
                    }
                        
                    case 3: {
                        cout << "Bluemen is Character 2." << endl;
                        c2 = new Bluemen;
                        break;
                    }
                        
                    case 4: {
                        cout << "Medusa is Character 2." << endl;
                        c2 = new Medusa;
                        break;
                    }
                        
                    case 5: {
                        cout << "Harry Potter is Character 2." << endl;
                        c2 = new Harrypotter;
                        break;
                    }
                }
                
                
                // Call the combat function and run the simulation.
                combat(c1, "Character 1", c2, "Character 2", round);
                
                
                // Delete the characters when we're finished with them so that we don't pollute the heap.
                delete c1;
                delete c2;
                
                
                // Show the loop menu and see if the player wants to play again.
                menu.showMenu(menu.loopMenu, "Would you like to play again?");
                switch (validateBounds(1, 2)) {
                    case 1: {
                        playAgain = true;
                        break;
                    }
                        
                    case 2: {
                        playAgain = false;
                        break;
                    }
                }
            } while (playAgain == true);
            
            // End of Case 1
        }
        
            
        // Case 2 = Exit the Game
        case 2: {
            cout << "Exiting the program..." << endl;
            return 0;
        }
    }
    return 0;
}


