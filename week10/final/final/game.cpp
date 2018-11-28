/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for running the game and initializing the player
 ** details, creating the rooms, and connecting the rooms to each
 ** other.
 **
 ** GAME.CPP
 *****************************************************************/

#include "game.hpp"

/******************************************************************
 ** Game Constructor
 **
 ** This constructor takes all of the rooms/spaces and creates them.
 ** It also creates the player (which prompts the user to set a name)
 ** and then it sets the current area to the lobby and the 
 ** northern area to the courtyard.
 **
 *****************************************************************/

Game::Game() {
    
    // Create the Player
    player = new Player();
    
    // Create the Spaces
    lobby = new Lobby("Lobby");
    courtyard = new Courtyard("Courtyard");
    easthall = new Easthall("Eastern Hall");
    eaststudy = new Eaststudy("Eastern Study");
    westhall = new Westhall("Western Hall");
    weststudy = new Weststudy("Western Study");
    
    
    // Set the Current Room Node
    currentArea = new RoomNode(lobby, "Lobby");
    currentArea->north = new RoomNode(courtyard, "Courtyard", nullptr, currentArea);
    
}

/******************************************************************
 ** Game Destructor
 **
 ** Goes through and deletes the player and spaces that were
 ** declared. Lastly, it runs through each of the currentArea's
 ** space pointers and checks to see if they're not a nullptr.
 ** It then deletes that area and finally deletes the currentArea
 ** space.
 **
 *****************************************************************/

Game::~Game() {
    
    delete player;
    delete lobby;
    delete courtyard;
    delete easthall;
    delete eaststudy;
    delete westhall;
    delete weststudy;
    
    
    if (currentArea->north != nullptr ) {
            
        delete currentArea->north;
            
    }
        
    if (currentArea->south != nullptr ) {
            
        delete currentArea->south;
            
    }
        
    if (currentArea->east != nullptr ) {
            
        delete currentArea->east;
            
    }
        
    if (currentArea->west != nullptr ) {
            
        delete currentArea->west;
        
    }
     
    delete currentArea;
    
}

/******************************************************************
 ** currentSpace() function
 **
 ** Getter function that returns the space the player is in
 **
 *****************************************************************/

Space *Game::currentSpace() {
    
    return currentArea->space;
    
}

/******************************************************************
 ** enterNewRoom() function
 **
 ** This function uses several flags to determine what it should do.
 ** First, it checks to see that runGame is true, which keeps
 ** the function running until it's set to false (death or chest unlock).
 ** After that, it checks the initialMsg flag and if it's true it
 ** displays it once, then it sets the bool to false and never
 ** displays the intro text again.
 **
 ** The function then checks to see if the player health is 0,
 ** at which point the game ends. Finally, it checks to see what
 ** the name of the room the player is in and calls the 
 ** related room function which spits out various menus and options
 ** to the user. The function calls itself at the end to keep it running
 ** and check various actions the player has made.
 **
 *****************************************************************/


