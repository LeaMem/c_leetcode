#include <stdlib.h>
#include <stdio.h>



typedef struct AVLTreeNode {
    int key;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
} Node, *AVLTree;
