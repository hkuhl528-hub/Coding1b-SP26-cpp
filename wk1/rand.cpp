// Random numbers, Switch Statements, and while loops

#include <iostream>
#include <cstdlib>  // for srand and rand
#include <ctime>  // for time

using namespace std;

int main() {
    // only once, at the beginning of the program
    // seed the random number generator
    srand(time(0));

    cout <<"Random Numbers\n";

    cout <<"Here is our first random number: " <<rand() << ".\n";

    int counter = 0;
    while(counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min;      // 50 
        int clampedNumber = (number % range) + min;

        cout << clampedNumber << endl;
    }

    // set variables 
        // the random number
        int number = (rand () % 10) + 1;

        // the guess/input
        int guess = -1;
   
    cout << "I'm thinking of a number between 1 and 10. Take a guess.\n>>";
        // start loop
    while(true) {
    // get player's guess/input
        cin >> guess;
    // evaluate the player's guess for
        // too high
        if(guess > number){
            cout << "Too High!\n";
        }
        // too low
        else if (guess < number){
            cout << "Too Low!\n";
        }
        // correct!
        else {
            cout << "Correct! Thanks for playing!\n";
            // break out of loop
            break;
        }
    }


    return 0;
}

