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
    else if (data < (*root)->data) {
        TreeAdd(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        TreeAdd(&(*root)->right, data);
    }
}

TNode *TreeSearch(TNode **root, tdata_t data) {
    if (!(*root)) {
        return NULL;
    }
    else if (data < (*root)->data) {
        TreeSearch(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        TreeSearch(&((*root)->right), data);
    }
    else if (data == (*root)->data) {
        return (*root);
    }
}

void TreePrintPostorder(TNode *node) {
    if (!node) {
        return;
    }
    TreePrintPostorder(node->left);
    TreePrintPostorder(node->right);
    printf("%d, ", node->data);
}

void TreePrintInorder(TNode *node) {
    if (!node) {
        return;
    }
    TreePrintInorder(node->left);
    printf("| %d |", node->data);
    TreePrintInorder(node->right);
}

void TreePrintPreorder(TNode *node) {
    if (!node) {
        return;
    }
    printf("| %d |", node->data);
    TreePrintPreorder(node->left);
    TreePrintPreorder(node->right);
}

void TreeClean(TNode *root) {
    if (root) {
        TreeClean(root->left);
        TreeClean(root->right);
        free(root);
    }
}

int main() {
    TNode *root = NULL;
    TreeAdd(&root, 25);
    TreeAdd(&root, 20);
    TreeAdd(&root, 36);
    TreeAdd(&root, 10);
    TreeAdd(&root, 22);
    TreeAdd(&root, 30);
    TreeAdd(&root, 40);
    TreeAdd(&root, 5);
    TreeAdd(&root, 12);
    TreeAdd(&root, 28);
    TreeAdd(&root, 38);
    TreeAdd(&root, 48);
    TreeAdd(&root, 1);
    TreeAdd(&root, 8);
    TreeAdd(&root, 15);
    TreeAdd(&root, 45);
    TreeAdd(&root, 50);

    // printf("Preorder: ");
    // TreePrintPreorder(root);
    // printf("\n");

    printf("Postorder: ");
    TreePrintPostorder(root);
    printf("\n");

    // printf("Inorder: ");
    // TreePrintInorder(root);
    // printf("\n");

    TreeClean(root);
}