#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int x;
    struct StackNode* next;
} StackNode, *LinkStack;

LinkStack init_LinkStack() { return NULL; }

//判断空
int empty_LinkStack(LinkStack top) { return top == NULL; }

