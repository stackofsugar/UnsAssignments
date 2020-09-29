#include "../include/stdinc.h"
using namespace std;

Binary::Binary(int x){
    BIN_VALUE = x;
}
int* Binary::BinOperate(){
    BIN_TYPE = log2(BIN_VALUE);

    for(int i = BIN_TYPE; i >= 0; i--){
        _BIN_REMAINDER = BIN_VALUE % 2;
        BIN_VALUE = BIN_VALUE / 2;
        BIN_CONTAINER[i] = _BIN_REMAINDER;
    }

    return BIN_CONTAINER;
}
int Binary::CheckBinType(){
    return BIN_TYPE;
}