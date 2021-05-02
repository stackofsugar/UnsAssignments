#include <iostream>
using namespace std;

struct Tnode {
    int data;
    Tnode *left;
    Tnode *right;

    Tnode() {
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
private:
    Tnode *head;
    int tsize;

    void destroy(Tnode *leaf) {
        if (leaf) {
            destroy(leaf->right);
            destroy(leaf->left);
            delete leaf;
        }
    }

    void insert(int num, Tnode *leaf) {
        if (num == leaf->data) {
            return;
        }
        if (num < leaf->data) {
            if (leaf->left) {
                insert(num, leaf->left);
            }
            else {
                leaf->left = new Tnode;
                leaf->left->data = num;
            }
        }
        else if (num > leaf->data) {
            if (leaf->right) {
                insert(num, leaf->right);
            }
            else {
                leaf->right = new Tnode;
                leaf->right->data = num;
            }
        }
    }

    bool search(int num, Tnode *leaf) {
        if (leaf) {
            if (num == leaf->data) {
                return true;
            }
            else if (num < leaf->data) {
                return search(num, leaf->left);
            }
            else {
                return search(num, leaf->right);
            }
        }
        else {
            return false;
        }
    }

    /*private*/ void postOrderPrint(Tnode *leaf) {
        if (!leaf) {
            return;
        }
        postOrderPrint(leaf->left);
        postOrderPrint(leaf->right);
        cout << ' ' << leaf->data << ' ';
    }

    void size(Tnode *leaf) {
        if (!leaf) {
            return;
        }
        size(leaf->left);
        size(leaf->right);
        tsize++;
    }

public:
    Tree() {
        head = nullptr;
    }

    ~Tree() {
        clear();
    }

    void insert(int num) {
        if (!head) {
            head = new Tnode;
            head->data = num;
            return;
        }
        insert(num, head);
    }

    void insert(int *arrnum, int size) {
        for (int i = 0; i < size; i++) {
            insert(arrnum[i]);
        }
    }

    bool search(int num) {
        return search(num, head);
    }

    /*public*/ void postOrderPrint() {
        if (head) {
            cout << '[';
            postOrderPrint(head);
            cout << "]\n";
        }
        else {
            cout << "[ no items ]\n";
        }
    }

    void clear() {
        destroy(head);
        head = nullptr;
    }

    int size() {
        tsize = 0;
        size(head);
        return tsize;
    }
};

int main() {
    Tree mytree;
    int input[12] = { 57, 32, 78, 24, 48, 85, 39, 81, 96, 35, 43, 90 };
    mytree.insert(input, 12);
    mytree.postOrderPrint();

    mytree.insert(81);
    mytree.postOrderPrint();

    if (mytree.search(96)) {
        cout << "96 exists in the tree\n";
    }
    if (!mytree.search(100)) {
        cout << "100 doesn't exist in the tree\n";
    }

    cout << "Size of the tree is: " << mytree.size() << '\n';

    mytree.clear();
    mytree.postOrderPrint();
}