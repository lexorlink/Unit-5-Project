#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<char, int> counter;
    char characterCounter;
    string userFilePath;
    int wordCount = 0;

    cout << "----------Welcome to Word Counter----------" << endl;
    cout << "Enter your file path or type 'exit' to close the program" << endl;
    getline(cin, userFilePath);

    if (userFilePath == "exit" || userFilePath == "Exit") {
        cout << "Ending program ..." << endl;
        return 0;
    }

    ifstream inFile(userFilePath);
    if (!inFile) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    string line;

    //Counts Words
    string word;
    while (inFile >> word){
        wordCount++;
    }

    //Reset File
    inFile.clear();
    inFile.seekg(0);


    int totalCharacters = 0;

    //Counts Characters
    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
        totalCharacters++;
    }

    cout << "This document contains: " << wordCount << " words" << endl;
    cout << "This document contains " << totalCharacters << " characters." << endl;

    //Reset File again
    inFile.clear();
    inFile.seekg(0);
    
    //Outputs the text
    cout << "\n----- File Contents -----" << endl;

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    cout << "-------------------------" << endl;

    //Closes the File
    inFile.close();

    return 0;
}
