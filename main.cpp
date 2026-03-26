// Hayden Kuhl Coding 1 spring 2026
// Our first c++ program

// to compile, open the 'Developer Command Prompt for VS 2022'
// navigate to this folder with 'cd' for 'change directory'
// 
// 

#include <iostream>  // in out stream, for sending text to console.
#include <string> // for player name

using namespace std;    // so we don't have to type "std::" all the time.

// here is where we start the program
int main() {
    // variables declared at the top is best practice
    string playerName;    // variables use camelCase

    cout << "What is your name, player? ";

    cin >> playerName;

    cout << "Hello " << playerName << "." << endl;

    // cout << "You freaking rock yo" << endl;    // endl =  end line

    return 0;     //end the program
}