#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
struct ListNode* reverseList(struct ListNode* head);
int main() {
    typedef struct ListNode List;

    List fifth = {5, NULL};
    List forth = {4, &fifth};
    List thrid = {3, &forth};
    List second = {2, &thrid};
    List first = {1, &second};

    List* res = reverseList(&first);

    printf("sdf\n");

    return 0;
}

struct ListNode* reverseList(struct ListNode* head) {
    typedef struct ListNode List;

    if (head == NULL) {
        return head;
    }

    List* first = NULL;
    List* tail = head;
    while (tail != NULL) {
        List* temp = tail;
        tail = tail->next;
        temp->next = first;
        first = temp;
    }
    return first;
}
