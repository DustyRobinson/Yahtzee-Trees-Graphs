/* 
 * File:   main.cpp
 * Author: Steven
 *
 * Created on May 23, 2023, 10:29 PM
 */

 //System Libraries
#include <iostream> //Input - Output Library
#include <ctime>    //Time for rand
#include <cstdlib>  //Srand to set the seed
#include<string>	//String Library
#include <fstream>

using namespace std;

//User Libraries
#include "PlayGame.h"

//Global Constants - Math/Physics/Chemistry/Conversions/Higher Dimensions

//Function Prototypes

int main(int argc, char** argv) {

    //Setting the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare values
    PlayGame game;
    fstream txt;
    
    //Initialize Variables
    char c = ' ';
    int choice = 0;
    //Map Input to the Outputs - Process
   
    // Do while Loop and Display menu and start the game
    do
    {
        // nested loop, one to check what mode the player wants and second loop prompts user to quit game or keep going
        do
        {
            //displays menu and prompts using choice for either play game or read rule book
            game.menu();
            cin >> choice;
            switch (choice)
            {
                //starts game if chosen
            case 1:
                game.playGame();
                break;
                //displays rules of game
            case 2:
                game.prtRules(txt);
                break;
                //check if choice is valid
            default:
                cout << "Invalid selection" << endl;
                break;
            }
        } while (choice >= '1' && choice <= '2');
        
        //prompts user if they want to quit the game or continue
        cout << "Do you what to quit? y/n" << endl;
        cin >> c;
        
        //checks if condition is met
    } while (toupper(c) == 'N');
    
    // end of program
    return 0;
}


