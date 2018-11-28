/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main File for running the game
 **
 ** MAIN.CPP
 *****************************************************************/

#include "roll.hpp"
#include "menu.hpp"
#include "validation.hpp"

int main() {
    // Variable Declarations and/or Definitions
    bool game = true;
    string word;
    int rounds;
    int number;
    double prevAvg;
    double average = 0;
    int percentPop;
    int comparePop;
    int percentPush;
    int comparePush;
    
    // Queue and Stack declarations
    queue<int> buffer;
    queue<int> temp;
    stack<char> palin;
    
    // Create Menu Object
    Menu menu;
    
    do {
        
        // Display the Main Menu
        menu.showMenu(menu.mm, "Main Menu");
        
        switch (validateBounds(1, 3)) {
                
            case 1: {
                
                // Buffer Simulation
                cout << "Please enter the number of rounds you'd like the buffer to run for." << endl;
                rounds = getInt();
                
                cout << "\nPlease set the percentage chance for pushing a random integer into the buffer." << endl;
                percentPop = validateBounds(1, 100);
                
                cout << "\nPlease set the percentage chance for popping a random integer out of the buffer." << endl;
                percentPush = validateBounds(1, 100);
                
                // Run the buffer...
                for (int i = 1; i <= rounds; i++) {
                    
                    prevAvg = average;
                    
                    cout << "\nRound " << i << "..." << endl;
                    
                    // Generate random number 1-1000
                    number = roll(1, 1000);
                    
                    // Create the push value to compare to and check to see if it meets requirements
                    comparePush = roll(1, 100);
                    if ( percentPush <= comparePush ) {
                        cout << "Push was triggered." << endl;
                        buffer.push(number);
                    }
                    
                    // Create the pop value to compare to and check to see if it meets requirements
                    comparePop = roll(1, 100);
                    if ( percentPop <= comparePop && !buffer.empty() ) {
                        cout << "Pop was triggered." << endl;
                        buffer.pop();
                    }
                    
                    // Set temp equal to the buffer
                    temp = buffer;
                    cout << "\nThe elements in the buffer are..." << endl;
                    while ( !temp.empty() ) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                    
                    // Display the length of the buffer
                    cout << "\nThe length of the buffer after round " << i << " is " << buffer.size() << endl;
                    
                    // Display the average size of the buffer
                    average = (prevAvg * (i - 1) + buffer.size()) / i;
                    cout << "\nThe average length of the buffer is " << average << endl;
                }
                
                break;
                
            }
                
            case 2: {
                
                // Palindrome
                cout << "Please enter a word for the palindrome..." << endl;
                getline(cin, word);
                
                // Go through the word and take each char and place it into the palindrome stack
                for ( int i = 0; i < word.size(); i++) {
                    palin.push(word.at(i));
                }
                
                cout << "The palindrome is..." << endl;
                cout << word;
                // Cycle through the palindrome stack and display the top of it, then pop it out of the stack
                while (!palin.empty()) {
                    
                    cout << palin.top();
                    
                    palin.pop();
                    
                }
                cout << endl << endl;
                
                break;
                
            }
                
            case 3: {
                // Exit the Program
                game = false;
                
                
                break;
                
            }
                
        }
        
    } while (game);
    
    return 0;
}
