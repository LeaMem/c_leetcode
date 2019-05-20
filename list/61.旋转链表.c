#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getLength(struct ListNode* head, struct ListNode** last);
struct ListNode* rotateRight(struct ListNode* head, int k);

int main() {
    struct ListNode* tmp = insertValue();
    tmp = rotateRight(tmp, 2);
    printf("Kk");
    return 0;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || !k) {
        return head;
    }
    typedef struct ListNode ListNode;
    ListNode* last;
    int len = getLength(head, &last);

    int toMove = k % len;

    if (!toMove) {
        return head;
    }

    //找到要移动的点
    ListNode* fast = head;
    ListNode* slow = head;
    while (toMove) {
        toMove--;
        fast = fast->next;
    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    last = slow->next;
    slow->next = NULL;
    fast->next = head;

    return last;
}

int getLength(struct ListNode* head, struct ListNode** last) {
    struct ListNode* it = head;
    struct ListNode pre = {0, head};
    *last = &pre;
    int count = 0;
    while (it) {
        count++;
        it = it->next;
        *last = (*last)->next;
    }
    return count;
}
