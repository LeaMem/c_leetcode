
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p && q) {
        return p->val == q->val && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    } else if ((q == NULL && p) || (p == NULL && q)) {
        return false;
    }
    
    return true;
}
