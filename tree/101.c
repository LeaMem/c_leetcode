#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"

bool compare(struct TreeNode * left, struct TreeNode * right);
bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    }

    return compare(root, root);
}

bool compare(struct TreeNode * left, struct TreeNode * right){
    if(left && right){
        return left->val == right->val &&
            compare(left->left, right->right) && compare(right->left, left->right);
    }else if((left && !right) || (!left && right)){
        return false;
    }
    return true;
}
