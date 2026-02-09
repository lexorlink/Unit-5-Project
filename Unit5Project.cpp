#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

//C:\\Users\\89173\\U-5-text.txt 

int main() {
    map<char, int> counter;
    char characterCounter;
    string userFilePath;
    int wordCount = 0;
    string line;
    string start;

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

        }
        cout << "Please choose which tool you would like to use"

    } while (start == start)

    

    

    //Counts Words
   

    //Reset File
    inFile.clear();
    inFile.seekg(0);


    int totalCharacters = 0;

    //Counts Characters
    
    

    cout << "This document contains: " << wordCount << " words" << endl;


    //Reset File again
    inFile.clear();
    inFile.seekg(0);
    
    //Outputs the text
    cout << "\n----- File Contents -----" << endl;

    
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    cout << "-------------------------" << endl;

    //Closes the File
    inFile.close();

    return 0;
}
static void charCounter{
    while (inFile.get(characterCounter)) {
        counter[characterCounter]++;
        totalCharacters++;
    }
    cout << "This document contains: " << totalCharacters << " characters." << endl;
}
static void wordCounter{
    string word;
    while (inFile >> word){
        wordCount++;
    }
    cout << "This document contains: " << wordCount << " words" << endl;
}
