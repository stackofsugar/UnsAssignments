#include <iostream>
#include <set>
using namespace std;

void printSet(set<int> &arr) {
    cout << "[ ";
    for (int i : arr) {
        cout << i << ' ';
    }
    cout << "]\n";
}

int main() {
    set<int> arr;
    arr.insert(1);
    arr.insert(2);
    arr.insert(1);
    arr.insert(1);
    arr.insert(1);
    arr.insert(1);
    arr.insert(1);
    arr.insert(1);
    printSet(arr);
}