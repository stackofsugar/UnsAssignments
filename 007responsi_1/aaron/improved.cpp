#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <string>
using namespace std;

void cleanbuf(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

template<typename Ty>
Ty input(Ty floor = 0, Ty ceil = numeric_limits<Ty>::max()){
    Ty buffer;
    while(1){
        if(cin >> buffer){
            if(buffer < floor){
                cout << "Your input was too small! Try again: ";
            } else if(buffer > ceil){
                cout << "Your input was too big! Try again: ";
            } else {
                return buffer;
            }
        } else {
            cout << "Invalid input! Please try again: ";
            cleanbuf();
        }
    }
}

enum OpCode {
    eLogin = 1, eRegister
} opcode;

enum InternalOperations {
    eError,
    eWriteNew,
    eWriteNewBalance,
    eLoginop
} internaloperations;

class UserAccount {
    private:
        string userName;
        string userID;
        string password;
        uint   balance;
    public:
        void prompt(InternalOperations opType);
        UserAccount read(UserAccount &obj);

    friend bool operator==(const UserAccount& ua1, const UserAccount &ua2);
    friend bool operator!=(const UserAccount& ua1, const UserAccount &ua2);
};

bool operator==(const UserAccount& ua1, const UserAccount &ua2){

}

bool operator!=(const UserAccount& ua1, const UserAccount &ua2){
    
}

void UserAccount::prompt(InternalOperations opType){
    if(opType == eWriteNew){
        cout << "Enter your Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, userName);
        cout << "Enter your User ID: ";
        getline(cin, userID);
        cout << "Enter your Password: ";
        getline(cin, password);
    }
    else if(opType == eWriteNewBalance){
        cout << "Enter your starting balance: Rp ";
        cin >> balance;
    }
    else if(opType == eLoginop){
        cout << "Enter your ID: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, userID);
        cout << "Enter you Password: ";
        getline(cin, password);
    }
}

void afterLoginEventHandler(UserAccount &user){

}

/** Validates user's login againts established database.
 * @param user Reference to a class buffer object
 * @param userBase Reference to a vector class object "userBase"
 * @return Correct vector array iteration, -1 on fails
 */
int loginValidator(UserAccount &user, vector<UserAccount> &userBase){
    return 1;
}

/** Handles ATM events and operations.
 * @param user Reference to a class buffer object
 * @param userBase Reference to a vector class object "userBase"
 * @return true on successful event
 */
bool operationEventHandler(UserAccount &user, vector<UserAccount> &userBase){
    bool loginSuccess = false;
    int userLocation = loginValidator(user, userBase);
    while(!loginSuccess){
        if(userLocation >= 0){
            loginSuccess = true;
            // NOTE Operate as usual with user[userLocation]
        } else {

        }
    }
}

int main() {
    int init_opcode, repeat = 1;
    vector<UserAccount> userBase;

    while(repeat){
        cout << "Selamat datang di Bank Jago. Pilih operasi yang anda inginkan \n"
             << "1. Login || 2. Registrasi || 0. Keluar \n"
             << "Pilihan anda: ";
        init_opcode = input<int>(0,3);

        if(init_opcode == eLogin){                          // SECTION Login
            UserAccount ua_buffer;
            ua_buffer.prompt(eLoginop);
            if(!operationEventHandler(ua_buffer, userBase)){
                cerr << ">> Something went wrong: event-handler-returned-false <<\n";
            } else {

            }
        }                                                   // !SECTION Login
        else if(init_opcode == eRegister){                  // SECTION Registration
            int multiAskFor = 1;
            while(multiAskFor){
                UserAccount ua_buffer;
                cout << "===== Registration Page ===== \n"
                    << "PASS: Strong, preferably more than 6 alphanumeric characters. \n";
                ua_buffer.prompt(eWriteNew);
                cout << "Do you want to do a deposit? (1/0): ";
                multiAskFor = input<int>(0,1);
                if(multiAskFor){
                    ua_buffer.prompt(eWriteNewBalance);
                }
                cout << "Registration done! Thank you! \n";
                userBase.push_back(ua_buffer);
                cout << "Do you want to register an account again? (1/0): ";
                multiAskFor = input<int>(0,1);
            }
        }                                                   // !SECTION Registration
        else if(!init_opcode){
            repeat = 0;
        }
        else {
            cerr << "Something went wrong: opcode-reached-end \n";
        }
    }
}