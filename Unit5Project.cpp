#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
bool openWelcomeWindow = true;
bool programActive = true;
int main(){
    string userFilePath;
    while(programActive = true){
        //Welcomes user
        if (openWelcomeWindow == true){
            cout<<"----------Welcome to Word Counter----------"<<endl;
            cout<<"Enter your file path or type 'exit' to close the program (preferably a .txt file)"<<endl;
            cout<<"Note that the file name must NOT contain any spaces"<<endl;
            cin>>userFilePath;
            openWelcomeWindow = false;
            //disables the window from being reopened until needed
        }

        if (userFilePath == "exit" || userFilePath == "Exit"){
            cout<<"Ending program ...";
            break;
            //exits the loop
        }
        if (userFilePath != "exit" || userFilePath != "Exit"){
            cout<<"The path you have selected is: "<<userFilePath << endl;
            ofstream inFile(userFilePath); 
            
            break;
            //this just lets us confirm the file works, data scanning needs implementation
            
        }
    }
}

