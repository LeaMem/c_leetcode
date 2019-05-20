#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
struct ListNode *insertValue();
struct ListNode *swapPairs(struct ListNode *head);

/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int main() {
    struct ListNode *head = insertValue();
    head = swapPairs(head);
    printf("kk\n");
    return 0;
}

struct ListNode *swapPairs(struct ListNode *head) {
    typedef struct ListNode ListNode;

    if (!(head && head->next)) {
        return head;
    }

    ListNode *pre = head;
    ListNode *tail = head->next;

    ListNode start = {0, head};
    ListNode *it = &start;

    while (tail) {
        pre->next = tail->next;
        tail->next = pre;
        it->next = tail;

        it = pre;
        pre = pre->next;
        if (pre) {
            tail = pre->next;
        } else {
            tail = NULL;
        }
    }

    return start.next;
}
