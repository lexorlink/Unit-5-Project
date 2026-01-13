#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    bool programActive = true;
    string userInput;
    string userFilePath;
    while(programActive = true){
        //Welcomes user
        cout<<"------ Welcome to Word Counter ------"<<endl;
        cout<<"Please copy in your file path or enter 'exit' to end program"<<endl;
        cin>>userFilePath;

        if (userFilePath == "exit" || userFilePath == "Exit"){
            cout<<"Ending program ...";
            programActive = false;
            //exits the loop
        }
        if (userFilePath != "exit" || userFilePath != "Exit"){
            ofstream inFile(userFilePath); 
            programActive = false;
            //this just lets us confirm the file works
            
        }
    }
}
