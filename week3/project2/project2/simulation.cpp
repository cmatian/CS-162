/****************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Re-useable functions for the ZOO AND SIMULATION 
 ** class and related objects
 ****************************************************************************/

#include "simulation.hpp"

/******************************************************************
 ** SIMULATION CONSTRUCTOR
 **
 ** Creates a newZoo object and starts the game
 **
 *****************************************************************/

Simulation::Simulation() {
    
    zoo newZoo;
    
    newZoo.run();
    
}

/* NOTE TO GRADER */
// I discovered that I could basically place functions related to simulating the zoo, yet created in the zoo class inside a different cpp file.
// Because of how large my zoo.cpp file was (legibility wise), I decided to take zoo functions that were not necessarily related to the handling of
// animal object arrays (adding, removing, and resizing) and move them to the simulation.cpp file (here).
//
//


/******************************************************************
 ** RUN FUNCTION
 **
 ** Simply runs the game and calls 
 ** begin, random and event functions
 **
 *****************************************************************/

void zoo::run() {
    
    int initialAnimals;
    
    cout << "Welcome to Zoo Tycoon Simulator. In a moment, you will be asked to purchase 1 or 2 animals of each type." << endl << endl;
    
    cout << "//*******************  PURCHASE TIGER...  ******************************//" << endl;
    cout << setw(2) << ' ' << "How many Tigers would you like to purchase...?" << endl;
    cout << setw(2) << ' ' << "[1]: One Tiger -- ($10,000)" << endl;
    cout << setw(2) << ' ' << "[2]: Two Tigers -- ($20,000)" << endl;
    cout << "//**********************************************************************//" << endl << endl;
    cin >> initialAnimals;
    while (!validateBounds(initialAnimals, 1, 2)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, that is an invalid input, please select either 1 or 2 for the corresponding menu item." << endl;
        cin >> initialAnimals;
    }
    // Run a loop and add tigers
    for(int i = 0; i < initialAnimals; i++) {
        addTiger();
        tigers[i]->setAge(0);
        bank -= tigers[i]->getCost();
    }
    cout << "You purchased " << initialAnimals << " tiger(s) for $"<< initialAnimals * tigers[0]->getCost() << ".00 dollars." << endl << endl;
    
    cout << "//*******************  PURCHASE PENGUIN...  ****************************//" << endl;
    cout << setw(2) << ' ' << "How many Penguins would you like to purchase...?" << endl;
    cout << setw(2) << ' ' << "[1]: One Penguin -- ($1,000)" << endl;
    cout << setw(2) << ' ' << "[2]: Two Penguins -- ($2,000)" << endl;
    cout << "//**********************************************************************//" << endl << endl;
    cin >> initialAnimals;
    while (!validateBounds(initialAnimals, 1, 2)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, that is an invalid input, please select either 1 or 2 for the corresponding menu item." << endl;
        cin >> initialAnimals;
    }
    // Run a loop and add tigers
    for(int i = 0; i < initialAnimals; i++) {
        addPenguin();
        penguins[i]->setAge(0);
        bank -= penguins[i]->getCost();
    }
    cout << "You purchased " << initialAnimals << " penguin(s) for $"<< initialAnimals * penguins[0]->getCost() << ".00 dollars." << endl << endl;
    
    cout << "//*******************  PURCHASE TURTLES...  ****************************//" << endl;
    cout << setw(2) << ' ' << "How many Turtles would you like to purchase...?" << endl;
    cout << setw(2) << ' ' << "[1]: One Turtle -- ($100)" << endl;
    cout << setw(2) << ' ' << "[2]: Two Turtles -- ($200)" << endl;
    cout << "//**********************************************************************//" << endl << endl;
    cin >> initialAnimals;
    while (!validateBounds(initialAnimals, 1, 2)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, that is an invalid input, please select either 1 or 2 for the corresponding menu item." << endl;
        cin >> initialAnimals;
    }
    // Run a loop and add Turtles
    for(int i = 0; i < initialAnimals; i++) {
        addTurtle();
        turtles[i]->setAge(0);
        bank -= turtles[i]->getCost();
    }
    cout << "You purchased " << initialAnimals << " turtle(s) for $"<< initialAnimals * turtles[0]->getCost() << ".00 dollars." << endl << endl;
    
    cout << endl << "Press any key to continue to the beginning of the day..." << endl << endl;
    system("read");

    do {
        
        beginDay();
        
        cout << endl << "Press any key to continue to a random event..." << endl << endl;
        system("read");
        
        randomEvent();
        
        cout << endl << "Press any key to continue to the end of the day..." << endl << endl;
        system("read");
        
        endDay();
        
    } while (runGame);
}

