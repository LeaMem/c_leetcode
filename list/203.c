#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
struct ListNode* insertValue();
struct ListNode* removeElements(struct ListNode* head, int val);

int main() {
    struct ListNode* head = insertValue();

    head = removeElements(head, 6);

    printf("kk\n");
    return 0;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    typedef struct ListNode List;

    List start = {0, head};

    List* tail = head;

    List* pre = &start;

    List* toFree;

    while (tail) {
        if (tail->val == val) {
            pre->next = tail->next;
            toFree = tail;
            tail = tail->next;
            free(toFree);
        } else {
            tail = tail->next;
            pre = pre->next;
        }
    }

    return start.next;
}