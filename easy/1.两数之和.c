#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct List {
    int data;
    int index;
    struct List* next;
} List;
bool contains(List* list, int data, int* index);
void insert(List** list, int data, int index);

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int a[] = {2, 7, 11, 15};

    int size;
    int* res = twoSum(a, 4, 9, &size);

    printf("kk");

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    List* list = NULL;
    *returnSize = 0;

    int index;
    int* result = calloc(2, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int value = target - nums[i];
        if (contains(list, nums[i], &index)) {
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            return result;
        } else {
            insert(&list, value, i);
        }
    }
    return result;
}

void insert(List** list, int data, int index) {
    List* s = calloc(1, sizeof(List));
    s->data = data;
    s->index = index;
    s->next = *list;
    *list = s;
}

bool contains(List* list, int data, int* index) {
    bool flag = false;
    List* it = list;
    while (it) {
        if (it->data == data) {
            flag = true;
            *index = it->index;
            break;
        }
        it = it->next;
    }
    return flag;
}