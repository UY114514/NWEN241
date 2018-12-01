//
// Created by UY114514 on 2018/11/12.
//

//
// Created by UY114514 on 2018/11/7.
//

#include <stdio.h>

int *max(int *p,int *q) {
    int *r_max;
    if (*p > *q) {
        r_max = p;
    } else {
        r_max = q;
    }
    return r_max;
}

int main(void) {
    int x = 10;
    int y = 13;
    printf("X=");
    scanf("%d", &x);
    printf("\nY=");
    scanf("%d", &x);
    int *p;
    int *(*fun)(int *, int *);
//    fun = max;
    p = fun(&x, &y);
    printf("max(x,y) = %d", *p);
    return 0;
}




