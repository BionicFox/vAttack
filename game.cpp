//Includes. | This file is where all of the base game code will be.
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
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
using std::stringstream;
//using std::atoir;

void cls();
void prompt(string tPrompt);
void mainMenu();
void stringIntConverter(string Code, string speedOfDestruction, string spreadRate, string stealth, string crypter, string optimization);

//Initialize the saves.
int sLoop = 0;
int amtSaves = 0;

//Game variables.
int code = 10;
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
    prompt("Feature in progress.");
    cls();

    mainMenu();

}

void saveGame()
{
    //Save the game.


}

void loadGame()
{
    //Load the game. In developemnt by BionicFox c:
    string saveCode;
    string saveSpeedOfDestruction;
    string saveSpreadRate;
    string saveStealth;
    string saveCrypter;
    string saveOptimization;
    ifstream save;
    int i = 0;
    ldgm: cout <<("Would you like to use the first save?\n");
    cout << ("1 = YES | 2 = NO | 3 = DIFFERENT SAVE | 4 = something>");
    cin >> i;
    cls();
    switch(i)
    {
    case 1:
        save.open("saves.vatk");
        getline(save,saveCode);
        getline(save,saveSpeedOfDestruction);
        getline(save,saveSpreadRate);
        getline(save,saveStealth);
        getline(save,saveCrypter);
        getline(save,saveOptimization);
        stringIntConverter(saveCode, saveSpeedOfDestruction, saveSpreadRate, saveStealth, saveCrypter, saveOptimization);
        save.close();
        cls();
        break;
    case 2:
        prompt("Press enter to go back to the main menu!");
        cls();
        break;
    case 3:
        prompt("I'm under development too!Press enter to go back to the main menu!");
        cls();
        break;
    case 4:
        save.open ("saves.vatk");
        getline(save,saveCode);
        cout << saveCode << "\n";
        save.close();
        cls();
        break;
    default:
        prompt("Invalid entry! Press enter to return to the load menu!");
        cls();
        goto ldgm;
    }
}

void stringIntConverter(string code, string speedOfDestruction, string spreadRate, string stealth, string crypter, string optimization)
{
    int loadCode = 0;
    int loadSpeedOfDestruction = 0;
    int loadSpreadRate = 0;
    int loadStealth = 0;
    int loadCrypter = 0;
    int loadOptimization = 0;
    stringstream convert(code);
    stringstream convert2(speedOfDestruction);
    stringstream convert3(spreadRate);
    stringstream convert4(stealth);
    stringstream convert5(crypter);
    stringstream convert6(optimization);
    convert >> loadCode;
    convert2 >> loadSpeedOfDestruction;
    convert3 >> loadSpreadRate;
    convert4 >> loadStealth;
    convert5 >> loadCrypter;
    convert6 >> loadOptimization;
    cout << loadCode << loadSpeedOfDestruction << loadSpreadRate << loadStealth << loadCrypter << loadOptimization << "\n";
    prompt("Press enter to continue");
}
