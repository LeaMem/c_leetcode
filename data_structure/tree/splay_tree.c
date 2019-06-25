#include <stdio.h>
#include <stdlib.h>

typedef struct SplayTreeNode {
    int key;
    struct SplayTreeNode* left;
    struct SplayTreeNode* right;
} Node, *SplayTree;

Node* splaytree_spaly(SplayTree tree, int key) {
    Node N, *l, *r, *c;

    if (tree == NULL) {
        return tree;
    }

    N.left = N.right = NULL;

    l = r = &N;

    for (;;) {
        if (key < tree->key) {
            if (tree->left == NULL) {
                break;
            }
            if (key < tree->left->key) {
                // 右旋
                c = tree->left;
                tree->left = c->right;
                c->right = tree;
                tree = c;
                if (tree->left == NULL) {
                    break;
                }
            }
            r->left = tree;
            r = tree;
            tree = tree->left;
        } else if (key > tree->key) {
            if (tree->right == NULL) {
                break;
            }
            if (key > tree->right->key) {
                c = tree->right;
                tree->right = c->left;
                tree = c;
                if (tree->right == NULL) {
                    break;
                }
            }
            l->right = tree;
            l = tree;
            tree = tree->right;
        } else {
            break;
        }
    }

    l->right = tree->left;
    r->left = tree->right;
    tree->left = N.right;
    tree->right = N.left;

    return tree;
}

int main(int argc, char const* argv[]) {
    Node ten = {10, NULL, NULL};
    Node thirty = {30, NULL, NULL};
    Node fifty = {50, NULL, NULL};
    Node seventy = {70, NULL, NULL};
    Node twenty = {20, &ten, &thirty};
    Node sixty = {60, &fifty, &seventy};
    Node forty = {40, &twenty, &sixty};

    Node* root = splaytree_spaly(&forty, 30);
    printf("%d\n", root->key);
    return 0;
}
