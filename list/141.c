#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
struct ListNode* insertValue();

bool hasCycle(struct ListNode* head) {
    typedef struct ListNode List;
    if (!head || !head->next) {
        return false;
    }
    List* fast = head;
    List* slow = head;

    bool flag = false;

    while (fast) {
        slow = slow->next;
        fast = fast->next;

        if (fast) {
            fast = fast->next;
        }

        if (fast == slow) {
            flag = true;
            break;
        }
    }
    return flag;
}