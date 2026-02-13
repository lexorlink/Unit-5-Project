#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<char, int> counter;
char characterCounter;

void charCounter(ifstream& inFile);
void wordCounter(ifstream& inFile);
void textOutput(ifstream& inFile);
void specificCharCounter(ifstream& inFile);

int main() {

    string userFilePath, start = "exit";
    int toolChoice, rerunNum;

    //Welcomes the user
    cout << "----------Welcome to Word Counter----------" << endl;
    cout << "Enter 'start' to begin the program" << endl;
    cin >> start;
    
    while (start == "start"){

        cout << "Enter your file path or type 'exit' to close the program" << endl;
        cin.ignore();
        getline(cin, userFilePath);

	    //The user can input exit as their file path to close the program.
        if (userFilePath == "exit" || userFilePath == "Exit") {
            cout << "Ending program ..." << endl;
            break;
        }

	    //Ckecks to make sure the user has inputed a proper file path.
        ifstream inFile(userFilePath);
        if (!inFile) {
            cout << "Failed to open file." << endl;
            continue; //Restarts the program if the file path is invalid.
        }
        
	    //Prompts the user to choose which tool they would like to use.
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
                specificCharCounter(inFile);
                textOutput(inFile);
                break;
            case 4:
		        specificCharCounter(inFile);
                wordCounter(inFile);
                charCounter(inFile);
                textOutput(inFile);
                break;
            default:
		        //If the user inputs an ivalid case num they with have to try again.
                cout << "You entered an invalid number, please try again" << endl;
                continue;
        }

	    //If the user enters 1 start will not change but if the enter 2 it will.
        cout << "Please enter either, '1' to use anouther tool or, '2' to exit the program." <<endl;
        cin >> rerunNum;

        if (rerunNum == 2){
            start = "exit";
        }

        inFile.close();

    }
     
    return 0;

}
//This function counts every character in the file and outputs to the user.
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
//This function counts every word in the file and outputs it to the user.
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
//This function outputs the contents of the text file to the user.
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
//This function prompts the user for a specific letter they want to count and outputs it to the user.
void specificCharCounter(ifstream& inFile) {
    
    char target;
    cout << "Enter a character to search for: ";
    cin >> target;

    counter.clear();    // reset map
    int total = 0;

    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
    }

    total = counter[target];

    cout << "The character '" << target << "' appears " << total << " times in the file." <<endl;

    inFile.clear();
    inFile.seekg(0);
}