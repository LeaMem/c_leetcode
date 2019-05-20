#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base/common.h"

typedef struct Queue {
    struct TreeNode *node;
    struct Queue *next;
} Queue;

Queue *findLast(Queue *q);
int insert(Queue **queue, struct TreeNode *treeNode);
int getLength(Queue *q);

// int maxDepth(struct TreeNode *root);

// int main() {
//     typedef struct TreeNode Tree;

//     Tree d1 = {5, NULL, NULL};
//     Tree d2 = {1, NULL, NULL};
//     Tree d3 = {6, NULL, NULL};
//     Tree d4 = {8, NULL, NULL};

//     Tree c1 = {1, &d1, &d2};

//     Tree c3 = {3, NULL, &d3};
//     Tree c4 = {-1, NULL, &d4};

//     Tree b1 = {2, &c1, NULL};
//     Tree b2 = {4, &c3, &c4};

//     Tree root = {0, &b1, &b2};

//     int max = maxDepth(&root);
//     printf("%d\n", max);

//     return 0;
// }

int maxDepth(struct TreeNode *root) {
    if (!root) {
        return 0;
    }

    struct TreeNode *temp = root;
    Queue *queue = NULL;
    Queue *pop;

    int deepth = 0;
    insert(&queue, temp);

    while (queue) {
        deepth++;
        int len = getLength(queue);
        for (int i = 0; i < len; i++) {
            pop = queue;
            queue = queue->next;

            if (pop->node->left) {
                insert(&queue, pop->node->left);
            }

            if (pop->node->right) {
                insert(&queue, pop->node->right);
            }

            free(pop);
        }
    }
    return deepth;
}

int insert(Queue **queue, struct TreeNode *treeNode) {
    Queue *s = malloc(sizeof(Queue));
    s->node = treeNode;
    s->next = NULL;

    if (*queue) {
        Queue *last = findLast(*queue);
        last->next = s;
    } else {
        (*queue) = s;
    }

    return 1;
}

Queue *findLast(Queue *q) {
    if (!q) {
        return NULL;
    }
    Queue *iterator = q;
    while (iterator->next) {
        iterator = iterator->next;
    }

    return iterator;
}

int getLength(Queue *q) {
    int count = 0;
    Queue *tmp = q;
    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}