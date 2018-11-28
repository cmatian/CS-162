/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main Function File for playing the game.
 **
 ** MAIN.CPP
 *****************************************************************/
// Source citation:
// Credit to fellow student Thad Sauter for introducing myself and others to rather interesting validation functions/techniques during our group project.
// I've implemented a couple of his validation functions that were better at handling validation.

#include "stack.hpp"
#include "queue.hpp"
#include "menu.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "combat.hpp"
#include "selection.hpp"

/******************************************************************
 ** Main
 **
 ** This is where all the magic happens. We use a number of nested switch
 ** cases to run through the game and enter a do-while loop that repeats
 ** everything if the player desires.
 **
 *****************************************************************/

int main() {
    
    // Seed the Time
    srand(time(NULL));
    
    // Generate Menu Object
    Menu menu;
    
    // Play Game Boolean
    bool playGame = true;
    
    // Generate a Queue Object
    Queue team1, team2;
    
    // Holds value for number of characters per team
    int charPerTeam;
    
    // Vector container for holding memory address of created characters - loop through and delete each created character
    vector<Character*> v1, v2;
    
    // Declare the Character Objects
    Character *c1, *c2;
    
    // Declare the Stack for losers
    Stack shamefulDisplay;
    
    // Main Cody Body
    
    // Display the welcome menu
    menu.showMenu(menu.mainMenu, "Welcome!");
    switch (validateBounds(1, 2)) {
        // Begin the game
        case 1: {
            
            while ( playGame == true ) {
                
                cout << "============================================================" << endl;
                cout << "How many character's should there be per team?" << endl;
                cout << "============================================================" << endl;
                
                charPerTeam = intOverZero();
                
                cout << "There will be " << charPerTeam << " characters per team. You will now be prompted to assemble each team (1 & 2) below." << endl << endl;
                
                cout << "Please select " << charPerTeam << " characters for team one." << endl;
                
                for (int i = 0; i < charPerTeam; i++) {
                    
                    cout << "Selecting Character " << i + 1 << " for team one." << endl;
                    
                    // Select the character - the string that's passed in is for the menu's title.
                    c1 = charSelect("Team One");
                    
                    // Set the Character's Team
                    c1->setTeam("Team One");
                    
                    // We push into vector first so we don't lose scope of the memory address when we re-assign the pointer in the for-loop.
                    v1.push_back(c1);
                    
                    //team1.push(c1);
                    // We push into the Queue using the vector's index position.
                    team1.push(v1[i]);
                    
                }
                // Display the Team One line up
                cout << "Team One's lineup consists of: " << endl;
                team1.print();
                
                
                cout << "Please select " << charPerTeam << " characters for team two." << endl;
                
                for (int i = 0; i < charPerTeam; i++) {
                    cout << "Selecting Character " << i + 1 << " for team two." << endl;
                    
                    c2 = charSelect("Team Two");
                    
                    c2->setTeam("Team Two");
                    
                    v2.push_back(c2);
                    
                    //team2.push(c2);
                    team2.push(v2[i]);
                    
                }
                
                // Display the Team Two line up
                cout << "Team Two's lineup consists of: " << endl;
                team2.print();
                
                // Call the combat function and pass in team1, team2, and shamefulDisplay. The function takes them in as references.
                combat(team1, team2, shamefulDisplay);
                
                for(int i = 0; i < charPerTeam; i++) {
                    
                    // Delete each vector index
                    delete v1[i];
                    delete v2[i];
                    
                }
                // Clear the Vectors
                v1.clear();
                v2.clear();
                
                // Ask if user would like to continue playing the game...
                menu.showMenu(menu.loopMenu, "Play Again?");
                switch (validateBounds(1, 2)) {
                    case 1: {
                        
                        playGame = true;
                        
                        break;
                    }
                        
                    case 2: {
                        
                        playGame = false;
                        
                        break;
                    }
                }
            }
            
            break;
            
        } // End of Case 1
    
        
        // Exit the Game
        case 2: {
            
            break;
        } // End of Case 2
    }
    
    return 0;
    
    
}


