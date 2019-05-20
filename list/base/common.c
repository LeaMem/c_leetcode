#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct ListNode List;

List* insertValue() {
    List head = {0, NULL};
    List* tail = &head;
    List* temp;
    int a;
    while (~scanf("%d", &a)) {
        if (a == -1) {
            break;
        }
        temp = calloc(1, sizeof(List));
        temp->val = a;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return head.next;
}