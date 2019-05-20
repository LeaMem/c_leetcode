#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct LList {
    int data;
    int size;
    struct LList* next;
};
typedef struct LList Kitty;
Kitty* getKitty(Kitty* list, int data);
void insert(Kitty** list, int data);
bool check(Kitty* list);
void freeMem(Kitty* list);
int gcd(int a, int b);

// bool hasGroupsSizeX(int* deck, int deckSize);

// int main() {
//     // int a[] = {1, 1, 1, 2, 2, 2, 3, 3};
//     // bool res = hasGroupsSizeX(a, 8);

//     int a = 1 & 0;
//     printf("%d\n", a);

//     return a;
// }

bool hasGroupsSizeX(int* deck, int deckSize) {
    if (deckSize <= 1) {
        return false;
    }

    Kitty* list = NULL;
    for (int i = 0; i < deckSize; i++) {
        insert(&list, deck[i]);
    }

    bool flag = check(list);

    //开始释放内存
    // freeMem(list);
    return flag;
}

void insert(Kitty** list, int data) {
    Kitty* pos = getKitty(*list, data);
    if (!pos) {
        Kitty* s = calloc(1, sizeof(Kitty));
        s->data = data;
        s->size = 1;
        s->next = NULL;
        if (list) {
            s->next = *list;
        }
        *list = s;
    } else {
        pos->size++;
    }
}

Kitty* getKitty(Kitty* list, int data) {
    Kitty* iterator = list;
    while (iterator) {
        if (iterator->data == data) {
            return iterator;
        }
        iterator = iterator->next;
    }

    return iterator;
}

bool check(Kitty* list) {
    Kitty* iterator = list;
    bool flag = true;

    int num = iterator->size;

    while (iterator) {
        num = gcd(num, iterator->size);

        // 2的整数才可以
        int tmp = num & (num - 1);

        if (num < 2) {
            flag = false; 
            break;
        }

        iterator = iterator->next;
    }

    return flag;
}

void freeMem(Kitty* list) {
    Kitty* it = list;
    while (it) {
        Kitty* tmp = it;
        it = it->next;
        free(tmp);
    }
}

int gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}