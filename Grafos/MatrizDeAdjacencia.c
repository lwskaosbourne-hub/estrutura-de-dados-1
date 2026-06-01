#include <stdio.h>

// Estrutura em matriz, linhas e colunas representam os vértices
// Considere dois vértices Vi e Vj;
// ADJ é a matriz de adjacência;
// ADJ[Vi][Vj] = 1 se existe a aresta (Vi, Vj);
// ADJ[Vi][Vj] = 0 em caso contrário.

#define MAX_VERTICES 10

typedef struct {
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} GrafoMatriz;

void iniciarGravo(GrafoMatriz *g, int v){
    g->num_vertices = v;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            g->matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(GrafoMatriz *g, int origem, int destino){
    g->matriz[origem][destino] = 1;
    g->matriz[destino][origem] = 1;
}

void DFS(GrafoMatriz *g, int v, int visitados[]){
    visitados[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->num_vertices; i++){
        if(g->matriz[v][i] != 0 && !visitados[i]){
            DFS(g, i, visitados);
        }
    }
    
}

int main(void) {
    GrafoMatriz grafo;
    int visitadosDFS[MAX_VERTICES] = {0};

    iniciarGravo(&grafo, 4);

    adicionarAresta(&grafo, 0, 1);
    adicionarAresta(&grafo, 0, 2);
    adicionarAresta(&grafo, 1, 2);

    printf("Grafo criado com sucesso.\n");

    for (int i = 0; i < grafo.num_vertices; i++){
        for (int j = 0; j < grafo.num_vertices; j++){
            if (grafo.matriz[i][j] == 1)
            {
                printf("(%d, %d)\n", i, j);
            }
        }
    }

    DFS(&grafo, 3, visitadosDFS);

    return 0;
}