#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base/common.h"
struct ListNode *insertValue();

/**

共同的node: Common
listA = A + Common
listB =B + Common
PointerA: [A + Common + B] + Common
PointerB: [B + Common + A] + Common


 * */
struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    typedef struct ListNode List;

    List *A = headA;
    List *B = headB;

    while (A != B) {
        A = A ? A->next : headB;
        B = B ? B->next : headA;
    }

    return A;
}