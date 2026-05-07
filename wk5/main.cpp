// week 15

// self-documenting code means the code can only do one thing, or be used one way.


#include <iostream>
#include <string>
using namespace std;

// classes are custom variable types
// variables
// functions

// constructors
// getters and setters (privacy)

class robot {
private:
    string name;
    int charge;
    int boredom;

public:
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    robot() {
        name = "ROB";
        charge = 10;
        boredom = 10;
        status();
    }

    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";

        if(boredom < 5) cout << "Happy";
        else if(boredom < 10) cout << "Bored";
        else if(boredom < 15) cout << "Frustrated";
        else cout << "ENRAGED";

        cout << ".\n";


    }

    string getName() {
        return name;
    }

    int getCharge() {
        return charge;
    }

    int getBoredom() {
        return boredom;
    }


    void setName(string givenName) {
        if(givenName.size() <= 5){   
            name = givenName;
        }
        else {
            cout << "error: " << givenName << " is too long.\n";
        }
     
    }

    void setCharge(int givenCharge) {
        if(givenCharge < 0) {
            charge = 0;
        }
        else if(givenCharge > 100) {
            charge = 100;
        }
        else {
            charge = givenCharge;
        }

    }

    void setBoredom(int givenBoredom) {
        if(givenBoredom > 20) boredom = 20;
        boredom = givenBoredom;
    }

    void changeChargeBy (int amount = 1) {
        setCharge(charge += amount);
    }

};


int main() {
    cout << "Classes!\n";

    // create our first instance of a robot.
    robot artoo("R2-D2", 45, 3);
    // artoo.name = "R2-D2"; // dot syntax
    // artoo.charge = 45;
    // artoo.boredom = 3;
    cout << "Artoo has " << artoo.getName().size() << " letters in their name.\n";

    robot threepio;
    threepio.setName("C-3PO");
    threepio.setCharge(2);
    threepio.setBoredom(12);

    artoo.status();
    threepio.status();

    cout << "Threepio has low battery, let's have artoo charge him up!\n";

    while(threepio.getCharge() < 15) {
        if(artoo.getCharge() > 0) {        
            artoo.changeChargeBy(-1);
            threepio.changeChargeBy(1);
        }
        else {
            cout << "artoo is out of energy!\n";
            break;
        }
     }

    artoo.status();
    threepio.status();

    return 0;
}