void Game::enterNewRoom() {
    
    // Run Game Flag
    while ( runGame ) {
        
        // Run InitialMsg Once
        while ( initialMsg ) {
            
            cout << "\nYou slowly approach the estate that you spotted in the distance." << endl;
            cout << "The air is musky and the wind is howling with an unbridled ferocity - you swear that it's growing more intense the closer you get." << endl;
            cout << "You reach the estate and reach out to open the door. Before you can touch it the door slowly swings open as if it's trying to avoid your touch." << endl;
            cout << "You enter through the open doors and you hear the wind die out behind you as the doors close by themselves." << endl;
            cout << "You look around and find that you are in the main lobby of the estate." << endl;
            cout << "Nearby is a satchel with a rolled up map poking out of the back pocket. Without hesitation, you pick up the bag and place the map into your pocket.\n" << endl;
            
            initialMsg = false;
        }
        
        // Check player health
        if ( player->getLife() == 0 ) {
            
            cout << "\nYou feel a heavy weight in your chest and then nothing. You try to move forward but find yourself tumbling forward onto your stomach and chest." << endl;
            cout << "You begin to lose consciousness as minutes go by, and very faintly you hear laughing in the distance - growing closer and closer with every second." << endl;
            cout << "Your eyes finally close shut and you drift off into an endless slumber." << endl;
            cout << "[You Have Died]\n" << endl;
            
            runGame = false;
            break;
            
        }
        
        cout << "You are currently located in the " << currentSpace()->getRoom() << endl;
        
        // LOBBY
        if ( currentArea->roomName == "Lobby" ) {
            
            if ( lobbyTrigger ) {
                currentSpace()->entrance();
                lobbyTrigger = false;
            }
            
            moveToLobby();
            
        // COURTYARD
        } else if ( currentArea->roomName == "Courtyard" ) {
            
            if ( courtyardTrigger ) {
                currentSpace()->entrance();
                courtyardTrigger = false;
            }
            
            moveToCourtYard();
            
        // EASTERN HALL
        } else if ( currentArea->roomName == "Eastern Hall" ) {
            
            if ( easthallTrigger ) {
                currentSpace()->entrance();
                easthallTrigger = false;
            }
            
            moveToEastHall();
           
        // WESTERN HALL
        } else if ( currentArea->roomName == "Western Hall" ) {
            
            if ( westhallTrigger ) {
                currentSpace()->entrance();
                westhallTrigger = false;
            }
            
            moveToWestHall();
            
        // EASTER STUDY
        } else if ( currentArea->roomName == "Eastern Study" ) {
            
            if ( eaststudyTrigger ) {
                currentSpace()->entrance();
                eaststudyTrigger = false;
            }
            
            moveToEastStudy();
            
        // WESTERN STUDY
        } else if ( currentArea->roomName == "Western Study" ) {
            
            if ( weststudyTrigger ) {
                currentSpace()->entrance();
                weststudyTrigger = false;
            }
            
            moveToWestStudy();
            
        }
        
        // RECURSION
        if ( currentArea != nullptr ) {
            
            enterNewRoom();
            
        }
        
    }
}

/******************************************************************
 ** moveToLobby() function
 **
 ** This function basically starts the player in the lobby and 
 ** lets the player move on to the courtyard area. If the player
 ** moves to a new space, it generates the next space information
 ** and connects the rooms together. It also deletes other rooms that
 ** are more than one space away (out of sight and out of mind) so
 ** we can manage the memory better.
 **
 ** The function uses the virtual function menu of the relative
 ** room to let the player make decisions as to what they want to do.
 **
 *****************************************************************/

void Game::moveToLobby() {
    
    int callMenu;
    
    switch ( callMenu = currentSpace()->menu() ) {
            
        // Enter the Courtyard
        case 1: {
            
            // Rebuild the Spaces
            RoomNode *temp = currentArea;                                                                           // Current Room - Lobby
            currentArea = temp->north;                                                                              // Current Room changed to Courtyard
            currentArea->south = temp;                                                                              // Current Room South changed to Lobby
            currentArea->east = new RoomNode(easthall, "Eastern Hall", nullptr, nullptr, nullptr, currentArea);     // Current Room East set to Eastern Hall
            currentArea->west = new RoomNode(westhall, "Western Hall", nullptr, nullptr, currentArea, nullptr);     // Current Room West set to Western Hall
            
            break;
        }
           
        // Observe the Surrounding Lobby Area
        case 2: {
            
            currentSpace()->observe();
            
            break;
        }
        // Show Map
        case 3: {
            
            currentSpace()->showMap();
            cout << "Press any key to put the map away..." << endl;
            system("read");
            break;
            
        }
        // Player Health Status
        case 4: {
            
            showStatus();
            break;
            
        }
        
        // Exit the Program
        case 5: {
            
            cout << "You decide to leave the estate - it's too spooky for you." << endl;
            
            runGame = false;
            
            break;
        }
    } // EOF Switch Statement
}

