#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findNext(char *pattern, int *next);

int main() {
    char *pattern = "ababaca";

    int *next = calloc(strlen(pattern), sizeof(int));

    findNext(pattern, next);

    for (int i = 0; i < strlen(pattern); i++) {
        printf("%d\t %d\t\n", i, next[i]);
    }

    free(next);
    
    return 0;
}

void findNext(char *pattern, int *next) {
    int len = strlen(pattern);
    next[0] = 0;
    for (int i = 1; i < len; i++) {
        int j = next[i - 1];  // j 表示前后缀形同的个数

        //如果pattern[j] 跟 pattern[i] 不相等了，就倒退
        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            next[i] = j + 1;
        } else {
            next[i] = 0;
        }
    }
}
