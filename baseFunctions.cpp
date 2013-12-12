//Includes. | This file will include base functions that will be used across most of the other source files.
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "game.h"
#include "main.h"
#include "baseFunctions.h"

using std::cout;
using std::cin;
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
