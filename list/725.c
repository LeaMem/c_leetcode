#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"

int getLength(struct ListNode* root);
struct ListNode** splitListToParts(struct ListNode* root, int k,
                                   int* returnSize);

int main() {
    typedef struct ListNode List;

    int k;
    List* in = insertValue();
    List** res = splitListToParts(in, 5, &k);
    printf("%d\n", k);
    return 0;
}
struct ListNode** splitListToParts(struct ListNode* root, int k,
                                   int* returnSize) {
    typedef struct ListNode List;
    int length = getLength(root);

    int mod = length % k;

    List** res = calloc(k, sizeof(List*));

    List* iterator = root;
    for (int i = 0; i < k; i++) {
        res[i] = iterator;

        int toMove = length / k;

        if (mod > 0) {
            mod--;
            toMove++;
        }

        while (iterator && toMove > 1) {
            iterator = iterator->next;
            toMove--;
        }

        if (iterator) {
            List* tmp = iterator;
            iterator = iterator->next;
            tmp->next = NULL;
        }
    }

    *returnSize = k;

    return res;
}

int getLength(struct ListNode* root) {
    struct ListNode* iterator = root;
    int count = 0;
    while (iterator) {
        count++;
        iterator = iterator->next;
    }
    return count;
}