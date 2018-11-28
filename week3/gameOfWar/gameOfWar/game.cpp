/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Reuseable game functions for Game of War
 *************************************************************************/

#include "game.hpp"
#include "dice.hpp"

Game::Game(int p1T, int p2T, int p1S, int p2S, int rounds) {
    // Variable Initialization
    p1Type = p1T;
    p2Type = p2T;
    
    p1Side = p1S;
    p2Side = p2S;
    
    numRounds = rounds;
    
    // Creates our Die objects based on what the player's dice type is
    createDie();
    
}

void Game::createDie() {
    // IF 1 = Regular Die
    // ELSE 2 = Loaded Die
    
    d1 = d2 = NULL;
    
    if(p1Type == 1) {
        d1 = new Die(p1Side);
    } else {
        d1 = new loadedDie(p1Side);
    }
    
    if(p2Type == 1) {
        d2 = new Die(p2Side);
    } else {
        d2 = new loadedDie(p2Side);
    }
    
}


void Game::run() {
    int p1Score,
        p2Score;
    
    p1Score = p2Score = 0;
    
    for (int i = 0; i < numRounds; i++) {
        int p1Roll, p2Roll;
        
        // Current Round
        
        // Go through the Player's Dice Rolls
        p1Roll = d1->roll();
        p1Score += p1Roll;
        
        p2Roll = d2->roll();
        p2Score += p2Roll;
        
        cout << endl;
        cout << "Current Round: " << i + 1 << endl;
        cout << "Player One " << "[" << d1->getType() << " Die, " << d1->getSide() << " Side(s)]" << " rolled: " << p1Roll << endl;
        cout << "Player Two " << "[" << d2->getType() << " Die, " << d2->getSide() << " Side(s)]" << " rolled: " << p2Roll << endl << endl;
        
        cout << "Player One has a total of: " << p1Score << endl;
        cout << "Player Two has a total of: " << p2Score << endl << endl;
        cout << "=======================================================================" << endl << endl;
    }
    // Final Score
    cout << "THE FINAL SCORES ARE:" << endl;
    cout << "Player One: " << p1Score << endl;
    cout << "Player Two: " << p2Score << endl;
    
    if(p1Score > p2Score) {
        cout << "PLAYER ONE WINS!" << endl;
    } else if (p1Score < p2Score) {
        cout << "PLAYER TWO WINS!" << endl;
    } else {
        cout << "DRAW GAME" << endl;
    }
    
    // Delete d1/d2 in order to prevent memory leaks
     delete d1;
     delete d2;
}
