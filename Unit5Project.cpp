#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    bool programActive = true;
    string userInput;
    while(programActive == true){
        //Wealcomes user
        cout<<"------ Welcome to Word Counter ------"<<endl;
        cout<<"Please enter your document or enter 'exit' to end program"<<endl;
        //user input not implemented
        cin>>userInput;
        //exits the loop
        if (userInput == "exit" || userInput == "Exit"){
            cout<<"Ending program ...";
            programActive = false;
        }
        else{
            //This is where we should get the input for word count
        }
    }
}
