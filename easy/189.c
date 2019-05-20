#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void rotate(int *nums, int numsSize, int k);

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};

    rotate(a, 7, 3);

    for (int i = 0; i < 7; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}

void rotate(int *nums, int numsSize, int k) {
    int *tempNums = (int *)calloc(numsSize, sizeof(int));

    int move = k % numsSize;

    for (int i = 0; i < numsSize; i++) {
        tempNums[(i + k) % numsSize] = nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        nums[i] = tempNums[i];
    }
    free(tempNums);
}
