#include <stdio.h>
#include <stdlib.h>

// Para cada vértice, uma lista de seus adjacentes.
//--------------------------------------------------
// Define-se uma estrutura chamada "nó" (nó = vértice Vj, e ponteiro para nó)
// Cria-se um vetor de nós.
// Para cada posição Vi no vetor, se Vj é adjacente adcione-o na lista.

#define N 5

typedef struct str_no {
    int v;
    str_no *proximo;
} str_no;

str_no grafo[N];