/******************************************************************
 ** moveToCourtyard() function
 **
 ** This function let's the player interact in the courtyard area.
 ** The player can either move back to the lobby, to the east hall, 
 ** or to the west hall. The function operates similarly to the other 
 ** rooms, however instead of a riddle there is a chest in the middle
 ** of the room that the player needs to open. The chest has two locks
 ** and the player needs to solve the riddles in the study rooms to
 ** retrieve both keys.
 **
 ** The function uses the virtual function menu of the relative
 ** room to let the player make decisions as to what they want to do.
 **
 *****************************************************************/

void Game::moveToCourtYard() {
    
    int callMenu;
    
    switch ( callMenu = currentSpace()->menu() ) {
            
        // Enter the Western Hall
        case 1: {
            
            delete currentArea->east;       // Delete the Courtyard's Eastern Wing
            delete currentArea->south;      // Delete the Courtyard's Lobby Wing
            
            RoomNode *temp = currentArea;   // Current Room is the Courtyard
            currentArea = temp->west;       // Current Room changed to Western Hall
            currentArea->east = temp;       // Current Room East changed to Courtyard
            currentArea->west = new RoomNode(weststudy, "Western Study", nullptr, nullptr, currentArea, nullptr);
            
            break;
        }
            
        // Enter the Eastern Hall
        case 2: {
            
            delete currentArea->west;       // Delete the Courtyard's Western Wing
            delete currentArea->south;      // Delete the Courtyard's Lobby Wing
            
            RoomNode *temp = currentArea;   // Current Room is the Courtyard
            currentArea = temp->east;       // Current Room changed to Eastern Hall
            currentArea->west = temp;       // Current Room West changed to Courtyard
            currentArea->east = new RoomNode(eaststudy, "Eastern Study", nullptr, nullptr, nullptr, currentArea);
            
            break;
        }
            
        // Enter the Lobby
        case 3: {
            
            // Rebuild the Spaces
            delete currentArea->east;     // Delete the Courtyard's Eastern Wing
            delete currentArea->west;     // Delete the Courtyard's Western Wing
            
            RoomNode *temp = currentArea; // Current Room is the Lobby
            currentArea = temp->south;    // Current Room changed to Lobby
            currentArea->north = temp;    // Current Room North changed to Courtyard
            
            break;
        }
            
        // Observe the surrounding Courtyard Area
        case 4: {
            
            currentSpace()->observe();
            
            moveToCourtYard();
            
        }
            
        // Interact with the chest in the center of the courtyard
        case 5: {
            
            cout << "\nYou approach the chest in the center of the courtyard.\n" << endl;
            
            // Iterate through the bag and check to see if they have the first key
            if ( find(bag.begin(), bag.end(), chestKeyOne) != bag.end() ) {
                
                // Iterate through the bag to see if they have the second key
                if ( find(bag.begin(), bag.end(), chestKeyTwo) != bag.end() ) {
                    
                    // Your prize is an ASCII snickers bar - congrats
                    cout << "You successfully unlocked the chest, hooray! What's inside you wonder?" << endl;
                    cout << "The prize is a...snickers bar." << endl;
                    cout << endl;
                    cout << endl;
                    cout << "<======================================================================>" << endl;
                    cout << ">                                                                      <" << endl;
                    cout << "<      ===  ||#    || ====  (=====  ||  #  =====  ||===||    ===       >" << endl;
                    cout << ">    {{     || #   ||  ||   (       || #   ||     ||   ||  {{          <" << endl;
                    cout << "<      ==   ||  #  ||  ||   (       ||#    =====  ||===||    ==        >" << endl;
                    cout << ">        }} ||   # ||  ||   (       || #   ||     ||^^         }}      <" << endl;
                    cout << "<     ===   ||    #|| ====  (=====  ||  #  =====  || ^^_    ===        >" << endl;
                    cout << ">                                                                      <" << endl;
                    cout << "<======================================================================>" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "What an incredible waste of " << player->getName() << "'s time.\n" << endl;
                    
                    runGame = false;
                    
                } else {
                    cout << "You try to open it but you don't have the second key needed to open the inner lock.\n" << endl;
                }
            } else {
                cout << "\nYou try to open it but you don't have the first key needed to open the outer lock.\n" << endl;
            }
            break;
        }
        // Show the Map
        case 6: {
            
            currentSpace()->showMap();
            cout << "Press any key to put the map away..." << endl;
            system("read");
            break;
            
        }
        // Player Health Status
        case 7: {
            
            showStatus();
            break;
            
        }
            
    } // EOF Switch Statement
}

