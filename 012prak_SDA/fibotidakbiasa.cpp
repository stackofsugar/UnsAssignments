#include <iostream>
using namespace std;
typedef int64_t fib_t;
#define mod 100000007

int main() {
    fib_t ind,
        num1 = 1,
        num2 = 1,
        num3 = 2,
        numq;
    cin >> ind;

    if (ind <= 2) {
        numq = 1;
    }
    else if (ind == 3) {
        numq = 2;
    }
    else {
        for (fib_t i = 3; i < ind; i++) {
            numq = (num3 % mod + num2 % mod + num1 % mod) % mod;
            num1 = num2;
            num2 = num3;
            num3 = numq;
        }
    }

    cout << numq << '\n';
}