#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 42;

    printf("Endereco: %p\nValor: %d", &ptr, *ptr);

    free(ptr);
    return 0;
}