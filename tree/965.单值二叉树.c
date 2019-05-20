#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"
/*
 * @lc app=leetcode.cn id=965 lang=c
 *
 * [965] 单值二叉树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool compare(struct TreeNode * root, int data);

bool isUnivalTree(struct TreeNode* root){
    if(root){
        struct TreeNode * tmp = root;
        int data = root->val;
        return compare(tmp, data);
    }

    return true;
}

bool compare(struct TreeNode * root, int data){
    if(root){
        return root->val == data && compare(root->left, data) && compare(root->right, data);
    }
    return true;
}

