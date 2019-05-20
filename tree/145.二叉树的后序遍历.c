#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"
/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    typedef struct TreeNode TreeNode;
    int* result = calloc(5000, sizeof(int));

    TreeNode** stack = calloc(5000, sizeof(TreeNode*));

    int count = 0;
    int top = 0;
    stack[top++] = root;
    while (top > 0) {
        TreeNode* tmp = stack[--top];

        result[count++] = tmp->val;

        if (tmp->left) {
            stack[top++] = tmp->left;
        }
        if (tmp->right) {
            stack[top++] = tmp->right;
        }
    }

    *returnSize = count;

    free(stack);

    for (int i = 0; i < count / 2; i++) {
        int tmp = result[i];
        result[i] = result[count - 1 - i];
        result[count - 1 - i] = tmp;
    }

    return result;
}
