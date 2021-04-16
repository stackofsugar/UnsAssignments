#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

void quickSort(vector<int> &arr) {
    int high = arr.size() - 1,
        low = 0,
        stack[high - low + 1],
        top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int x = arr[high / 2],
            i = (low - 1);

        for (int j = low; j <= (high - 1); j++) {
            if (arr[j] <= x) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int part = i + 1;

        if ((part - 1) > low) {
            stack[++top] = low;
            stack[++top] = part - 1;
        }

        if ((part + 1) < high) {
            stack[++top] = part + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    int query_length,
        opchoice,
        inp_num,
        beforesplit;
    bool is_sorted = false;
    vector<int> arr;
    cin >> query_length;

    for (int i = 0; i < query_length; i++) {
        cin >> opchoice;
        if (opchoice == 1) {
            is_sorted = false;
            cin >> inp_num;
            if (find(arr.begin(), arr.end(), inp_num) == arr.end()) {
                arr.push_back(inp_num);
            }
            // arr.push_back(inp_num);
        }
        else {
            if (arr.empty()) {
                cout << "0\n";
            }
            else {
                if (!is_sorted) {
                    quickSort(arr);
                    is_sorted = true;
                }

                if ((arr.size() % 2) != 0) {
                    cout << arr[arr.size() / 2] << '\n';
                }
                else {
                    // cout << (double)(arr[(arr.size() - 1) / 2] + arr[arr.size() / 2]) / 2.0F << '\n';
                    beforesplit = arr[(arr.size() - 1) / 2] + arr[arr.size() / 2];
                    if (beforesplit % 2 == 0) {
                        cout << (beforesplit / 2) << '\n';
                    }
                    else {
                        cout << (beforesplit - 1) / 2 << ".5\n";
                    }
                }
            }
        }
    }
}