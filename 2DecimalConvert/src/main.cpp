#include "../include/stdinc.h"
using namespace std;


int main(){
    int choice, repeat = 1;
    int after;

do {
    cout << ".:DeConvert:. \n(C) 2020 Christopher Digno" << endl;
    cout << "Convert from decimal to: \n1) Binary\n2) Octal\n3) Hexadecimal" << endl;
    cout << "Your choice: ";
    cin >> choice;

        if (choice == 1){
            int BIN_CHOICE, *BIN_RESULT;
            do {
            cout << "Put in the decimal integer you want to convert into binary: ";
            cin >> BIN_CHOICE;
            Binary BIN_OBJECT(BIN_CHOICE);
            BIN_RESULT = BIN_OBJECT.BinOperate();

            cout << "The result is: \n> ";
            for (int i = 0; i <= BIN_OBJECT.CheckBinType(); i++){
                cout << *(BIN_RESULT + i);
            }
            cout << " <" << endl;

            cout << "Press 1 to go back to home, 2 to repeat last, 3 to exit: ";
            cin >> after;
            if (after == 3){
                return 0;
            }      
            } while (after == 2);
        } // endif choice 1
        else if (choice == 2){
            //OctOperate();
        }
        else if (choice == 3){
            //HexOperate();
        }
        else {
            cerr << "Invalid value entered!";
        }

} while (repeat = 1);
}