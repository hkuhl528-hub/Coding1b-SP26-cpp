// slime battles

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> names = {"Alfred", "Barbara", "Quintin", "Sandra", "Glenn", "Betty"};

class baseSlime {
public: 
    string name;
    int health;
    int damage;

    int startingHealth = 0;

    // default constructor
    baseSlime() {
        cout << "A new slime has been born.\n";
        name = names[rand() % names.size()] + " Slime";
        health = rand() % 4 + 4;
        startingHealth = health;
        damage = rand() % 3 + 3;
    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
    }

    // attack another slime
    // return true if opponent is less then or equal to 0
    bool attack(baseSlime& opponent) {
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

class bossSlime : public baseSlime {
public:
    int damageMultiplier = 3;

    //  constructor for boss
    // this runs after the baseSlime
    bossSlime() {
        name = "boss";
        damage = damage * damageMultiplier;
    }

    bool attack(baseSlime& opponent) {
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

    void taunt() {
        cout << "I will crush your bones with my slime!\n";
    }
};

int main () {
    srand(time(0));                         // seed the random number generator
    cout << "SLIME BATTLES\n";

    // create slime
    baseSlime gerald;
    gerald.name = "Gerald";
    gerald.hello();

    bossSlime destroyer;
    destroyer.name = "Destroyer";
    destroyer.hello();
    destroyer.taunt();

    cout << "Gerald is feeling cheeky...\n";
    gerald.attack(destroyer);

    cout << "Destroyer is enraged!\n";
    if (destroyer.attack(gerald)) {
        cout << "Gerald is no more. DED.\n";
    }

    // create a vector of slimes
    // pick 2 to fight
    // global varaibles
    
// create vector of slimes with output of six
    vector<baseSlime> sludge(6);

    cout << "Here's our sludge of slimes:\n\n";
    for(auto& slime : sludge) {
        cout << slime.name << "\n";
    }

    random_shuffle(sludge.begin(), sludge.end());

    auto& a = sludge[0];
    auto& b = sludge [1];

    cout << a.name << " is fighting " << b.name << "!!!\n\n";

    while(a.health > 0 && b.health > 0) {
        if(a.attack(b)) {
            cout<< b.name << " has been defeated by " << a.name << ".\n";
        }
        else {
            if (b.attack(a)) {
                cout << a.name << " has been defeated by " << b.name << ".\n";
            }
        }
    }

    return 0;
}