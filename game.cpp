//Includes. | This file is where all of the base game code will be.
#include <cstdlib>
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
using std::ifstream;
using std::ofstream;
using std::stringstream;

void cls();
void prompt(string tPrompt);
void mainMenu();
void stringIntConverter(string Code, string speedOfDestruction, string spreadRate, string stealth, string crypter, string optimization);
int input(string iPrompt, int i);
void saveGame();
void loadGame();
bool fileExists(const char *fileName);

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
    int getInput;
    /* - Loading area end - */

    cout << "Starting a new game will overwrite any currently saved game. Continue?\n";
    cout << "| 1 = YES  |  2 = NO  |\n" << "Overwrite? > ";
    cin >> getInput;
	if (cin.fail())
	{
		cin.clear(); cin.ignore(); cin.sync();
        prompt("Invalid input, press enter.");
		cls();
	}

    if (getInput == 1)
    {
        cls();
        cout << "Saving...\n";
		saveGame();
        cout << "Save created.\n";
        prompt("Feature in progress.");
        cls();
    }  else
        {
            mainMenu();
        }

}

void saveGame()
{
    //Save the game.
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
            save << "crypter:" << crypter << "\n";
            save << "optimization:" << optimization << "\n";
            save.close();
            mainMenu();
        }
}

void loadGame()
{
    //Load the game. In developemnt by BionicFag c:
    string saveCode;
    string saveSpeedOfDestruction;
    string saveSpreadRate;
    string saveStealth;
    string saveCrypter;
    string saveOptimization;
    ifstream save;

    int i = 0;
    ldgm: cout <<("Would you like to use the first save?\n");
    cout << ("1 = YES | 2 = NO>");
    cin >> i;
    if (cin.fail())
    {
        cin.clear(); cin.ignore(); cin.sync();
        prompt("Invalid input, press enter.");
        cls();
        loadGame();
    }
    cls();

    switch(i)
    {
    case 1:
        save.open("game.vatk");
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
    default:
        prompt("Invalid entry! Press enter to return to the load menu!");
        cls();
        goto ldgm;
    }
}

void stringIntConverter(string iCode, string iSpeedOfDestruction, string iSpreadRate, string iStealth, string iCrypter, string iOptimization)
{
    int loadCode;
    int loadSpeedOfDestruction;
    int loadSpreadRate;
    int loadStealth;
    int loadCrypter;
    int loadOptimization;
    string saveCode = iCode.substr(5, 6);
    string saveSpeedOfDestruction = iSpeedOfDestruction.substr(11, 12);
    string saveSpreadRate = iSpreadRate.substr(19, 20);
    string saveStealth = iStealth.substr(8,9);
    string saveCrypter = iCrypter.substr(8,9);
    string saveOptimization = iOptimization.substr(13,14);

    stringstream convert(saveCode);
    stringstream convert2(saveSpeedOfDestruction);
    stringstream convert3(saveSpreadRate);
    stringstream convert4(saveStealth);
    stringstream convert5(saveCrypter);
    stringstream convert6(saveOptimization);

    convert >> loadCode;
    convert2 >> loadSpeedOfDestruction;
    convert3 >> loadSpreadRate;
    convert4 >> loadStealth;
    convert5 >> loadCrypter;
    convert6 >> loadOptimization;
    code = loadCode;
    speedOfDestruction = loadSpeedOfDestruction;
    spreadRate = loadSpreadRate;
    stealth = loadStealth;
    crypter = loadCrypter;
    optimization = loadOptimization;
    prompt("Game loaded. Press enter to continue");
}
