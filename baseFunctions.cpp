//Includes. | This file will include base functions that will be used across most of the other source files.
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "game.h"
#include "main.h"
#include "baseFunctions.h"

using std::cout;
using std::cin;
using std::string;
using std::ifstream;

void newGame(int codeAmt);

baseFunctions::baseFunctions()
{
    
    
    
}

void cls()
{
    //Clear the screen.
    for(int i = 0; i <= 10; i++)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n";
    }
}

void prompt(string tPrompt)
{
    //Wait for the enter key to be pressed.
    cout << tPrompt;
    cin.get();
    cin.ignore();
}

int input(string iPrompt, int i)
{
    //Get input from a user.
    cout << iPrompt;
    cin >> i;
    if (cin.fail())
    {
        cin.clear(); cin.ignore(); cin.sync();
        cls();
        prompt("Invalid input. Press enter to go back.\n");
        newGame(10);
    } else
        {
            return i;
        }
    cout << "\n";
}

bool fileExists(string fileName)
{
    ifstream file(fileName.c_str());
    if (!file)
    {
        return 0;
    } else { return 1; }
}