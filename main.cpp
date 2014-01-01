//Includes. | This file will handle the first load, and code fuctions.
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "game.h"
#include "main.h"
#include "baseFunctions.h"

//We'll only use what we need.
using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::ifstream;

void cls();
void prompt(string tPrompt);
void newGame(int codeAmt);
void mainMenu();
void loadGame();
<<<<<<< HEAD
void saveGame();
=======
void saveGame(); 
>>>>>>> upstream/master

//Variables and files.
string gameName = "vAttack";
string gameVersion = "Alpha 0.1.0";

string line;
ifstream information;

int main()
{
    cout << "Loading...\n";
    mainMenu();

    return 0;
}

void mainMenu()
{
    cls();
    int uInp;
    int mLoop = 0;

    while (mLoop != 1)
    {
        cout << "Welcome to " << gameName << "\nVersion: " << gameVersion << "\n";
        cout << "================================================\n";
        cout << "| 1 = New game | 2 = Load game | 3 = Save game |\n";
        cout << "|   4 = Help   |   5 = About   |   9 = Exit    |\n";
        cout << "================================================\n";
        cout << "Main > ";
        cin >> uInp;

        //Make sure the input is an int.
        if (cin.fail())
        {
            cin.clear(); cin.ignore(); cin.sync();
            prompt("Invalid input, press enter.");
        }

        cls();

        switch(uInp)
        {
            case 9:
                //Exit the game.
                exit(0);
                break;

            case 5:
                //Show information about the game.
                information.open("about.txt");
                if (information.is_open())
                {
                    while (getline(information,line)) { cout << line << "\n"; }
                    prompt("Press enter to return to the main menu.");
                    information.close();
                    cls();
                    break;
                } else { prompt("Unable to open file. Press enter to return to main menu."); information.close(); break; }

            case 4:
                //Help the poor user figure out what this is.
                information.open("help.txt");
                if (information.is_open())
                {
                    while (getline(information,line)) { cout << line << "\n"; }
                    prompt("Press enter to return to the main menu.");
                    information.close();
                    cls();
                    break;
                } else { prompt("Unable to open file. Press enter to return to main menu."); information.close(); break; }

            case 3:
                saveGame();
                break;

            case 2:
                loadGame();
                break;

            case 1:
                newGame(10);

            default:
                prompt("Not a menu item, press enter.");
                cls();
        }

    }

    //Make sure the file is closed before exit.
    information.close();
}