/******************************************************************
 ** moveToEastHall() function
 **
 ** This function let's the player interact in the east hall. Unlike
 ** the courtyard/lobby, the player has to solve a riddle in order
 ** to unlock the door to the study (where the key is).
 **
 ** The function uses the virtual function menu of the relative
 ** room to let the player make decisions as to what they want to do.
 **
 *****************************************************************/

void Game::moveToEastHall() {
    
    int callMenu;
    
    switch ( callMenu = currentSpace()->menu() ) {
            
        // Enter the Eastern Study
        case 1: {
            
            if ( riddleOne == true ) {
                
                delete currentArea->west;
                RoomNode *temp = currentArea;
                currentArea = temp->east;
                currentArea->west = temp;
                
            } else {
                
                cout << "\nYou approach the door and see a placard which indicates that the next room is the Eastern Study." << endl;
                cout << "You try to open the door but it won't budge - it's sealed completely tight." << endl;
                cout << "You swear that you can hear a subtle laugh in the background...\n" << endl << endl;
                
            }
            
            break;
        }
            
        // Enter the Courtyard
        case 2: {
            
            delete currentArea->east;
            RoomNode *temp = currentArea;
            currentArea = temp->west;
            currentArea->east = temp;
            currentArea->south = new RoomNode(lobby, "Lobby", currentArea);
            currentArea->west = new RoomNode(westhall, "Western Hall", nullptr, nullptr, currentArea, nullptr);
            
            
            break;
        }
          
        // Observe the surrounding Eastern Hall area
        case 3: {
            
            currentSpace()->observe();
            
            break;
        }
            
        // Interact with the pedastal in the center of the room
        case 4: {
            
            if ( riddleOne == false ) {
                
                bool answer = currentSpace()->riddle();
                
                if ( answer ) {
                    
                    cout << "\nYou hear a grinding noise directly ahead - the door to the Eastern Study has opened.\n" << endl;
                    riddleOne = true;
                    
                } else {
                    
                    cout << "\n[You hear a distant voice laugh and whisper]" << endl;
                    cout << "Nice try " << player->getName() << " but that's wrong..." << endl;
                    cout << "[You feel a stabbing pain in your heart - you have lost 1 point of health.]\n" << endl;
                    player->reduceLife();
                    
                }
                
            } else {
                
                cout << "\nYou approach the pedastal but there is nothing to do, you've already solved the riddle and the door is open to you.\n" << endl;
                
            }
            
            break;
        }
            
        case 5: {
            
            currentSpace()->showMap();
            cout << "Press any key to put the map away..." << endl;
            system("read");
            break;
        }
            
        case 6: {
            
            showStatus();
            break;
            
        }
    } // EOF Switch Statement
}

/******************************************************************
 ** moveToEastStudy() function
 **
 ** This function let's the player interact in the east study. 
 ** The player has to solve a riddle in order
 ** to retrieve the key needed for the chest in the courtyard.
 **
 ** The function uses the virtual function menu of the relative
 ** room to let the player make decisions as to what they want to do.
 **
 *****************************************************************/

