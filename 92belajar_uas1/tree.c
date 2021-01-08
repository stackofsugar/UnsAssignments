#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
};
typedef struct TNode TNode;
typedef int tdata_t;

void TreeAdd(TNode **root, tdata_t data) {
    TNode *buffer1 = (TNode *)malloc(sizeof(TNode));
    if (!buffer1) {
        printf("Gagal mengalokasikan memori (sad computer noises)\n");
        return;
    }

    buffer1->data = data;
    if (!(*root)) {
        *root = buffer1;
        buffer1->left = NULL;
        buffer1->right = NULL;
    }
    else {

    }
}

void TreePrintPostorder(TNode *node) {
    if (!node) {
        return;
    }
    TreePrintPostorder(node->left);
    TreePrintPostorder(node->right);
    printf("| %d |", node->data);
}

int main() {
    TNode *root = NULL;
    TreeAdd(&root, 10);
    TreePrintPostorder(root);

}