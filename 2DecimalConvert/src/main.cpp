#include "../include/stdinc.h"
using namespace std;

void BinOperate();
void OctOperate();
void HexOperate();

int main(){
    int choice, repeat = 1;

while (repeat = 1){
    repeat = 1;
    cout << "\nDeConvert \n(C) 2020 Christopher Digno" << endl;
    cout << "Convert from decimal to: \n1) Binary\n2) Octal\n3) Hexadecimal" << endl;
    cout << "Your choice: ";
    cin >> choice;

        if (choice == 1){
            BinOperate();
        }
        else if (choice == 2){
            OctOperate();
        }
        else if (choice == 3){
            HexOperate();
        }
        else {
            cerr << "Invalid value entered!";
        }
}
}

/*
void BinOperate(){
    cout << "This is Bin" << endl;
}
void OctOperate(){
    cout << "This is Oct" << endl;
}
void HexOperate(){
    cout << "This is Hex" << endl;
}
*/
