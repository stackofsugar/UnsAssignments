#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> data;
    string name, key;
    int opchoice,
        q_len;

    cin >> q_len;
    for (int i = 0; i < q_len; i++) {
        cin >> opchoice;
        if (opchoice == 1) {
            cin >> key >> name;
            auto found = data.find(key);
            if (found == data.end()) {
                data.insert(pair<string, string>(key, name));
                cout << "kursi berhasil dipesan\n";
            }
            else {
                cout << "kursi sudah dipesan " << found->second << '\n';
            }
        }
        else {
            cin >> key;
            auto found = data.find(key);
            if (found == data.end()) {
                cout << "kursi masih kosong\n";
            }
            else {
                cout << "kursi sudah dipesan " << found->second << '\n';
            }
        }
    }
}