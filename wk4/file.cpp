
// writing to and reading from files.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


void read(string path = "save.txt") {
    
    string line;
    ifstream readFile(path);
    if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    readFile.close();
    
}

void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);
        if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    readFile.close();
}

void write(vector<string>& vec, string path = "save.txt") {
    ofstream writeFile(path);

    if(writeFile.is_open()) {
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    }
    else {
        cout << "Couldn't open new writeFile.\n";
    }

    writeFile.close();
}



int main() {
    cout << "Let's write to a file!\n";
    vector<string> favs;
    string input = "asdf";
    
    string path = "save.txt";

    cout << "what file would you like to open?\ntype 'no' to use default.\n";
    getline(cin, input);
    if(input != "no") {
        path = input;
    }

    read(path);
    read(favs, path);

    cout << "What names would you like to add?\n";
    cout << "enter an empty line to stop.\n";
   
    while(input != "") {
        cout << "> ";
        getline(cin, input);
        // writeFile << input << endl;
        favs.push_back(input);
    }
    
    
    write(favs, path);

    return 0;
}