#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int hammingWeight(uint32_t n);
int main() {



}

int hammingWeight(uint32_t n) {
 

    int count = 0;
    while(n != 0){

        count += n % 2;
        n /= 2;
    }
    return count;
}