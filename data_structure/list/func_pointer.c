#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int (*f)(int, int);

int main() {
    f = max;

    int c = (*f)(1, 2);

    printf("max is %d\n", c);

    f = min;

    c = (*f)(1, 2);

    printf("min is %d\n", c);

    return 0;
}
