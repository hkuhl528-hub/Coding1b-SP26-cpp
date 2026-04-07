// Arrays, for loops, enums, and switch statements

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {\
    srand(time(0));
    cout << "Let's make some arrays!\n";

    // arrays cannot change their size
    // arrays dont know where the "last index" is
    // arrays are a list of similar variable type
    // arrays are ordered

    int scores[5];

    scores[0] = 4545;
    scores[1] = 13;
    scores[2] = 9001;
    scores[3] = 2456;
    scores[4] = -4;
    // scores[5] = 99999;

    cout << "The first score is " << scores[0] << ".\n";

    cout << "Here are all of the scores:\n";

     int index = 0;
    while(index < 5){
        cout << scores [index] << ".\n";
        index++;
    }

    cout << "Using a for loop:\n";

    // for loop has the 'iterator' built in.
    for(int i = 0; i<5; i++) {
        cout << scores[i] << "\n";
    }

    // lets build a string array for names
    string names[10];
    string input;
    index = 0; //reset index
   
    while(index < 10) { 
        // we want the user to add names to the array
        cout <<"type name, or done: ";
        cin >> input;

        // until they type 'done'
        if (input == "done"){
            cout << "Done adding names.\n";
            break;
        }

        // add the name to the array
        // then add 1 to index with the increment operator
        names [index++] = input;

    }
    
    // show the list of names
    for(int i = 0; i < index; i++) {
        if(names[i] == "") {
            continue;
        }

        cout << names[i] << ".\n";
    }

    // create a new string array
    string newNames[] = {"Mario", "Luigi", "Peach", "Captain Toad", "Bowser", "Rosalina", "Yoshi", "Bowser Jr."
 };
    
    cout << "Here are the new names: \n";
    for(int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << newNames[i] << "\n";
    }

    
    // pick a randome name from our newNames array
    int randIndex = rand() % 8;
    string character = newNames[randIndex];

    cout << character << ", let's talk about them.\n";

    // an enumerator is a custome variable type
    // with only the values specified
    // they correspond to numbers, starting with 0 by default.
    enum favor {LOVE, LIKE, DISLIKE, LOATHE};
    enum Difficulty {EASY, MEDIUM, HARD, IMPOSSIBLE};
    

    switch(rand() % 4) {
        case LOVE:
            cout << "I love " << character << ".\n";
            break;
        case LIKE:
            cout << "I like " << character << ".\n";
            break;
        case DISLIKE:
            cout << "I dislike " << character << ".\n";
            break;
        case LOATHE:
            cout << "I loathe " << character << ".\n";
            break;
    }

    return 0;
}