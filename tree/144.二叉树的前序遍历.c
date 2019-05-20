#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Stack {
    struct TreeNode* data;
    struct Stack* next;
} Stack;

bool isEmpty(Stack* s);
void push(Stack** stack, struct TreeNode* root);

struct Stack* pop(Stack** stack);
// int* preorderTraversal(struct TreeNode* root, int* returnSize);

// int main() {
//     typedef struct TreeNode TreeNode;
//     TreeNode third = {3, NULL, NULL};
//     TreeNode second = {2, &third, NULL};
//     TreeNode root = {1, NULL, &second};

//     int size;
//     int* a = preorderTraversal(&root, &size);

//     printf("%d\n", size);
//     return 0;
// }

// int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//     typedef struct TreeNode TreeNode;

//     if (!root) {
//         *returnSize = 0;
//         return NULL;
//     }

//     TreeNode** stack = calloc(5000, sizeof(TreeNode*));
//     int* result = calloc(5000, sizeof(int));
//     int top = 0;
//     int count = -1;
//     stack[top] = root;

//     while (top >= 0) {
//         TreeNode* tmp = stack[top--];
//         if (tmp->right) {
//             stack[++top] = tmp->right;
//         }
//         if (tmp->left) {
//             stack[++top] = tmp->left;
//         }

//         result[++count] = tmp->val;
//     }

//     free(stack);
//     *returnSize = count + 1;
//     return result;
// }

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode TreeNode;

    *returnSize = 0;
    Stack* stack = NULL;
    int* result = calloc(2000, sizeof(int));
    push(&stack, root);
    while (!isEmpty(stack)) {
        Stack* ss = pop(&stack);
        TreeNode* tmp = ss->data;
        if (tmp) {
            result[(*returnSize)++] = tmp->val;
            if (tmp->right) {
                push(&stack, tmp->right);
            }
            if (tmp->left) {
                push(&stack, tmp->left);
            }
        }
        free(ss);
    }

    return result;
}

void push(Stack** stack, struct TreeNode* root) {
    Stack* s = calloc(1, sizeof(Stack));
    s->data = root;
    s->next = *stack;
    *stack = s;
}

struct Stack* pop(Stack** stack) {
    if (!isEmpty(*stack)) {
        Stack* tmp = *stack;
        *stack = tmp->next;
        return tmp;
    }
    return NULL;
}

bool isEmpty(Stack* s) { return s == NULL; }

// void push(struct TreeNode * stack, struct TreeNode * root){

//     typedef struct TreeNode  TreeNode;
//     TreeNode * tmp = malloc(sizeof(TreeNode*));
//     tmp = root;

//     stack

// }
