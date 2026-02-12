#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

//C:\\Users\\89173\\U-5-text.txt 

map<char, int> counter;

void charCounter(ifstream& inFile);
void wordCounter(ifstream& inFile);
void textOutput(ifstream& inFile);

int main() {

    string userFilePath, start;
    int toolChoice, rerunNum;

    cout << "----------Welcome to Word Counter----------" << endl;
    cout << "Enter 'start' to begin the program" << endl;
    cin >> start;
    
    while (start == "start"){

        cout << "Enter your file path or type 'exit' to close the program" << endl;
        cin.ignore();
        getline(cin, userFilePath);

        if (userFilePath == "exit" || userFilePath == "Exit") {
            cout << "Ending program ..." << endl;
            break;
        }

        ifstream inFile(userFilePath);
        if (!inFile) {
            cout << "Failed to open file." << endl;
            continue;
        }
        
        cout << "Please choose which tool you would like to use, 1: Basic Word Counter, 2: Character Counter, 3: Specific Character Counter, 4: All Tools."<<endl;
        cout << "Please enter either 1, 2, 3, or 4, depending on which option you would like to choose." << endl;
        cin >> toolChoice;

        switch (toolChoice){
            case 1:
                wordCounter(inFile);
                textOutput(inFile);
                break;
            case 2:
                charCounter(inFile);
                textOutput(inFile);
                break;
            case 3:
            
                textOutput(inFile);
                break;
            case 4:
                wordCounter(inFile);
                charCounter(inFile);
                
                textOutput(inFile);
                break;
            default:
                cout << "You entered an invalid number, please try again" << endl;
                break;
        }

        cout << "Please enter either, '1' to use anouther tool or, '2' to exit the program." <<endl;
        cin >> rerunNum;

        if (rerunNum == 2){
            start = "exit";
        }

        inFile.close();

    }
     
    return 0;

}

void charCounter(ifstream& inFile){
    
    counter.clear();
    char characterCounter;
    int totalCharacters = 0;

    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
        totalCharacters++;
    }
    cout << "This document contains: " << totalCharacters << " characters." << endl;
    
    inFile.clear();
    inFile.seekg(0);
}

void wordCounter(ifstream& inFile){
    
    int wordCount = 0; 
    string word;

    while (inFile >> word){
        wordCount++;
    }
    cout << "This document contains: " << wordCount << " words" << endl;
    
    inFile.clear();
    inFile.seekg(0);
}
void textOutput(ifstream& inFile){

    string line;

    cout << "\n----- File Contents -----" << endl;

        while (getline(inFile, line)) {
            cout << line << endl;
        }

        cout << "-------------------------" << endl;

    inFile.clear();
    inFile.seekg(0);

}