#pragma once

class Binary {
    private:
        int BIN_TYPE, BIN_VALUE, _BIN_BUFFER, _BIN_REMAINDER;
        int BIN_CONTAINER[];
    public:
        Binary(int);
        int* BinOperate();
        int CheckBinType();
};

class Octal {

};

class Hex {

};