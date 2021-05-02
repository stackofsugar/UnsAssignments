#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int num) {
        value = num;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node *root;

public:
    BST() {
        root = nullptr;
    }

    /* Masukkan fungsi insert disini */
    void insert(int num) {
        if (root == nullptr) {
            Node *insnode = new Node(num);
            root = insnode;
        }
        Node *objbuf1 = root;
        Node *objbuf2 = nullptr;

        while (objbuf1) {
            objbuf2 = objbuf1;
            if (num < objbuf1->value) {
                objbuf1 = objbuf1->left;
            }
            else /* if (num > objbuf1->value)*/ {
                objbuf1 = objbuf1->right;
            }
            // else {
            //     return;
            // }
        }

        Node *insnode = new Node(num);

        if (num < objbuf2->value) {
            objbuf2->left = insnode;
        }
        else if (num > objbuf2->value) {
            objbuf2->right = insnode;
        }
    }

    /* Masukkan fungsi search disini */
    Node *search(int num) {
        Node *objbuf = root;
        while (objbuf) {
            if (num < objbuf->value) {
                objbuf = objbuf->left;
            }
            else if (num > objbuf->value) {
                objbuf = objbuf->right;
            }
            else if (num == objbuf->value) {
                return objbuf;
            }
            else {
                return nullptr;
            }
        }
        return nullptr;
    }

    /* Masukkan fungsi depth disini */
    int depth(int num) {
        int depth = 0;
        Node *objbuf = root;
        while (objbuf) {
            if (num < objbuf->value) {
                objbuf = objbuf->left;
                depth++;
            }
            else if (num > objbuf->value) {
                objbuf = objbuf->right;
                depth++;
            }
            else if (num == objbuf->value) {
                return depth;
            }
            else {
                return -1;
            }
        }
        return -1;
    }


};

int main() {
    BST *bst = new BST;
    int i, n, temp;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 1) {
            cin >> temp;
            bst->insert(temp);
        }
        else if (temp == 2) {
            cin >> temp;
            cout << ((bst->search(temp) == nullptr) ? "tidak ada\n" : "ada\n");
        }
        else if (temp == 3) {
            cin >> temp;
            cout << bst->depth(temp) << "\n";
        }
    }
}