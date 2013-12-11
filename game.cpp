//Includes.
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
using std::getline;
using std::ifstream;
using std::ofstream;

void cls();
void prompt(string tPrompt);
void mainMenu();

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

game::game()
{



}

void newGame()
{
    //Start a new game.
    cls();
    cout << "Loading...\n";
    ifstream checkSave("saves.vatk");

    //Check if the save exists, if it does, ask the user to overwrite it. If it doesn't, make it, and write to it.
ifchksv:    if (checkSave)
    {
        int i = 0;
        cout << "Saved game exists, overwrite it?\n";
        cout << " 1 = YES | 2 = NO \n";
        cout << "Overwrite? > ";
        cin >> i;
        if (cin.fail())
        {
            cls();
            cin.clear(); cin.ignore(); cin.sync();
            prompt("Invalid input. Press enter to continue.\n");
            cls();
            goto ifchksv;
        } else
            {
                if (i != 0)
                {
                    checkSave.close();
                    remove("saves.vatk");
                } else
                    {
                        checkSave.close();
                        mainMenu();
                    }
            }
    } else
        {
            checkSave.close();
            ofstream createSave("saves.vatk");
            createSave << "code:" << code << "\n";
            createSave << "spreadRate:" << spreadRate << "\n";
            createSave << "speedOfDestruction:" << speedOfDestruction << "\n";
            createSave << "stealth:" << stealth << "\n";
            createSave << "crypter:" << crypter << "\n";
            createSave << "optimization:" << optimization << "\n";
            createSave.close();
        }

    cout << "Save created.\n";
    prompt("I haven't developed farther yet.");
    cls();
    mainMenu();

}

void saveGame()
{
    //Save the game.


}

void loadGame()
{
    //Load the game.

}
