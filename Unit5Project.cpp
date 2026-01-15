#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<char, int> counter;
    char characterCounter;
    string userFilePath;

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
    }
    else {
            string word;
            int wordCount = 0;
            while (inFile >> word) {
                    wordCount++;
                }
            cout << "This document contains: " << wordCount << "words" << endl;

    }
    
    int totalCharacters = 0;

    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
        totalCharacters++;
    }

    inFile.close();

    cout << "This document contains " << totalCharacters << " characters." << endl;

    return 0;
}