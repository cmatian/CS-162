/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Reuseable Board Functions
 *************************************************************************/


#include "board.hpp"

Board::Board(int bX, int bY, int aX, int aY, int num) {
    // BOARD INFORMATION
    width = bX;
    height = bY;
    moves = num;
    
    // BOARD ICONS
    black = '#';
    white = ' ';
    ant = '*';
    
    // CREATE NEW BOARD
    board = new char*[height];
    for (int i = 0; i < height; i++) {
        board[i] = new char[width];
    }
    
    // INITIALIZE THE BOARD AND FILL IT WITH WHITE SPACE
    fill(board);
    
    // ESTABLISH THE ANT'S STARTING POSITION
    antX = aX;
    antY = aY;
    
    // TELL TONY (HE'S THE ANT) TO START AT THESE X AND Y COORDINATES - IF HE REFUSES HE GETS SQUASHED
    tony.setX(antX);
    tony.setY(antY);
    
    // UPDATE THE ANT'S POSITION TO USE THE VALUES THAT WERE INITIALIZED ABOVE
    updateAnt();

}

// This is the function that basically makes all the magic happen.
// It has a few features - tells us what turn it is, tells us what direction the ant is facing, displays the board each time it's iterated,
// moves the ant around the board using the .move() function from the Ant function fil, and more. Read inline comments below for more.
void Board::run() {
    // Run the game for as long as i is less than the total moves
    for (int i = 0; i < moves; i++){
        // Tells us what turn we are on
        cout << "YOU ARE ON TURN " << i + 1 << "." << endl;
        
        // grabs the direction of the ant and outputs the integer value into something easily legible.
        if(tony.getDirection() == 1) {
            cout << "ANT IS FACING NORTH..." << endl;
        } else if(tony.getDirection() == 2) {
            cout << "ANT IS FACING EAST..." << endl;
        } else if(tony.getDirection() == 3) {
            cout << "ANT IS FACING SOUTH..." << endl;
        } if(tony.getDirection() == 4) {
            cout << "ANT IS FACING WEST..." << endl;
        }
        
        // Display the board per loop
        display();
        cout << endl << endl;
        
        // Repositions Tony the ant using the move function.
        tony.move(board[antY][antX], height, width);
        
        // recolors the tile that the ant was on previously.
        recolor(board, antY, antX);
        
        // Updates the Ant's position relative to his new XY position (from the .move() function).
        updateAnt();
        
    }

    // Memory Deallocation for the game board.
    for (int i = 0; i < height; i++) {
        delete(board[i]);
    }
    delete(board);
}

// Board is filled out with whitespace
void Board::fill(char **board) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            board[i][j] = white;
        }
    }
}

// Function to display the board
// Places a space between each element so it's not so condensed on the screen and a little easier to differentiate the icons.
void Board::display() {
    char border = '/';
    
    // Pads out the width by 2 to make it even with the left/right borders
    for (int k = 0; k < (width + 2); k++) {
       cout << border << " ";
    }
    cout << endl;
    
    for (int i = 0; i < height; i++) {
        cout << border << " ";
        
        for (int j = 0; j < width; j++) {
            if (i == antY && j == antX)
                cout << ant << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << border << " " << endl;
    }
    
    // Pads out the width by 2 to make it even with the left/right borders
    for (int n = 0; n < (width + 2); n++) {
        cout << border << " ";
    }
    cout << endl;
}

// Function that allows us to update the Ant's position when it's called.
void Board::updateAnt() {
    antX = (tony.getX());
    antY = (tony.getY());
}


// recolors the board based on the current location of the ant's X and Y position 
void Board::recolor(char **board, int y, int x) {
    
    if (board[y][x] == white) {
        board[y][x] = black;
    }
    
    else if (board[y][x] == black) {
        board[y][x] = white;
    }
}















