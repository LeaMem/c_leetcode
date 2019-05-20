#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
    typedef struct ListNode List;
    List* first = head;
    List* second = first;

    if (first->next == NULL) {
        return first;
    }

    while (second != NULL && second->next != NULL) {
        first = first->next;
        second = second->next;
        second = second->next;
    }

    return first;
}
