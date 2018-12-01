//
// Created by UY114514 on 2018/11/19.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index;
    printf("Enter N:");

    scanf("%d", &N);


    int *address = (int *) calloc(N, sizeof(int));
//    int *address = (int *) malloc(sizeof(int) * N);
    //MAKE SURE GOT RAM
    if (address == NULL) {
        printf("\nERROR: FAILED TO ALLOCATE RAM");
        return 0;
    }

    //GET INPUT
    for (int i = 0; i < N; i++) {
        printf("\nInput number %i:",i+1);
        scanf("%i", (address + i));
    }

    int biggest=0;
    //DO CALC
    for (int i = 0; i < N; i++) {
        if (*(address + i) > biggest) {
            biggest = *(address + i);
        }
    }

    printf("\nBiggest=%i", biggest);
    free(address);
    return 0;

}



