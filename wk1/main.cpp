// Variables and Logic

// compile with the Developer Command Prompt
// 'cl /EHsc main.cpp' is what you type to compile
// 'main' or 'main.exe' to run the program.

#include <iostream>
using namespace std;
bool debug = false;

int main() {
    cout << "let's learn about variables and logic!\n";

    // declaring and defining variables
    int playerAge = -1;
    string playerName = "Darth Vader";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    // just like a branch in unreal
    // if (the test is true) run this code
    if(playerAge == -1) {
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge <= 12) {
            cout << "I'm sorry, this game is for grownups!\n";
            return 0;
        }
        else {
            cout << "Wow, " << playerAge << " years, that is a long time!\n";
        } 
        
    }

    if(playerName == "Darth Vader") {
        cout << "is your name " << playerName << "?\n";
        string input;
        cin >> input;
        if(input == "yes" ||input == "Yes" ||input == "yea" ||input == "YES") {
            cout << "Well, that's convenient!\n";
        }
        else{
            cout << "What is your name?\n";
            cin >> playerName;
        }

        cout << "Hello " << playerName << ".\n";
    }

    if (playerAge == 18 && playerName == "Hayden"){
        debug = true;
        cout << "Hello Creator, debug mode is ON.\n";
    }

    if(debug) {
        cout << "\n\tDEBUG MODE\n\n";
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercent = " << happinessPercent << ".\n";
        cout << "keepPlaying = " << keepPlaying << ".\n";
    }

    





    return 0;

} // end of main()



