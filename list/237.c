#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"

void deleteNode(struct ListNode *node) {
    struct ListNode *temp = node->next;

    node->val = temp->val;
    node->next = temp->next;

    free(temp);
}
