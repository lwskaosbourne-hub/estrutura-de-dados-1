#include <stdio.h>
#include <stdlib.h>

// Implementação simples utilizando estruturas estáticas:
// - Matriz de adjacências - grafo não orientado.
// - Operações:
// 1: Inicializar o grafo (escolher o tamanho-n° de vértices).
// 2: Inserir aresta.
// 3: Remover aresta.
// 4: Exibir matriz de adjacências.

#define maximo 10

int ma[maximo][maximo];
int tamanho = 0;

int grafo_tamanho(){
    int tam = 0;
    while (tam > maximo || tam < 1){
        printf("Escolha a quantidade de vértices: \n");
        scanf("%d", &tam);
    }
    return tam;
}

void inserir_aresta(int num1, int num2){
    if(num1 > tamanho-1 || num2 > tamanho - 1 || num1 < 0 || num2 < 0){
        printf("Erro!");
        system("pause");
    }else{
        ma[num1][num2] = 1;
        ma[num2][num1] = 1;
    }
}

void remover_aresta(int num1, int num2){
    if(num1 > tamanho-1 || num2 > tamanho - 1 || num1 < 0 || num2 < 0){
        printf("Erro!");
        system("pause");
    }else{
        ma[num1][num2] = 0;
        ma[num2][num1] = 0;
    }
}

void exibir_ma(){
    printf("Matriz de arestas:\n");
    for (int i = 0; i < tamanho; i++){
        printf("( ");
        for (int j = 0; j < tamanho; i++){
            printf("%d ", ma[i][j]);
        }
        printf(")\n");
    }
    
}

int main(void){
    inserir_aresta(2, 2);

    exibir_ma();

    return 0;
}
