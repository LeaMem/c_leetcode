#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
struct ListNode* insertValue();
int getLength(struct ListNode* head);
struct ListNode* traverse(struct ListNode* head, int len);
struct ListNode* lastHalf(struct ListNode* head, int len);
bool isPalindrome(struct ListNode* head);

int main() {
    struct ListNode* head = insertValue();
    bool res = isPalindrome(head);
    printf("%d\n", res);
} 

//TODO: 大佬的代码
// 直接翻转后面一部分就可以了
// bool isPalindrome(struct ListNode* head) {
//     struct ListNode *fast = head, *slow = head, *temp = NULL;
//     while (fast) {//快慢指针找到链表中点
//         slow = slow->next;
//         fast = fast->next ? fast->next->next : fast->next;
//     }
//     while (slow) {
//         fast = slow->next;
//         slow->next = temp;
//         temp = slow;
//         slow = fast;
//     }
//     fast = head;
//     slow = temp;
//     while (fast && slow) {
//         if (fast->val != slow->val)
//             return false;
//         fast = fast->next;
//         slow = slow->next;
//     }
//     return true;
// }

// FIXME: 没有free内存
bool isPalindrome(struct ListNode* head) {
    typedef struct ListNode List;
    if (!head) {
        return true;
    }

    int len = getLength(head);

    int start = len / 2 + 1;

    struct ListNode* first = traverse(head, len + 1 - start);
    struct ListNode* second = lastHalf(head, start);

    bool res = true;
    while (first && second) {
        if (first->val != second->val) {
            res = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    if (first || second) {
        res = false;
    }

    return res;
}

int getLength(struct ListNode* head) {
    struct ListNode* iterator = head;
    int len = 0;
    while (iterator) {
        len++;
        iterator = iterator->next;
    }
    return len;
}

//头插法
struct ListNode* traverse(struct ListNode* head, int len) {
    int count = 0;
    struct ListNode* iterator = head;
    struct ListNode* end = NULL;

    struct ListNode* s;
    while (count < len) {
        s = calloc(1, sizeof(struct ListNode));
        s->val = iterator->val;
        s->next = end;
        end = s;
        count++;
        iterator = iterator->next;
    }
    return end;
}

//后一半的位置
struct ListNode* lastHalf(struct ListNode* head, int len) {
    int count = 1;
    struct ListNode* iterator = head;
    while (count < len) {
        count++;
        iterator = iterator->next;
    }
    return iterator;
}