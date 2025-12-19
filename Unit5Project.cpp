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
        //Welcomes user
        cout<<"------ Welcome to Word Counter ------"<<endl;
        cout<<"Please enter your document or enter 'exit' to end program"<<endl;
        cin>>userInput;

        if (userInput == "exit" || userInput == "Exit"){
            cout<<"Ending program ...";
            programActive = false;
            //exits the loop
        }
        else{
            //This is where we should get the input for word count
        }
    }
}
