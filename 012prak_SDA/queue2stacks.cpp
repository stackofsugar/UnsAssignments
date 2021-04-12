#include <iostream>
#include <stack>
using namespace std;

struct Q {
    stack<int> st_m, st_s;

    void en(int x) {
        st_m.push(x);
    }

    bool de() {
        if (st_m.empty() && st_s.empty()) {
            cout << "Sorry, the queue is empty." << endl;
            return false;
        }

        if (st_s.empty()) {
            while (!st_m.empty()) {
                st_s.push(st_m.top());
                st_m.pop();
            }
        }

        st_s.pop();
        return true;
    }

    void pt() {
        if (st_s.empty()) {
            while (!st_m.empty()) {
                st_s.push(st_m.top());
                st_m.pop();
            }
        }
        cout << st_s.top() << '\n';
    }
};

int main() {
    Q q;
    int num_query,
        cmd,
        param;

    cin >> num_query;

    for (int i = 0; i < num_query; i++) {
        cin >> cmd;

        if (cmd == 1) {
            cin >> param;
            q.en(param);
        }
        else if (cmd == 2) {
            if (!q.de()) {
                return 69420;
            }
        }
        else {
            q.pt();
        }
    }
}
