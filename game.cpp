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
bool fileExists(string fileExists);

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
    int getInput;
    //Start a new game.
    cls();
    cout << "Loading...\n";

    /* - Anything to be done behind the scenes while the game is loading should go here - */
    code = codeAmt;
    ifstream checkSave("game.vatk");

    ofstream save("game.vatk");
    /* - Loading area end - */

    cout << "Starting a new game will overwrite any currently saved game. Continue?\n";
    cout << "| 1 = YES | 2 = NO |\n" << "Overwrite? > ";
    cin >> getInput;
	if (cin.fail())
	{
		cin.clear(); cin.ignore(); cin.sync();
        prompt("Invalid input, press enter.");
		cls();
	}

    if (getInput == 1)
    {
		saveGame();
    } 

    cout << "Save created.\n";
    prompt("Feature in progress.");
    cls();

    mainMenu();
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
            save << "crypter:" << crypter << "\n";
            save << "optimization:" << optimization << "\n";
            save.close();
            mainMenu();
        }

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
    case 3:
        prompt("I'm under development too!Press enter to go back to the main menu!");
        cls();
        break;
    case 4:
        save.open ("game.vatk");
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
    int loadCode;
    int loadSpeedOfDestruction;
    int loadSpreadRate;
    int loadStealth;
    int loadCrypter;
    int loadOptimization;
    string saveCode = code.substr(7, 8);
    string saveSpeedOfDestruction = speedOfDestruction.substr(13, 14);
    string saveSpreadRate = spreadRate.substr(21, 22);

    stringstream convert(code.substr(7, 8));
    stringstream convert2(speedOfDestruction.substr(13, 14));
    stringstream convert3(spreadRate.substr(21, 22));
    stringstream convert4(stealth.substr(10, 11));
    stringstream convert5(crypter.substr(10, 11));
    stringstream convert6(optimization.substr(15, 16));

    convert >> loadCode;
    convert2 >> loadSpeedOfDestruction;
    convert3 >> loadSpreadRate;
    convert4 >> loadStealth;
    convert5 >> loadCrypter;
    convert6 >> loadOptimization;
    cout << loadCode << ", " << loadSpeedOfDestruction << ", " << loadSpreadRate << ", " << loadStealth << ", " << loadCrypter << ", " << loadOptimization << "\n";
    prompt("Press enter to continue");
}
