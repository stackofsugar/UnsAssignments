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
    private:
        int oct_type, oct_value, oct_buffer, oct_remainder;
        int* oct_container;
    public:
        Octal(int);
        ~Octal();
        int* OctOperate();
        int CheckOctType();
        uint Logbn(uint,uint);
};

class Hex {

};