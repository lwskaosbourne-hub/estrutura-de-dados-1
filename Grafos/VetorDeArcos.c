#include <stdio.h>
#include <stdlib.h>

// É um método que usa apenas um único vetor usando uma Struct para definir as arestas (arcos)
// É uma estrutura mais simples, porém mais lenta

#define TAM 25

typedef struct{
    int v1;
    int vj;
    int peso;
} arc;

arc grafo[TAM];