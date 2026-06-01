#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da lista:
typedef struct {
    int dado;
    struct no *proximo;
} no;

// Variáveis globais:
typedef struct no* ptr_no;
ptr_no lista;
int op;

// Prototipação:
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

// Função principal:
int main(void) {
    // Inicia máquina de numeros aleatórios:
    srand(time(NULL));
    op = 1;
    // Criando o primeiro nó da lista:
    lista = (ptr_no) malloc(sizeof(struct no));
    lista->dado = 0;
    lista->proximo = NULL;
    // Laço principal:
    while (op != 0) {
        system("cls");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }

    system("Pause");

    free(lista);

    return 0;
}

void menu_mostrar() {
    lista_mostrar(lista);
    printf("\n\nEscolha uma opção:\n");
    printf("1 - Inserir\n2 - Remover\n0 - Sair\n\n");
}

void menu_selecionar(int op) {
    switch (op) {
    case 1:
        lista_inserir(lista);
        break;
    case 2:
    lista_remover(lista);
        break;
    default:
        break;
    }
}

void lista_inserir(ptr_no lista) {
    while (lista->proximo != NULL) {
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no) malloc(sizeof(struct no));
    lista = lista->proximo;
    lista->dado = rand()%100;
    lista->proximo = NULL;
}
