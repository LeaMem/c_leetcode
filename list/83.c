#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
// struct ListNode* insertValue();
struct ListNode* deleteDuplicates(struct ListNode* head);

int main() {
    struct ListNode* head = insertValue();

    struct ListNode* res = deleteDuplicates(head);

    printf("KK");

    return 0;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode List;
    List start = {0, NULL};
    List* pre = &start;

    List* iterator = head;

    List* toFree;

    while (iterator) {
        if (pre->next != NULL && pre->val == iterator->val) {
            pre->next = iterator->next;
            toFree = iterator;
            iterator = iterator->next;
            free(toFree);
        } else {
            pre->next = iterator;
            pre = iterator;
            iterator = iterator->next;
        }
    }

    return start.next;
}