/******************************************************************
 **
 ** RANDOM EVENT FUNCTION
 ** Produces a random event when called. The 
 ** function produces a random number and performs
 ** a certain event based on that value.
 **
 *****************************************************************/

void zoo::randomEvent() {
    // Roll is set to a number between 1 - 4
    int roll = (rand() % 4) + 1;
    
    // ANIMAL DEATH EVENT
    if (roll == 1) {
        int x = (rand() % 3) + 1;
        switch (x) {
            // Tiger Death
            case 1: {
                if(tigerCount > 0) {
                    cout << "********************************* TIGER DEATH ******************************" << endl;
                    cout << setw(2) << ' ' << "A tiger has died due to a series of unfortunate of events." << endl;
                    cout << "****************************************************************************" << endl << endl;
                    removeTiger();
                } else {
                    cout << endl << "There was an incident in the tiger savanna, but there were no tigers in the savanna to begin with. Lucky break!" << endl << endl;
                }
                break;
            }
                
            // Penguin Death
            case 2: {
                if(penguinCount > 0) {
                    cout << "************************ PENGUIN DEATH *********************" << endl;
                    cout << "A penguin has died due to a series of unfortunate of events." << endl;
                    cout << "************************************************************" << endl << endl;
                    removePenguin();
                } else {
                    cout << endl << "There was an incident in the penguin's habitat, but there were no penguins in the habitat to begin with. Lucky break!" << endl << endl;
                }
                break;
            }
                
            // Turtle Death
            case 3: {
                if(penguinCount > 0) {
                    cout << "********************** TURTLE DEATH ***********************" << endl;
                    cout << "A turtle has died due to a series of unfortunate of events." << endl;
                    cout << "***********************************************************" << endl << endl;
                    removeTurtle();
                } else {
                    cout << endl << "There was an incident in the turtle's pool, but there were no turtles in the pool to begin with. Lucky break!" << endl << endl;
                }
                break;
            }
                
            default: {
                break;
            }
        }
    // BUSINESS BOOM EVENT
    } else if (roll == 2) {
        // Generate random value between $250 - $500
        int tigerBonus = (rand() % (500 - 250)) + 250;
        
        for(int i = 0; i < tigerCount; i++) {
            bonus += tigerBonus;
            // cout << bonus << endl;
        }
        cout << "******************* BUSINESS IS BOOMING **********************" << endl;
        cout << setw(2) << ' ' << "There was a boom in zoo attendance today." << endl;
        cout << setw(2) << ' ' << "Each tiger generated an extra $" << tigerBonus << ".00 dollars" << endl;
        cout << setw(2) << ' ' << "for a total of $" << bonus << ".00!" << endl;
        cout << "**************************************************************" << endl << endl;
        
    // ANIMAL BIRTH EVENT
    } else if (roll == 3) {
        
        // Index 0 = Tigers
        // Index 1 = Penguins
        // Index 2 = Turtles
        bool adultArray[3] = {false, false, false};
        int adultCage = 0;
        
        // Parse through each object array and check for eligible adults
        // Tiger Parse
        // We need to make sure there's a tiger in the cage to begin with, otherwise we're going to be accessing a NULL value.
        if (tigerCount > 0) {
            for (int i = 0; i < tigerCount; i++) {
                if (tigers[i]->getAge() >= 3) {
                    adultArray[0] = true;
                }
            }
        }
        
        // Penguin Parse
        if (penguinCount > 0) {
            for (int i = 0; i < penguinCount; i++) {
                if (penguins[i]->getAge() >= 3) {
                    adultArray[1] = true;
                }
            }
        }
        
        // Turtle Parse
        if (turtleCount > 0) {
            for (int i = 0; i < turtleCount; i++) {
                if (turtles[i]->getAge() >= 3) {
                    adultArray[2] = true;
                }
            }
        }
        
        // Run after all arrays are parsed
        for (bool b : adultArray) {
            // If b is true, increment adultCage
            if (b) {
                adultCage++;
            }
        }
        
        // If the adult cage has a value in it, we jump into the conditional below.
        if (adultCage) {
            /*
             Explanation: I first tried to use rand() in order to get a value, but what happened was that
             rand would get caught returning the same number, even though srand() was declared (only once throughout the program) in the main.cpp.
             I had to use uniform_int_distribution in order to get a random value to work. Very strange bug.
             */
            
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 2);

            // This code basically keeps rolling a random number until it lands on one of the array's boolean values that are true
            int randAdult = dis(gen);
            while (!adultArray[randAdult]) {
                randAdult = dis(gen);
            }
            
            switch (randAdult) {
                // TIGERS
                case 0: {
                    cout << "********* TIGER BIRTH ************" << endl << endl;
                    cout << "A TIGER HAS GIVEN BIRTH TO A BABY." << endl;
                    cout << endl << "**********************************" << endl << endl;
                    for(int i = 0; i < tigers[i]->getBabies(); i++) {
                        addTiger();
                    }
                    break;
                }
                // PENGUINS
                case 1: {
                    cout << "************ PENGUIN BIRTH **************" << endl << endl;
                    cout << "A PENGUIN HAS GIVEN BIRTH TO FIVE BABIES." << endl;
                    cout << endl << "*****************************************" << endl << endl;
                    for(int i = 0; i < penguins[i]->getBabies(); i++) {
                        addPenguin();
                    }
                    break;
                }
                // TURTLES
                case 2: {
                    cout << "************ TURTLE BIRTH *************" << endl << endl;
                    cout << "A TURTLE HAS GIVEN BIRTH TO TEN BABIES." << endl;
                    cout << endl << "***************************************" << endl;
                    for(int i = 0; i < turtles[i]->getBabies(); i++) {
                        addTurtle();
                    }
                    break;
                }
                    
                default:
                    cout << endl << "There were no eligible animals to give birth." << endl << endl;
                    break;
            }
            
        } else {
            cout << endl << "There were no eligible animals to give birth." << endl << endl;
        }
    // NO RANDOM EVENT OCCURRED 
    } else {
        cout << endl << "Nothing happened today." << endl << endl;
    }
}

