#include <iostream> 
#include <ctime>
#include <cstdlib>
using namespace std;

class App {
    private:
        int number, guess;
        bool done;
    public:
        App(int,int,bool);
        void test();
        void Operate();
        void updateGuess(int);
        void isDone(bool);
        bool retDone();
};
App::App(int x = 0, int y = 0, bool done = false){
    number = x; guess = y;
}
void App::test(){
    cout << number << endl;
}
void App::updateGuess(int x){
    guess = x;
}
void App::isDone(bool other){
    done = other;
}
bool App::retDone(){
    return done;
}
void App::Operate(){
    if(guess < number){
        int TEMP;
        cout << "Too low! Your guess: ";
        cin >> TEMP;
        updateGuess(TEMP);
        isDone(false);
    }
    else if(guess > number){
        int TEMP;
        cout << "Too high! Your guess: ";
        cin >> TEMP;
        updateGuess(TEMP);
        isDone(false);
    }
    else if(guess = number){
        isDone(true);
    }
    else {
        cerr << "SOMETHING HAS GONE WRONG! EXITING..." << endl;
        cin.get();
    }
}


char a = 'Y';
bool done = false;

int main(){
    while(a == 'Y'){
        int guess = 0;
        cout << "GuessMyNumber \n(C) 2020 Christopher Digno" << endl;
        cout << "I have one random number, ranging from 0 - 1000. Can you guess my number? \nYour guess: ";
        cin >> guess;
        //
        int NUM;
        srand (unsigned(time(0)));
        NUM = rand() % 1000 + 1;
        App Operation(NUM, guess);
        //
        while(!Operation.retDone()){ Operation.Operate(); }
        cout << "Hooray! You picked the correct number! \nDo you want to play again? (Y/N): ";
        cin >> a;
        Operation.isDone(false);
    }
return 0;
}