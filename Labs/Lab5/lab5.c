#include <stdio.h>

int main() {
    int i = 4, j = 0;
    while (i) {
        printf("\n%d", j);
        --i && j++;
    }
}