void Game::moveToEastStudy() {
    
    int callMenu;
    
    switch ( callMenu = currentSpace()->menu() ) {
            
        // Return to the Eastern Hall
        case 1: {
            
            RoomNode *temp = currentArea;
            currentArea = temp->west;
            currentArea->east = temp;
            currentArea->west = new RoomNode(courtyard, "Courtyard", nullptr, nullptr, currentArea, nullptr);
            
            break;
        }
            
        // Observe the surrounding Eastern Study area
        case 2: {
            
            currentSpace()->observe();
            
            break;
        }
            
        // Interact with the pedastal in the center of the room
        case 3: {
            
            if ( riddleTwo == false ) {
                
                bool answer = currentSpace()->riddle();
                
                if ( answer ) {
                    
                    cout << "\nA key magically appears on the pedastal before you." << endl;
                    cout << "A small inscription can be seen on the key which reads: \"Chest Key One\"" << endl;
                    cout << "You quickly place the key into your bag and move on...\n" << endl;
                    bag.push_back(chestKeyOne);
                    riddleTwo = true;
                    
                } else {
                    
                    cout << "\n[You hear a distant voice laugh and whisper]" << endl;
                    cout << "Nice try " << player->getName() << " but that's wrong..." << endl;
                    cout << "[You feel a stabbing pain in your heart - you have lost 1 point of health.]\n" << endl;
                    player->reduceLife();
                    
                }
                
            } else {
                
                cout << "\nYou approach the pedastal but there is nothing to do, you've already solved the riddle and retrieved the first chest key\n" << endl;
                
            }
            
            break;
        }
            
        case 4: {
            
            currentSpace()->showMap();
            cout << "Press any key to put the map away..." << endl;
            system("read");
            break;
            
        }
            
        case 5: {
            
            showStatus();
            break;
            
        }
    } // EOF Switch Statement
}

/******************************************************************
 ** moveToWestHall() function
 **
 ** This function let's the player interact in the west hall. Unlike
 ** the courtyard/lobby, the player has to solve a riddle in order
 ** to unlock the door to the study (where the key is).
 **
 ** The function uses the virtual function menu of the relative
 ** room to let the player make decisions as to what they want to do.
 **
 *****************************************************************/

void Game::moveToWestHall() {
    
    int callMenu;
    
    switch ( callMenu = currentSpace()->menu() ) {
            
        // Enter the Western Study
        case 1: {
            
            if ( riddleThree == true ) {
                
                delete currentArea->east;       // Delete the Courtyard
                RoomNode *temp = currentArea;   // Set a temp node to the westhall
                currentArea = temp->west;       // Set current area to the study
                currentArea->east = temp;       // Set the area east of the study to the hallway
                
            } else {
                
                cout << "\nYou approach the door and see a placard which indicates that the next room is the Western Study." << endl;
                cout << "You try to open the door but it won't budge - it's sealed completely tight." << endl;
                cout << "You swear that you can hear a subtle laugh in the background..." << endl << endl;
            }
            
            break;
        }
            
        // Enter the Courtyard
        case 2: {
            
            delete currentArea->west;
            RoomNode *temp = currentArea;
            currentArea = temp->east;
            currentArea->west = temp;
            currentArea->south = new RoomNode(lobby, "Lobby", currentArea);
            currentArea->east = new RoomNode(easthall, "Eastern Hall", nullptr, nullptr, nullptr, currentArea);
            
            break;
        }
            
        // Observe the surrounding Western Hall area
        case 3: {
            
            currentSpace()->observe();
            
            break;
        }
            
        // Interact with the pedastal in the center of the room
        case 4: {
            
            if ( riddleThree == false ) {
                
                bool answer = currentSpace()->riddle();
                
                if ( answer ) {
                    
                    cout << "\nYou hear a grinding noise directly ahead - the door to the Western Study has opened.\n" << endl;
                    riddleThree = true;
                    
                } else {
                    
                    cout << "\n[You hear a distant voice laugh and whisper]" << endl;
                    cout << "Nice try " << player->getName() << " but that's wrong..." << endl;
                    cout << "[You feel a stabbing pain in your heart - you have lost 1 point of health.]\n" << endl;
                    player->reduceLife();
                
                }
                
            } else {
                
                cout << "You approach the pedastal but there is nothing to do, you've already solved the riddle and the door is open to you." << endl;
                
            }
            break;
        }
            
        case 5: {
            
            currentSpace()->showMap();
            
            cout << "Press any key to put the map away..." << endl;
            system("read");
            
            break;
            
        }
            
        case 6: {
            
            showStatus();
            break;
            
        }
    } // EOF Switch Statement
}

