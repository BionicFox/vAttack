//Includes. | This file is where all of the base game code will be.
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "game.h"
#include "main.h"
#include "baseFunctions.h"

//We'll just use what we need.
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void cls();
void prompt(string tPrompt);
void mainMenu();
int input(string iPrompt, int i);
void saveGame();
void loadGame();
bool fileExists(string fileExists);

//Initialize the saves.
int sLoop = 0;
int amtSaves = 0;

//Game variables.
int code = 0;
int spreadRate = 0;
int speedOfDestruction = 0;
int stealth = 0;
int crypter = 0;
int optimization = 0;

string gName = "vAttack";
string gVersion = "Alpha 0.1.0";

game::game()
{
    
    
    
}

void newGame(int codeAmt)
{
    //Start a new game.
    cls();
    cout << "Loading...\n";
    
    /* - Anything to be done behind the scenes while the game is loading should go here - */
    code = codeAmt;
    int getInput;
    ofstream save("game.vatk");
    /* - Loading area end - */
    
    cout << "Starting a new game will overwrite any currently saved game. Continue?\n";
    cout << "| 1 = YES | 2 = NO |\n" << "Overwrite? > ";
    input("Overwrite? > ", getInput);
    
    if (getInput == 1)
    {
        if (fileExists("game.vatk"))
        {
            save.close();
            remove("game.vatk");
            saveGame();
        } else
            {
                save.close();
                saveGame();
            }
    } else
        {
            save.close();
            mainMenu();
        }
}

void saveGame()
{
    //Save the game.
    cls();
    cout << "Saving...\n";
    
    if (fileExists("game.vatk"))
    {
        remove("game.vatk");
        saveGame();
    } else
        {
            ofstream save("game.vatk");
            save << "code:" << code << "\n";
            save << "spreadRate:" << spreadRate << "\n";
            save << "speedOfDestruction:" << speedOfDestruction << "\n";
            save << "stealth:" << stealth << "\n";
            save << "crypter" << crypter << "\n";
            save << "optimization:" << optimization << "\n";
            save.close();
            mainMenu();
        }
}

void loadGame()
{
    //Load the game.

}
