#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = calloc(1000, sizeof(int));

    int plus = 1;
    *returnSize = 0;
    for (int i = digitsSize - 1; i >= 0; i--) {
        plus += digits[i];

        result[(*returnSize)++] = plus % 10;
        plus /= 10;
    }
    if (plus) {
        result[(*returnSize)++] = plus;
    }

    //翻转
    if (*returnSize) {
        int i = 0;
        int j = *returnSize - 1;
        while (i < j) {
            result[i] = result[i] ^ result[j];
            result[j] = result[i] ^ result[j];
            result[i] = result[i] ^ result[j];
            i++;
            j--;
        }
    }
    return result;
}
