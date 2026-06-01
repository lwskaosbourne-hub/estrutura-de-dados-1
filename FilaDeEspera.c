#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    int id_paciente;
    struct Paciente* proximo;
} Paciente;

typedef struct{
    Paciente* ini;
    Paciente* fim;
} Fila;

void iniciarFila(Fila* f){
    f->ini = NULL;
    f->fim = NULL;
}

void adicionar(Fila* f, int id){
    Paciente* novoPaciente = (Paciente*) malloc(sizeof(Paciente));
    if(novoPaciente == NULL){
        printf("ERRO - Memoria cheia!\n");
        return;
    }

    novoPaciente->proximo = NULL;
    novoPaciente->id_paciente = id;

    if(f->ini == NULL){
        f->ini = novoPaciente;
        f->fim = novoPaciente;
    }else{
        f->fim->proximo = novoPaciente;
        f->fim = novoPaciente;
    }

    printf("Paciente %d adicionado a fila com sucesso.\n", novoPaciente->id_paciente);
}

void remover(Fila* f){
    if(f->ini == NULL){
        printf("A fila esta vazia!\n");
        return;
    }

    Paciente* temp = f->ini;
    printf("Chamar o paciente codigo %d...\n", temp->id_paciente);

    f->ini = f->ini->proximo;

    if(f->ini == NULL){
        f->fim = NULL;
    }

    free(temp);
}

void exibirFila(Fila* f) {
    if (f->ini == NULL) {
        printf("Fila atual: [Vazia]\n\n");
        return;
    }
    Paciente* atual = f->ini;
    printf("Fila atual: ");
    while (atual != NULL) {
        printf("[%d] ", atual->id_paciente);
        atual = atual->proximo;
    }
    printf("\n\n");
}

void liberarFila(Fila *f){
    if(f->ini != NULL){
        Paciente* atual = f->ini;
        Paciente* prox;
        while(atual != NULL){
            prox = atual->proximo;

            printf("Liberando paciente ID: %d\n", atual->id_paciente);

            free(atual);

            atual = prox;
        }

        f->ini = NULL;
        f->fim = NULL;
    
        printf("Todos os elementos foram liberados com sucesso!\n\n");
    }
}

int main(void){
    Fila filaDeEspera;
    iniciarFila(&filaDeEspera);

    adicionar(&filaDeEspera, 100);
    adicionar(&filaDeEspera, 101);
    adicionar(&filaDeEspera, 102);
    adicionar(&filaDeEspera, 103);
    adicionar(&filaDeEspera, 104);
    adicionar(&filaDeEspera, 105);
    adicionar(&filaDeEspera, 106);

    exibirFila(&filaDeEspera);

    liberarFila(&filaDeEspera);

    return 0;
}