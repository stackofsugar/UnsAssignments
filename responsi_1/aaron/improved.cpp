#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
#define hardLimit 2147483646
using namespace std;

void cleanbuf(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

template<typename Ty>
Ty input(Ty floor = 0, Ty ceil = hardLimit){
    Ty buffer;
    while(1){
        if(cin >> buffer){
            if(buffer < floor){
                cout << "Your input was too small! Try again: \n";
            } else if(buffer > ceil){
                cout << "Your input was too big! Try again: \n";
            } else {
                return buffer;
            }
        } else {
            cout << "Invalid input! Please try again: \n";
            cleanbuf();
        }
    }
}

int main() {
    int init_opcode;
    cout << "Selamat datang di Bank Jago. Pilih operasi yang anda inginkan \n"
         << "1. Login || 2. Registrasi || 0. Keluar \n"
         << "Pilihan anda: ";

    init_opcode = input<int>(0,3);
}