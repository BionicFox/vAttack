//Includes.
#include <fstream>
#include <iostream>
#include <string>
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
void newGame();
void mainMenu();

//Location the user is in the game, used for labeling input.
string currentMenu = "____LOADING____";

//All variables.
string gName = "vAttack";
string gVersion = "Alpha 0.1.0";
    
//Files.
string line;
ifstream information;

int main()
{
    //Run the main menu loop, and wait for instruction.
    mainMenu();

    return 0;
}

void mainMenu()
{ 
    //General input variables for the game.
    int uInp;
    
    //Loop variables.
    int mLoop = 0;
    
    //Menu loop.
    while (mLoop <= 10)
    {
        mLoop = 0;
        //Main menu.
        currentMenu = "Main";
        cout << "Welcome to " << gName << "\nVersion: " << gVersion << "\n";
        cout << "================================================\n";
        cout << "| 1 = New game | 2 = Load game | 3 = Save game |\n";
        cout << "|   4 = Help   |   5 = About   |   9 = Exit.   |\n";
        cout << "================================================\n";
        cout << currentMenu << " > ";
        cin >> uInp;
        
        //Make sure the input is an int.
        if (cin.fail())
        {
            cin.clear(); cin.ignore(); cin.sync();
            mLoop++;
        }
        
        cls();
        
        switch(uInp)
        {       
            case 9:
                //Exit the game.
                mLoop = 11;
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
                }
                
            case 3:
                //TODO: Save the game.
                
            case 2:
                //TODO: Load a game.
                
            case 1:
                newGame();
                
            default:
                prompt("Not a menu item, press enter.");
                cls();
        }
        
        //Continue the loop.
        mLoop++;
    }
    
    //Make sure the file is closed before exit.
    information.close();
}