/******************************************************************
 ** moveToWestStudy() function
 **
 ** This function let's the player interact in the West study.
 ** The player has to solve a riddle in order
 ** to retrieve the key needed for the chest in the courtyard.
 **
 ** The function uses the virtual function menu of the relative
 ** room to let the player make decisions as to what they want to do.
 **
 *****************************************************************/

void Game::moveToWestStudy() {
    
    int callMenu;
    
    switch ( callMenu = currentSpace()->menu() ) {
            
        // Return to the Western Hall
        case 1: {
            
            RoomNode *temp = currentArea;
            currentArea = temp->east;
            currentArea->west = temp;
            currentArea->east = new RoomNode(courtyard, "Courtyard", nullptr, nullptr, nullptr, currentArea);
            
            break;
        }
            
        // Observe the surrounding Western Study area
        case 2: {
            
            currentSpace()->observe();
            
            break;
        }
            
        // Interact with the pedastal in the center of the room
        case 3: {
            
            if ( riddleFour == false ) {
                
                bool answer = currentSpace()->riddle();
                
                if ( answer ) {
                    
                    cout << "\nA key magically appears on the pedastal before you." << endl;
                    cout << "A small inscription can be seen on the key which reads: \"Chest Key Two\"" << endl;
                    cout << "You quickly place the key into your bag and move on...\n" << endl;
                    bag.push_back(chestKeyTwo);
                    riddleFour = true;
                    
                } else {
                    
                    cout << "\n[You hear a distant voice laugh and whisper]" << endl;
                    cout << "Nice try " << player->getName() << " but that's wrong..." << endl;
                    cout << "[You feel a stabbing pain in your heart - you have lost 1 point of health.]\n" << endl;
                    player->reduceLife();
                    
                }
                
            } else {
                
                cout << "You approach the pedastal but there is nothing to do, you've already solved the riddle and retrieved the second chest key" << endl;
                
            }
            
            break;
        }
            
        case 4 : {
            
            currentSpace()->showMap();
            
            cout << "Press any key to put the map away..." << endl;
            system("read");
            
            break;
            
        }
            
        case 5: {
            
            showStatus();
            break;
            
        }
    } // EOF Switch Statement
}

/******************************************************************
 ** showStatus() function
 **
 ** Simple status function that can be called by the room menu's
 ** to display what the player's current health. It prints
 ** a little flavor text based on what the player's health is.
 **
 *****************************************************************/

void Game::showStatus() {
    
    int hp = player->getLife();
    
    if ( hp == 5 ) {
        
        cout << "\nI am feeling great. There's a very nice bounce to my step." << endl;
        cout << "[You have " << player->getLife() << " health remaining]\n" << endl;
        
    } else if ( hp == 4 ) {
        
        cout << "\nI am feeling relatively good. Just a small, dull pain in my chest and that's all." << endl;
        cout << "[You have " << player->getLife() << " health remaining]\n" << endl;
        
        
    } else if ( hp == 3 ) {
        
        cout << "\nI am feeling ok. I have definitely had better days and the pain in my chest is slightly more noticeable." << endl;
        cout << "[You have " << player->getLife() << " health remaining]\n" << endl;
        
    } else if ( hp == 2 ) {
        
        cout << "\nI am not feeling very well - something seems off...my chest is tightening up." << endl;
        cout << "[You have " << player->getLife() << " health remaining]\n" << endl;
        
    } else if ( hp == 1 ) {
        
        cout << "\nI am feeling very weak, almost as if my strength is being sapped and I have no stamina left. What is going on?" << endl;
        cout << "[You have " << player->getLife() << " health remaining]\n" << endl;
        
    }
}




