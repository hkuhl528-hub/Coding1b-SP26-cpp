//  Functions

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std; 



void sayHello () {
    cout << "Hello!\n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";
}

int dieRoll(int sides = 6) {
    return rand() % sides + 1;
}

bool askYesNo(string question = "Do you want to keep playing?") {
    while(true) { 
        cout << question << " 'yes' 'no' \n";
        string input;
        getline(cin, input);

        if(input == "yes") {
            return true;
        }
        else if(input == "no") {
            return false;
        }
        else {
            cout << "I did not understand. Please type 'yes' or 'no'.\n";
        }
    }
   
}

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

    // showVec(vec);
}


int main() {
    srand(time(0)); 
    vector<string> names = {"Finn", "Jake", "Gumball", "Darwin", "Mordecai", "Rigby"};

    showVec(names);

    addStringToVec(names);

    showVec(names);

    cout <<"Finally, functions!\n";

    sayHello();

    doAddition(32, 54);

    doAddition(dieRoll(), dieRoll());

    cout << "let's roll the dice! Our first number is " << dieRoll(6) << ".\n";

    if(askYesNo()) {
        cout << "let's start the next level!\n";
    }
    else {
        cout << "Thanks for playing!\n";
        return 0;
    }

    if(askYesNo("Do you like waffles?")) {
        cout << "Hell yea!\n";
    }
    else {
        cout << "how can you not like waffles you fucking asshole.\n";
    }

    return 0;
}