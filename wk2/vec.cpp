// Vectors, Iterators, and algorithms

#include <iostream>
#include <string>
#include <vector>      //for vectors and iterators
#include <algorithm>   // for find(), sort(), random_shuflle()

using namespace std;

int main() {
    cout << "Let's learn about vectors!\n";

    vector<string> favGames = {"Dishonored", "Marathon", "Elden Ring"};

    string input;

    do {
        cout << "what would you like to do?\n";
        cout << "You can type 'push', 'quit', 'find', 'remove'.\n";

        getline(cin, input);

        if(input == "push") {
            cout << "Let's make our first vecotr of strings.\n";

            vector<string> names;

            names.push_back("finn");
            names.push_back("Lady Rainicorn");
            names.push_back("Jake");
            names.push_back("The Lich");
            names.push_back("Lemongrab");

            cout << "here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << names[i] << "\n";
            }

            cout << "There are " << names.size() << " names. \n\n";

            cout << *(names.end() - 1) << " is a dick. Let's get rid of him.\n";

            names.pop_back();

            cout << "here are you names!\n";
            for (int i = 0; i < names.size(); i++) {
                cout << "   " << names[i] << "\n";
            }

        } //end of 'push'
        else if (input == "find") {
            cout << "Let's try to use the find algorithm.\n";

            //building an iterator. it points to a 'spot' in a vecotr.
            vector<string> favs = {"Star Wars", "Kill Bill", "Ponyo"};

            vector<string>::iterator iter;

            cout << "here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "  " << favs[i] << "\n";
            }

            iter = favs.begin();

            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1;

            cout << "Now iter is pointing at " << *iter << ".\n";

            cout << "What names would you like to select?\n";
            getline(cin, input);

            iter = find(favs.begin(), favs.end(), input);

            if(iter != favs.end()) {
                cout << "We've found " << *iter << "!\n";
                cout << "Would you like to change this fav?\n";
                getline(cin, input);
                if (input == "yes") {
                    cout << "What would you like to change this fav to?\n";
                    getline(cin, input);

                    *iter = input;
                }

                cout << "Here are your updated favs!\n";
                for(int i = 0; i < favs.size(); i++) {
                    cout << "  " << favs[i] << "\n";
                }

            }
            else {
                cout << "We couldn't find that name.\n";
            }
        
        }
        else if(input == "remove") {
            sort(favGames.begin(), favGames.end());

            cout << "Here are your favorite Games:\n";

            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }

            cout << "What game would you like to remove?\n";

            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We've found that name, removing now.\n";
                favGames.erase(iter);
            }
            
            cout << "Here are your favorite Games:\n";

            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }


        }
        else if(input == "quit") {
            cout << "Thanks for playing!\n";
            break;
        }
        else {
            cout << "I did not recognize the command.\n";
        }

    } while(true);

    return 0;
}