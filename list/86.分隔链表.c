#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* find(struct ListNode* head, struct ListNode** location, int x);
struct ListNode* partition(struct ListNode* head, int x);

int main() {
    struct ListNode* res = insertValue();
    res = partition(res, 3);
    printf("kk");
    return 0;
}

struct ListNode* partition(struct ListNode* head, int x) {
    typedef struct ListNode ListNode;

    ListNode virtual = {0, head};

    ListNode* location = NULL;

    location = find(head, &location, x);

    ListNode* move = location;

    // if (location) {
    //     ListNode* it = &virtual;
    //     while (it->next != location) {
    //         it = it->next;
    //     }
    //     location = it;
    // } else {
    //     location = &virtual;
    // }

    // ListNode* pre = location;
    // while (move) {
    //     if (move->val < x) {
    //         pre->next = move->next;
    //         ListNode* tmpPre = location->next;
    //         location->next = move;
    //         move->next = tmpPre;
    //         pre = move;
    //     } else {
    //         move = move->next;
    //     }
    // }

    return virtual.next;
}

struct ListNode* find(struct ListNode* head, struct ListNode** location,
                      int x) {
    struct ListNode* tmp = head;

    while (tmp) {
        if (tmp->val == x) {
            break;
        }

        if (x < tmp->val) {
            *location = tmp;
        }
        tmp = tmp->next;
    }

    return tmp;
}
