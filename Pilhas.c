#include <stdio.h>
#include <stdlib.h>

#define tamanho 3

struct tipo_pilha{
    int dados[tamanho];
    int ini;
    int topo;
};

struct tipo_pilha pilha;

void empilha(int elemento){
    if(pilha.topo == tamanho){
        printf("Fila cheia!\n");
    }
    else{
        pilha.dados[pilha.topo] = elemento;
        pilha.topo++;
    }
}

int desempilha(){
    int elemento;
    if(pilha.topo == pilha.ini){
        printf("Fila vazia!\n");
        system("pause");
    }
    else{
        pilha.topo--;
        elemento = pilha.dados[pilha.topo];
        return elemento;
    }
}

int main(void){
    
    return 0;
}