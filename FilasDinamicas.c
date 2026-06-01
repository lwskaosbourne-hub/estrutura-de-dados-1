#include <stdio.h>
#include <stdlib.h>

#define MAX_FILA 5

typedef struct {
    int id_requisicao;
} Elemento;

typedef struct {
    Elemento dados[MAX_FILA];
    int ini;
    int fim;
} Fila;

void iniciarFila(Fila *f){
    f->ini = 0;
    f->fim = -1;
}

void exibirEsteira(Fila *f){
    printf("------ ESTADO DA ESTEIRA ------\n");

    if (f->ini > f->fim){
        printf("Esteira vazia!\n");
    }else{
        printf("Saida (head) -> ");
        for (int i = f->ini; i <= f->fim; i++){
            printf("%d - ", f->dados[i].id_requisicao);
        }
        printf("<- Entrada (tail)\n");
    }

    printf("-------------------------------\n");
}

// Enfileirar:
int enqueue(Fila *f, Elemento novo_elemento){
    printf("[Tentativa] Solicitacao de Enqueue para o ID: %d...\n", novo_elemento.id_requisicao);
    if (f->fim == MAX_FILA - 1){
        printf("[ALERTA CRITICO] Erro de Overflow! A fila atingiu o limite.\n");
        printf("        Requisicao %d rejeitada.\n", novo_elemento.id_requisicao);
        return 0;
    }
        
    f->fim++;
    f->dados[f->fim] = novo_elemento;

    printf("[SUCESSO] Elemento inserido na cauda (Indice atual do fim %d)\n\n", f->fim);

    return 1;
}

// Desenfileirar:
int dequeue(Fila *f, Elemento *elementoAtendido){
    printf("[Tentativa] Solicitacao de Dequeue\n");
    if (f->ini > f->fim){
        printf("[ALERTA CRITICO] Erro de Underflow! A fila esta vazia.\n");
        printf("        Requisicao rejeitada.\n");
        return 0;
    }
    
    *elementoAtendido = f->dados[f->ini];
    f->ini++;

    printf("[SUCESSO] Requisicao %d processada.\n", elementoAtendido->id_requisicao);
}

int main(void) {
    printf("\n============================================\n");
    printf("======== SISTEMA DE GENTAO DE FLUXO ========\n");
    printf("============================================\n");

    printf("[SISTEMA] Aplicando o paradigma FIFO.\n");
    Fila filaAtendimento;
    iniciarFila(&filaAtendimento);
    exibirEsteira(&filaAtendimento);

    Elemento e1 = {.id_requisicao = 101};
    Elemento e2 = {.id_requisicao = 102};
    Elemento e3 = {.id_requisicao = 103};
    Elemento e4 = {.id_requisicao = 104};
    Elemento e5 = {.id_requisicao = 105};
    Elemento e6 = {.id_requisicao = 106};

    enqueue(&filaAtendimento, e1);
    enqueue(&filaAtendimento, e2);
    enqueue(&filaAtendimento, e3);
    
    exibirEsteira(&filaAtendimento);

    enqueue(&filaAtendimento, e4);
    enqueue(&filaAtendimento, e5);
    
    exibirEsteira(&filaAtendimento);

    enqueue(&filaAtendimento, e6);

    exibirEsteira(&filaAtendimento);

    printf("################## INICIO DO ATENDIMENTO ################");
    
    dequeue(&filaAtendimento, &e1);
    dequeue(&filaAtendimento, &e2);
    
    exibirEsteira(&filaAtendimento);

    return 0;
}