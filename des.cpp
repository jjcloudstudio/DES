#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//the central controller of the program
void runDESProgram(){
    int inputOfUser;
    cout << "Let me know, what to do? " << endl;
    cout << "1. DES Encryption " << endl;
    cout << "2. DES Decryption " << endl;
    cin >> inputOfUser;

    switch (inputOfUser)  {
    case 1:
        // code to be executed if expression is equal to 1;
        cout << "1 output" << endl;
        break;

    case 2:
        // code to be executed if expression is equal to 2;
        cout << "2 output" << endl;
        break;
    default:
        // code to be executed if expression doesn't match any defined value
        cout << "Not correct input, try again. " << endl;
        runDESProgram();
}
}

int main()
{
    cout<<"Hello World" << endl;
    runDESProgram();
    return 0;
}
//A
