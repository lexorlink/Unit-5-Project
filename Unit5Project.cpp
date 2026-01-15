#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    map<char, int> counter;
    char characterCounter;
    string userFilePath;
    int wordCount = 0;

    cout << "----------Welcome to Word Counter----------" << endl;
    cout << "Enter your file path or type 'exit' to close the program" << endl;
    cin >> userFilePath;

    if (userFilePath == "exit" || userFilePath == "Exit") {
        cout << "Ending program ..." << endl;
        return 0;
    }

    ifstream inFile(userFilePath);
    if (!inFile) {
        cout << "Failed to open file." << endl;
        return 1;
    }else {
        
    }

    while (getline(inFile, word)) {
        stringstream ss(word);
        string word;
        while (ss>word){
            wordCount++;
        }
    }
    infile.clear();


    int totalCharacters = 0;

    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
        totalCharacters++;
    }

    inFile.close();

    cout << "This document contains: " << wordCount << "words" << endl;
    cout << "This document contains " << totalCharacters << " characters." << endl;

    return 0;
}