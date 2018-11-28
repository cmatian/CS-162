/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable function file for simulating the tournament
 ** combat between the two teams.
 **
 ** COMBAT.CPP
 *****************************************************************/

#include "combat.hpp"

/******************************************************************
 ** Combat Function
 **
 ** This function controls the tournament simulation. It takes in
 ** the lists as references (so that we can mutate them outside 
 ** of the function)
 **
 **
 *****************************************************************/


void combat(Queue &team1, Queue &team2, Stack &losers) {
    
    Menu menu;
    
    int teamScore1 = 0;
    int teamScore2 = 0;
    
    Character *p1, *p2;
    
    bool gameStatus = true;
    
    
    while(gameStatus) {
        
        p1 = team1.pop();
        p2 = team2.pop();
        
        if ( p1 && p2 ) {
            
            cout << endl;
            cout << "============================= [ New Round ] =============================" << endl << endl;
            cout << p1->getName() << " [" << p1->getType() << "]" << " will now be fighting " << p2->getName() << " [" << p2->getType() << "]" << endl << endl;
            cout << "=========================================================================" << endl << endl;
            
            // Keep track of who is alive
            bool p1Status = true;
            bool p2Status = true;
            
            // While loop keeps running until one of the players is killed
            
            while(p1Status == true && p2Status == true) {
                
                // p1 attacks p2
                p2Status = p2->defend(p1->attack());
                
                // If p2 survives it attacks and p1 defends
                if (p2Status == true) {
                    
                    p1Status = p1->defend(p2->attack());
                    
                }
                
            } // End of while loop for combat simulation
            
            if (p1Status == true) {
                // Player One Survived
                cout << "\n~~ Medical Service for Team One's Fighter ~~" << endl;
                p1->restore();
                cout << p1->getName() << " [" << p1->getType() << "] " << "now has " << p1->getStrength() << " strength." << endl;
                cout << endl;
                
                // Push the winner to the back of the Queue
                team1.push(p1);
                
                // Increment the Score
                teamScore1++;
                
                // Place loser (p2) into the loss stack
                losers.push(p2);
                
            } else {
                // Player Two Survived
                cout << "\n~~ Medical Service for Team Two's Fighter ~~" << endl;
                p2->restore();
                cout << p2->getName() << " [" << p2->getType() << "] " << "now has " << p2->getStrength() << " strength." << endl;
                cout << endl;
                
                team2.push(p2);
                teamScore2++;
                
                // Place loser (p1) into the loss stack
                losers.push(p1);
            }
            
        } else if (p2 == nullptr ) {
            // Team One Wins
            gameStatus = false;
            
            // Clear nodes from the team 2 list
            while (team1.head != nullptr) {
                team1.remove();
            }
            
            // Display Final score
            cout << "================= [ Final Score ] =================" << endl;
            cout << "===" << "Team One: " << teamScore1 << " points." << endl;
            cout << "===" << "Team Two: " << teamScore2 << " points." << endl;
            cout << "===================================================" << endl;
            
            cout << endl;
            cout << "================================" << endl;
            cout << "Team One has won the tournament!" << endl;
            cout << "================================" << endl;
            cout << endl;
            
            
        } else if (p1 == nullptr ) {
            // Team Two Wins
            gameStatus = false;
            
            // Clear nodes from the team 2 list
            while (team2.head != nullptr) {
                team2.remove();
            }
            
            // Display Final score
            cout << "================= [ Final Score ] =================" << endl;
            cout << "===" << "Team One: " << teamScore1 << " points." << endl;
            cout << "===" << "Team Two: " << teamScore2 << " points." << endl;
            cout << "===================================================" << endl;
            
            cout << endl;
            cout << "================================" << endl;
            cout << "Team Two has won the tournament!" << endl;
            cout << "================================" << endl;
            cout << endl;
            
        }
        
    } // End of game while loop
    
    // Ask player if they would like to display the loser pile menu?
    menu.showMenu(menu.loserMenu, "Display Loser Stack?");
    switch (validateBounds(1, 2)) {
        // Display Losers
        case 1: {
            cout << endl;
            cout << "============================================================" << endl;
            cout << "We honor those who fell in battle..." << endl;
            cout << "============================================================" << endl;
            
            // Popout the losers and print out their details.
            while ( (p1 = losers.pop()) ) {
                
                cout << p1->getName() << " [" << p1->getType() << " - " << p1->getTeam() << "]" << endl;
                
            }
            cout << endl;
            break;
        }
            
        // Skip Over
        case 2: {
            
            // Do Nothing - Skip
            
            break;
        }
    }
    
}


