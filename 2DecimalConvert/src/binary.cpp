#include "../include/stdinc.h"
using namespace std;

Binary::Binary(int x){
    bin_value = x;
    bin_container = nullptr;
}

int* Binary::BinOperate(){
    bin_type = log2(bin_value);
    bin_container = new int[bin_type + 1];

    for(int i = bin_type; i >= 0; i--){
        _bin_remainder = bin_value % 2;
        bin_value = bin_value / 2;
        bin_container[i] = _bin_remainder;
    }

    return bin_container;
}
int Binary::CheckBinType(){
    return bin_type;
}
Binary::~Binary(){
    if (bin_container != nullptr){
        delete[] bin_container;
    }
}