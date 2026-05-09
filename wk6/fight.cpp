// Create a .cpp program that allows the player to 




// battle other critters, with options to
// attack
// heal
// run away

// Your program needs the following features

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> names = {"Ze", "Loe", "Gro", "Meep", "Querp"};

class baseG {
public:
    string name;
    int health;
    int damage;
    int hunger;

    int startingHealth = 0;
    int startingHunger = 0;

    baseG () {
        cout << "A wild gecko has come up to you.\n";
        name = "GURT";
        damage = 5;
        health = 10;
        hunger = 0;
        startingHealth = health;
        startingHunger = hunger;
    };

    void hello () {
        cout << "HI!!!!!! MY NAME IS " << name << " AND I GOT " << damage << " DAMAGE ";
        cout << "AND " << health << " HEALTH!\n";
    };
    
    // feed their critter
    
    void feed () {
        hunger = startingHunger;
        cout << "I'm no longer hungry :D\n";
    } 

    // train their critter (chance to increase health or damage)

    void train () {
        int num = rand() % 10 + 1;

        if (num <= 5) {
            health ++;
            cout << "My health is now " << health << "!\n";
        }
        else if (num > 5) {
            damage ++;
            cout << "My damage is now " << damage << "!\n";
        }

    }

    void hungry () {
        cout << "I'm feeling a little hungry.\n";
    }

    void starving () {
        cout << "PLEASE FEED ME!\n";
    }

    void death () {
        cout << "IT DIED! \nwhy wouldn't you feed it?\n";
    }
    
    // listen to their critter (display health, damage, and hunger)
    
    void display () {
        cout << "I got " << damage << " damage, " << health << " health, and " << hunger << " hunger.\n";
    }

    bool attack(baseG& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void heal() {
        health += 5;
    }

};

class enemyG : public baseG {
public:

    enemyG () {
        name = names[rand() % names.size()];
        health = rand() % 10 + 10;
        damage = rand() % 5 + 8;
    }

        bool attack(baseG& opponent) {
        // cout << "This is a boss attack!\n";
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0) {
             return true;
        }
        else {
            return false;
        }
    }


};


int main () {
    srand(time(0));

    string input;

    cout << "Gecko Battles!\n";

    baseG albert;
    albert.hello();
   
    // name a 'critter' (or 'monster', or 'robot', or 'slime', or 'puppy' - whatever you like!)

    cout << "Would you like to change its name?\n";

    getline(cin, input);

    if (input == "yes") {
        cout << "What do you want to change it to?\n";
        getline(cin, input);
        albert.name = input;
        cout << "The geckos name is now " << albert.name << ".\n";
    }
    else {
        cout << "Lame\n";
    };

    while(true) { 

    cout << "What would you like to do with " << albert.name << "?\n";
    cout << "'feed', 'train', 'fight', 'display', or are you 'done'?\n";
    getline(cin, input);

    if (input == "feed"){
        albert.feed();
    }

    else if (input == "display"){
        albert.display();
    }

    else if (input == "done"){
        cout << "Come again soon!\n";
        return 0;
    }

    else if (input == "train"){
        albert.train();
        albert.hunger ++;

        if (albert.hunger <= 5) {
            cout << "Let's keep going!\n";
        }
        else if (albert.hunger <= 10) {
            albert.hungry();
        }
        else if (albert.hunger <= 15) {
            albert.starving();
        }
        else if (albert.hunger <= 20) {
            albert.death();
            return 0;
        }
    }

    else if (input == "fight") {

        enemyG op;
        cout << "My name is " << op.name << " and I am the one you will be facing!\n";
        cout << "This one seems strong, what should you have " << albert.name << " do?\n";
        
        while(op.health > 0&& albert.health > 0) { 

            cout << op.name << " has " << op.health << " health.\n";
            cout << "'attack', 'heal', 'display', or 'run'\n";
            getline(cin, input);

            if (input == "attack") {
                albert.attack(op);
                if (op.health == 0) {
                    cout << "You've beat " << op.name << "!\n";
                }
                op.attack(albert);
            }
        
            else if (input == "heal") {
                albert.heal();
                cout << albert.name << " now has " << albert.health << " health.\n";
                op.attack(albert);
            }

            else if (input == "display"){
                albert.display();
            }   

        
            else if (input == "run") {
                op.health = 0;
            }
                if (op.health <= 0) {
                cout << "You've won the fight!\n";
            }        
            
            if (albert.health <= 0){
                cout << "Your gecko has died.\n";

                return 0;
            }



        }

       
    }




}
   
    return 0;
}

// a randomized list of names must be read from a separate text file
// setters and getters must be implemented for all class variables (class variables should be private)
// critter class must have a constructor
// each battle or training adds 1 to the critter's hunger.
// if their hunger is greater than 10, they can't train or battle.
// if their hunger is greater than 5, they'll mention it each time they train or battle