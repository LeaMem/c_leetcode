#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    int data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

int main() { return 0; }

int init(BiTree *bt) {
    if ((bt = malloc(sizeof(BiTNode))) == NULL) {
        return -1;
    }

    (*bt)->lchild = NULL;

    (*bt)->rchild = NULL;

    return 1;
}

