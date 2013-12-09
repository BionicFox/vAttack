//Includes.
#include <fstream>
#include <iostream>
#include <string>
#include "game.h"
#include "main.h"
#include "baseFunctions.h"
#include "base64.h"

//We'll only use what we need.
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

void cls();
void prompt(string tPrompt);

game Game;

//Location the user is in the game, used for labeling input.
string currentMenu = "____LOADING____";

int main()
{
    //All variables.
    string gName = "vAttack";
    string gVersion = "Alpha 0.1.0";
    
    //Files.
    string line;
    ifstream information;

    //General input variables for the game.
    int uInp;
    
    //General game variables.
    int code = 0;
    
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
            cin.clear();
            cin.ignore();
            cin.sync();
            mLoop++;
        }
        
        cls();
        
        switch(uInp)
        {
            case 666:
                {
                    //An easter egg.
                    string key;
                    cout << "What is the key (Start/load a game FIRST if you haven't already!)? ";
                    cin >> key;
                    if (cin.fail()) { cin.clear(); cin.ignore(); prompt("The gates shall not open. Press enter to return to the main menu.\n"); cls(); break; }
                
                    if (key == "0x2fe223")
                    {
                        cout << "You have been given the treasures of the hacker before you. (+5 code)\n";
                        code += 5;
                        prompt("Press enter to return to main menu.");
                        cls();
                        break;
                    } else { prompt("The gates shall not open. Press enter to return to the main menu.\n"); cls(); break; }
                }
                
            case 42:
                //Get the key for the easter egg.
                cout << "The key is: 0x2fe223, you will find the lock at the gates of hell.\n";
                prompt("Press enter to return to the main menu.");
                cls();
                break;
                
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
                //TODO: Create a new game.
                
            default:
                prompt("Not a menu item, press enter.");
                cls();
        }
        
        //Continue the loop.
        mLoop++;
    }
    
    //Make sure the file is closed before exit.
    information.close();
    return 0;
}
