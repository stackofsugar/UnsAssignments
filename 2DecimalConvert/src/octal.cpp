#include "../include/stdinc.h"
using namespace std;

Octal::Octal(int x){
    oct_value = x;
    oct_container = nullptr;
}

int* Octal::OctOperate(){
    oct_type = Logbn(8, oct_value);
    oct_container = new int[oct_type + 1];

    for(int i = oct_type; i >= 0; i--){
        oct_remainder = oct_value % 8;
        oct_value = oct_value / 8;
        oct_container[i] = oct_remainder;
    }

    return oct_container;
}

int Octal::CheckOctType(){
    return oct_type;
}
uint Octal::Logbn(uint b, uint n){
    return (log(n) / log(b));
}
Octal::~Octal(){
    if (oct_container != nullptr){
        delete[] oct_container;
    }
}