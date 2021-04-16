#include <iostream>
#include <iterator>
#include <iomanip>
#include <set>
using namespace std;

// 1 2 3 [4] 5 6 7

int main() {
    set<int> arr;
    set<int>::iterator it;
    size_t arr_size_before;
    int q_len,
        opchoice,
        in_num;
    bool left_oriented = false;

    cin >> q_len;
    for (int i = 0; i < q_len; i++) {
        cin >> opchoice;
        if (opchoice == 1) {
            arr_size_before = arr.size();
            cin >> in_num;
            arr.insert(in_num);

            if (arr.size() == 1) {
                it = arr.begin();
            }
            else {
                if ((arr.size() - arr_size_before) != 0) {
                    if (arr.size() % 2 == 0) {
                        if (in_num > *it) {
                            left_oriented = true;
                        }
                        else {
                            left_oriented = false;
                        }
                    }
                    else {
                        if (((in_num < *it) && (left_oriented == true)) || ((in_num > *it) && (left_oriented == false))) {
                            continue;
                        }
                        else if ((in_num > *it) && (left_oriented == true)) {
                            advance(it, 1);
                        }
                        else {
                            advance(it, -1);
                        }
                    }
                }
            }
        }
        else {
            if (arr.empty()) {
                cout << "0\n";
            }
            else {
                if (arr.size() % 2 != 0) {
                    cout << *it << '\n';
                }
                else if (left_oriented == true) {
                    auto itp = next(it, 1);
                    cout << (double)((*it + *itp) / 2.0F) << '\n';
                }
                else {
                    auto itp = prev(it, 1);
                    cout << (double)((*it + *itp) / 2.0F) << '\n';
                }
            }
        }
    }
}

/*
10
it

10 20
it

10 20 30
   it

10 20 30 40
   it

10 20 25 30 40
      it
*/