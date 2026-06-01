#include <stdio.h>
#include <stdlib.h>

// malloc() Aloca um bloco de bytes em memória
// free() Libera o espaço de memória alocado a um ponteiro

/*
    TAMANHO DOS TIPOS PRIMITIVOS:
        - Int: 4 bytes
        - Char: 1 byte
        - Float: 4 bytes
        - Double: 8 bytes
        - Bool: 1 byte

        também posso usar o sizeof(<nome do tipo>)
*/

void teste1(){
    int *p;
    p = (int *) malloc(sizeof(int));
    if(p == NULL){
        printf("Erro!\n");
    }
    else{
        *p = 10;
        printf("p: %d\n", *p);
        free(p);
    }
}

// Vetores:
void teste2(){
    int *vetor;
    int tamanho = 0;
    int sys = 1;

    while (sys == 1)
    {
        printf("\nNUMERO DE VETORES: %d", tamanho);
        for (int i = 0; i < tamanho; i++)
        {
            printf("");
        }
        
    }
    
    vetor = (int *) malloc(sizeof(int)*tamanho);
    free(vetor);
}

int main(void){
    teste2();

    return 0;
}