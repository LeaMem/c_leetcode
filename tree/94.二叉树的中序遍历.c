#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"

int* inorderTraversal(struct TreeNode* root, int* returnSize);

int main() {
    struct TreeNode third = {3, NULL, NULL};
    struct TreeNode second = {2, &third, NULL};

    struct TreeNode root = {1, NULL, &second};

    int a;
    int* res = inorderTraversal(&root, &a);

    printf("kk");
    return 0;
}

/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode TreeNode;

    int* result = calloc(2000, sizeof(int));
    TreeNode** stack = calloc(2000, sizeof(TreeNode*));

    int top = 0;
    int count = 0;
    TreeNode* tmp = root;

    while (tmp || top > 0) {
        while (tmp) {
            stack[top++] = tmp;
            tmp = tmp->left;
        }

        // pop
        tmp = stack[--top];
        if (tmp) {
            result[count++] = tmp->val;
            tmp = tmp->right;
        }
    }

    *returnSize = count;
    return result;
}
