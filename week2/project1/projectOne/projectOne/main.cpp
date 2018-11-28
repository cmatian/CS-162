/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Christopher Matian's Langton's Ant Simulation Program
 *************************************************************************/

#include "ant.hpp"
#include "board.hpp"
#include "validation.hpp"
#include <time.h> // Needed for rand
#include <cstdlib> // Needed for rand

int main() {
    // Board X Y Coordinates
    int boardX,
        boardY;
    
    // Ant X Y Coordinates
    int antX,
        antY;
    
    // Total moves the player wants the game to make.
    int moves;
    
    // Menu Option Selection
    int menuOption,
        randomMenuOption;
    char again;
    
    do {
        // Initial Menu
        cout << "Welcome to Christopher's Langton's Ant Program." << endl;
        cout << "Please select one of the two options below." << endl << endl;
        
        cout << "*~~~~~~~~~~~~~~~~~ Main Menu ~~~~~~~~~~~~~~~~~*" << endl;
        cout << "[1]: Begin Langton's Ant Simulation" << endl;
        cout << "[2]: Quit Program" << endl;
        cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl << endl;
        
        cin >> menuOption;
        
        while(menuOption < 1 || menuOption > 2) {
            cin.clear();
            cin.ignore();
            cout << "That is an invalid menu option - please select a valid option from the menu" << endl;
            cin >> menuOption;
        }
        if(menuOption == 1) {
            // Main Code Block
            // Prompt the user to determine the size of the game board.
            cout << "You will now be prompted to set the size of the Ant Simulation board." << endl << endl;
            // Determine width of the game board.
            cout << "Please enter the WIDTH of the board..." << endl;
            cin >> boardX;
            // Validate the width via validX function call
            while(!validX(boardX)) {
                cin.clear();
                cin.ignore();
                
                cout << "Sorry, that is an invalid input. Please enter a numeric value for the width." << endl;
                cin >> boardX;
            }
            // Determine height of the game board.
            cout << "Please enter the HEIGHT of the board..." << endl;
            cin >> boardY;
            // Validate the height via validX function call
            while(!validX(boardY)) {
                cin.clear();
                cin.ignore();
                
                cout << "Sorry, that is an invalid input. Please enter a numeric value for the height." << endl;
                cin >> boardY;
            }
            // Output the board inputs.
            cout << "The board width is: " << boardX << endl;
            cout << "The board height is: " << boardY << endl << endl;
            
            // Prompt the user to determine the ant's starting position - random or manual input.
            cout << "Would you like to position the ant's starting position randomly or manually?" << endl << endl;
            cout << "*~~~~~~~~~~~~~~~~~ Ant Position ~~~~~~~~~~~~~~~~~~*" << endl;
            cout << "[1]: Randomly determine the Ant's starting position" << endl;
            cout << "[2]: Manually input the Ant's starting position" << endl;
            cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl << endl;
            
            cin >> randomMenuOption;
            while(randomMenuOption < 1 || randomMenuOption > 2) {
                cin.clear();
                cin.ignore();
                
                cout << "That is an invalid menu option - please select a valid option from the menu above." << endl;
                cin >> randomMenuOption;
            }
            // User chooses to randomly determine the Ant's starting coordinates.
            if(randomMenuOption == 1) {
                srand(time(NULL));
                antX = rand() % boardX;
                antY = rand() % boardY;
            }
            // User chooses to manually determine the Ant's starting coordinates.
            else {
                // Prompt user to enter the Ant's starting X Coordinate.
                cout << "Please enter the starting X Position for the Ant..." << endl;
                cin >> antX;
                while (!validW(antX, boardX)) {
                    cin.clear();
                    cin.ignore();
                    
                    cout << "Sorry, that is an invalid input. Please re-enter the Ant's starting X position." << endl;
                    cin >> antX;
                }
                // Prompt user to enter the Ant's starting Y Coordinate.
                cout << "Please enter the starting Y Position for the Ant..." << endl;
                cin >> antY;
                while (!validH(antY, boardY)) {
                    cin.clear();
                    cin.ignore();
                    
                    cout << "Sorry, that is an invalid input. Please re-enter the Ant's starting Y position." << endl;
                    cin >> antY;
                }
            }
            // Output the Ant's starting position
            cout << "The Ant's starting X position is: " << antX << endl;
            cout << "The Ant's starting Y position is: " << antY << endl << endl;
            
            cout << "Now, please determine the number of times you would like the ant to move..." << endl;
            cin >> moves;
            while(!validX(moves)) {
                cin.clear();
                cin.ignore();
                
                cout << "Sorry, that is an invalid move value. Please enter a number that is greater than 0." << endl;
                cin >> moves;
            }
            // Output the total number of moves the ant will make.
            cout << "The ant will make a total of " << moves << " moves during the simulation. Enjoy the show!" << endl << endl;
            
            // Generate the game board using the inputted information
            Board board(boardX, boardY, antX, antY, moves);
            
            // Run the game
            board.run();
            
        }
        // Exits the Program if the user chooses main menu option 2
        else {
            return 0;
        }
        
        cout << "Would you like to return to the Main Menu and start over? [Y] / [N]" << endl;
        cin >> again;
        
    } while(again == 'Y' || again == 'y');
    
    return 0;
}
