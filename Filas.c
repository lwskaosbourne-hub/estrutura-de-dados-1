#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

//Estrutura da fila
struct tipo_fila{
    int dados[tamanho];
    int ini;
    int fim;
};

//Variaveis globais
struct tipo_fila fila;

//Prototipos
void enfileira();
void desenfileira();
void fila_mostrar();
void menu_mostrar();

//Função principal
int main(void)
{
    //setlocale(LC_ALL, "Portuguese");
    int op = 1;
    fila.ini = 0;
    fila.fim = 0;
    while (op != 0)
    {
        system("cls");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            enfileira();
            break;
        case 2:
            desenfileira();
            break;
        default:
            break;
        }
    }
    
    return 0;
}


void enfileira(){ // push_back
    if(fila.fim == tamanho){
        printf("Fila cheia!\n");
        system("pause");
    }
    else{
        printf("\nDigite o valor: ");
        scanf("%d", &fila.dados[fila.fim]);
        fila.fim++;
    }
}

void desenfileira(){
    if(fila.fim == fila.ini){
        printf("Fila vazia!\n");
        system("pause");
    }
    else{
        for(int i=0; i<tamanho; i++){
            fila.dados[i] = fila.dados[i+1];
        }
        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
}

//Mostrar conteúdo da fila
void fila_mostrar(){
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", fila.dados[i]);
    }
    printf("]\n\n");
}

//Mostrar opções
void menu_mostrar() {
    printf("\n Escolha uma opção: \n");
    printf("1 - Incluir na fila \n");
    printf("2 - Excluir da fila \n");
    printf("0 - Sair \n \n");
}