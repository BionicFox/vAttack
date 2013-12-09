//Includes.
#include <fstream>
#include <iostream>
#include <string>
#include "game.h"
#include "main.h"
#include "baseFunctions.h"
#include "base64.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

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