/******************************************************************
 ** BEGIN DAY FUNCTION
 **
 ** This function controls various elements of the
 ** beginning of each day. It ages up animals,
 ** displays animal count and cage size, and 
 ** feeds the animals.
 **
 *****************************************************************/

void zoo::beginDay() {
    // Make sure that bonus and payoff are reset to 0 because we will be manipulating them with the end of day function.
    // If we don't reset the values we'll end up incrementing them from their last held value rather than from 0.
    bonus = 0;
    payoff = 0;
    
    // Display the total animals and their cage sizes at the beginning of the day.
    cout << "//*******************  TOTAL ANIMALS  **************************//" << endl;
    
    cout << setw(2) << ' ' << "** TIGER INFORMATION" << endl;
    cout << setw(2) << ' ' << "** Total: " << tigerCount << endl;
    cout << setw(2) << ' ' << "** Cage:  " << tigerCage << endl << endl;
    
    cout << setw(2) << ' ' << "** PENGUIN INFORMATION" << endl;
    cout << setw(2) << ' ' << "** Total: " << penguinCount << endl;
    cout << setw(2) << ' ' << "** Cage:  " << penguinCage << endl << endl;
    
    cout << setw(2) << ' ' << "** TURTLE INFORMATION" << endl;
    cout << setw(2) << ' ' << "** Total: " << turtleCount << endl;
    cout << setw(2) << ' ' << "** Cage:  " << turtleCage << endl;
    
    cout << "//**************************************************************//" << endl << endl;
    
    // Age all of the animals up.
    cout << "//*****************  ANIMAL'S AGING UP  ************************//" << endl;
    
    if (tigerCount > 0) {
        for(int i = 0; i < tigerCount; i++) {
            tigers[i]->setAge((tigers[i]->getAge() + 1));
            // cout << tigers[i]->getAge() << endl;
        }
        cout << setw(2) << ' ' << "Your tigers all aged up by one!" << endl;
    } else {
        cout << setw(2) << ' ' << "There are no tigers to age up." << endl;
    }
    
    if (penguinCount > 0) {
        for(int i = 0; i < penguinCount; i++) {
            penguins[i]->setAge((penguins[i]->getAge() + 1));
            // cout << penguins[i]->getAge() << endl;
        }
        cout << setw(2) << ' ' << "Your penguins all aged up by one!" << endl;
    } else {
        cout << setw(2) << ' ' << "There are no penguins to age up." << endl;
    }
    
    if (turtleCount > 0) {
        for(int i = 0; i < turtleCount; i++) {
            turtles[i]->setAge((turtles[i]->getAge() + 1));
            // cout << turtles[i]->getAge() << endl;
        }
        cout << setw(2) << ' ' << "Your turtles all aged up by one!" << endl;
    } else {
        cout << setw(2) << ' ' << "There are no turtles to age up." << endl;
    }
    
    cout << "//**************************************************************//" << endl << endl;
    
    // Use bank money to pay for the animal feed for the day.
    cout << "//********** BEGIN THE DAY AND FEED YOUR ANIMALS ***************//" << endl;
    cout << setw(2) << ' ' << "Initializing Auto-Feeder - purchasing food for the animals..." << endl << endl;;
    
    // If tigers are in the cage, we pay for their feeding costs.
    if (tigerCount > 0) {
        for (int i = 0; i < tigerCount; i++) {
            bank -= tigers[i]->getFoodCost();
        }
        cout << setw(2) << ' ' << "The tiger feed cost you a total of $" << tigerCount * tigers[tigerCount - 1]->getFoodCost() << ".00 dollars." << endl;
    } else {
        cout << setw(2) << ' ' << "Your auto-feeder did not purchase tiger feed because there are no tigers to feed!" << endl;
    }
    
    // If penguins are in the cage, we pay for their feeding costs.
    if (penguinCount > 0) {
        for (int i = 0; i < penguinCount; i++) {
            bank -= penguins[i]->getFoodCost();
        }
        cout << setw(2) << ' ' << "The penguin feed cost you a total of $" << penguinCount * penguins[penguinCount - 1]->getFoodCost() << ".00 dollars." << endl;
    } else {
        cout << setw(2) << ' ' << "Your auto-feeder did not purchase penguin feed because there are no penguins to feed!" << endl;
    }
    
    // If turtles are in the cage, we pay for their feeding costs.
    if (turtleCount > 0) {
        for (int i = 0; i < turtleCount; i++) {
            bank -= turtles[i]->getFoodCost();
        }
        cout << setw(2) << ' ' << "The turtle feed cost you a total of $" << turtleCount * turtles[turtleCount - 1]->getFoodCost() << ".00 dollars." << endl;
    } else {
        cout << setw(2) << ' ' << "Your auto-feeder did not purchase turtle feed because there are no turtles to feed!" << endl;
    }
    cout << endl << setw(2) << ' ' << "Your current bank balance is $" << bank << ".00 dollars." << endl;
    
    cout << "//**************************************************************//" << endl << endl;
}


