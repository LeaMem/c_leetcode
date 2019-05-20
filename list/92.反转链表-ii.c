#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"

/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n);
int main() {
    struct ListNode* res = insertValue();
    res = reverseBetween(res, 1, 2);
    printf("kk");
    return 0;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    typedef struct ListNode ListNode;
    ListNode pre = {0, head};
    ListNode* it = &pre;
    for (int i = 0; i < m - 1; i++) {
        it = it->next;
    }
    ListNode* start = it->next;
    for (int i = m; i < n; i++) {
        ListNode* tmp = start->next;
        start->next = tmp->next;
        tmp->next = it->next;
        it->next = tmp;
    }

    return pre.next;
}
