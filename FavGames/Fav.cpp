// Get everything included
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// namespace lol
using namespace std;
// set up main 
int main() {
    vector<string> favGames = {"Marathon", "Darksouls 3", "Apex Legends", "BTD6", "Raccoin", "Cuphead", "Dispatch", "Megabonk", "Overwatch", "Palworld", "REPO", "Skate", "Destiny"};

    string input;

    do {
        // Ask the player what they want to do
        cout << "Here are your current favorite games, what would you like to do with them?\n";

        sort(favGames.begin(), favGames.end());

        for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
        }
        // give them the options
        cout << "'add', 'edit', 'remove', 'quit', 'show'.\n";
        // get line
        getline(cin, input);
        
        // setup add
        if(input == "add") {
            cout << "What game would you like to add to the list?\n";

            getline(cin, input);
            favGames.push_back(input);
        }
        // setup quit
        else if(input == "quit"){
            cout << "Thanks for playing!\n";
            break;
        }
        // setup edit
        else if(input == "edit") {
            vector<string>::iterator iter;

            iter = favGames.begin();

            cout << "Please pick a game you would like to edit.\n";
            getline(cin, input);

            iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()){
                cout << "We've got " << *iter << ". Do you want to change it?\n";
                getline(cin, input);
                if(input == "yes"){
                    cout << "What do you want to change it to?\n";
                    getline(cin, input);

                    *iter = input;
                }
            }
        }
        else if(input == "remove") {
            cout << "What game would you like to remove?\n";

            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We've found that name, removing now.\n";
                favGames.erase(iter);
            }
        }
        else if(input == "show") {
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }
        }
    } while (true);
    return 0;
}    

 





// 