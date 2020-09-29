#pragma once

class Binary {
    private:
        int bin_type, bin_value, _bin_buffer, _bin_remainder;
        int* bin_container;
    public:
        Binary(int);
        ~Binary();
        int* BinOperate();
        int CheckBinType();
};

class Octal {

};

class Hex {

};