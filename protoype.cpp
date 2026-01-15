#include <iostream>
using namespace std;

void showStatic();

int main(){
    for (int i=0;i<5;i++){
        showStatic();
    }
    return 0;
}

void showStatic(){
    static in staticVar = 0;
    int regularVar = 0;

    regularVar++;

    cout<<"Static Variable"<<++staticVar<<endl;
    cout<<"Regular Variable"<<regularVar<<endl;
    cout<<"--------------------------------"<<endl;
}