/******************************************************************
 ** END OF DAY FUNCTION
 **
 ** This function essentially prompts the user
 ** with several options. It first tells them 
 ** how much money they made. Then it asks them
 ** whether they would like to purchase an animal.
 ** Afterwards it determines whether the bank is 
 ** negative. If the bank is negative it closes
 ** the program. Otherwise, it allows the user to
 ** continue and loop the program to the next day,
 ** or exit the program.
 **
 *****************************************************************/

void zoo::endDay() {
    // End of Day Menu Inputs
    int buyAnimal;
    int whichAnimal;
    int continueGame;
    
    // Calc payoff for each animal
    // TIGERS
    if(tigerCount > 0) {
        for(int i = 0; i < tigerCount; i++) {
            payoff += tigers[i]->getPayoff();
        }
    }
    // PENGUINS
    if(penguinCount > 0) {
        for(int i = 0; i < penguinCount; i++) {
            payoff += penguins[i]->getPayoff();
        }
    }
    // TURTLES
    if(turtleCount > 0) {
        for(int i = 0; i < turtleCount; i++) {
            payoff += turtles[i]->getPayoff();
        }
    }
    // Add bonus and pay off to the bank
    bank += (bonus + payoff);
    
    cout << "//**********************  PROFITS  *****************************//" << endl;
    cout << setw(2) << ' ' << "The tiger's generated a bonus of $" << bonus << ".00 dollar(s)." << endl;
    cout << setw(2) << ' ' << "The total payoff from each animal (before bonus) is $" << payoff <<".00 dollar(s)." << endl;
    cout << setw(2) << ' ' << "You made a grand total of $" << bonus + payoff << ".00 dollar(s) for the day." << endl << endl;
    cout << setw(2) << ' ' << "You now have $" << bank << ".00 dollars(s) in the bank. Spend it wisely!" << endl;
    cout << "//**************************************************************//" << endl << endl;
    
    cout << "//****************  PURCHASE ADULT ANIMAL?  ********************//" << endl;
    cout << setw(2) << ' ' << "Would you like to purchase an animal?" << endl;
    cout << setw(2) << ' ' << "[1]: Yes, I would like to purchase an animal." << endl;
    cout << setw(2) << ' ' << "[2]: No, I do not want to purchase an animal." << endl;
    cout << "//**************************************************************//" << endl << endl;
    cin >> buyAnimal;
    while(!validateBounds(buyAnimal, 1, 2)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, that is an invalid input, please select either 1 or 2 for the corresponding menu item." << endl;
        cin >> buyAnimal;
    }
    
    if(buyAnimal == 1) {
        cout << "//************************  PICK ANIMAL?  **********************//" << endl;
        cout << setw(2) << ' ' << "Which Animal would you like to purchase?" << endl;
        cout << setw(2) << ' ' << "[1]: TIGER -- ($10,000)" << endl;
        cout << setw(2) << ' ' << "[2]: PENGUIN -- ($1,000)" << endl;
        cout << setw(2) << ' ' << "[3]: TURTLE -- ($100)" << endl;
        cout << "//**************************************************************//" << endl << endl;
        cin >> whichAnimal;
        while(!validateBounds(whichAnimal, 1, 3)) {
            cin.clear();
            cin.ignore();
            cout << "Sorry, that is an invalid input, please select either 1, 2 or 3 for the corresponding menu item." << endl;
            cin >> whichAnimal;
        }
        switch (whichAnimal) {
            // PURCHASE A TIGER
            case 1: {
                cout << "You have purchased a tiger aged 3 for $10,000 dollars." << endl;
                addTiger();
                tigers[tigerCount - 1]->setAge(3);
                bank -= tigers[tigerCount - 1]->getCost();
                cout << "You now have $" << bank << ".00 in the bank." << endl << endl;
                break;
            }
            case 2: {
                cout << "You have purchased a penguin aged 3 for $1,000 dollars." << endl;
                addPenguin();
                penguins[penguinCount - 1]->setAge(3);
                bank -= penguins[penguinCount - 1]->getCost();
                cout << "You now have $" << bank << ".00 in the bank." << endl << endl;
                break;
            }
            case 3: {
                cout << "You have purchased a turtle aged 3 for $100." << endl;
                addTurtle();
                turtles[turtleCount - 1]->setAge(3);
                bank -= turtles[turtleCount - 1]->getCost();
                cout << "You now have $" << bank << ".00 in the bank." << endl << endl;
                break;
            }
            default:
                break;
        } // End of Switch
        
    } // End of if conditional
    
    // Exit program if your bank is in the negatives.
    if(bank < 0) {
        cout << endl << " Bummer, your Zoo fell into debt and was foreclosed. Better luck next time!" << endl << endl;
        return;
    }
    
    // Ask the user if they would like to continue playing - this always occurs after we've determined that the bank account is not below 0
    cout << "//*******************  CONTINUE ZOO TYCOON?  *******************//" << endl;
    cout << setw(2) << ' ' << "Would you like to continue playing Zoo Tycoon?" << endl;
    cout << setw(2) << ' ' << "[1]: Continue playing Zoo Tycoon." << endl;
    cout << setw(2) << ' ' << "[2]: Quit the program." << endl;
    cout << "//**************************************************************//" << endl << endl;
    cin >> continueGame;
    while(!validateBounds(continueGame, 1, 2)) {
        cin.ignore();
        cin.clear();
        cout << "Sorry, that is an invalid input, please select either 1 or 2 for the corresponding menu item." << endl;
        cin >> continueGame;
    }
    if (continueGame == 2) {
        runGame = false;
    }
}



