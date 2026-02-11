#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

//C:\\Users\\89173\\U-5-text.txt 

map<char, int> counter;
char characterCounter;
string userFilePath, line, start;
int wordCount = 0, toolChoice;

int main() {

    cout << "----------Welcome to Word Counter----------" << endl;
    cout << "Enter 'start' to begin the program" << endl;
    cin >> start;
    
    
    do {

        cout << "Enter your file path or type 'exit' to close the program" << endl;
        getline(cin, userFilePath);

        if (userFilePath == "exit" || userFilePath == "Exit") {
            cout << "Ending program ..." << endl;
            break;
        }

        ifstream inFile(userFilePath);
        if (!inFile) {
            cout << "Failed to open file." << endl;
            break;
        }
        
        cout << "Please choose which tool you would like to use, 1: Basic Word Counter, 2: Character Counter, 3: Specific Character Counter, 4: All Tools."<<endl;
        cout << "Please enter either 1, 2, 3, or 4, depending on which option you would like to choose." << endl;
        cin >> toolChoice;

            switch (toolChoice){
                case 1:
                wordCounter();
                textOutput();
                break;
                case 2:
                charCounter();
                textOutput();
                break;
                case 3:
                textOutput();
                break;
                case 4:
                wordCounter();
                charCounter();
                textOutput();
                break;
                default:
                    cout << "You entered an invalid number, please try again" << endl;
                break;
            }

    } while (start == start);

    inFile.close();

    return 0;

}
void charCounter(){
    int totalCharacters = 0;

    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
        totalCharacters++;
    }
    cout << "This document contains: " << totalCharacters << " characters." << endl;
    inFile.clear();
    inFile.seekg(0);
}

void wordCounter(){
    string word;

    while (inFile >> word){
        wordCount++;
    }
    cout << "This document contains: " << wordCount << " words" << endl;
    inFile.clear();
    inFile.seekg(0);
}
void textOutput(){
    cout << "\n----- File Contents -----" << endl;

        while (getline(inFile, line)) {
            cout << line << endl;
        }

        cout << "-------------------------" << endl;

}