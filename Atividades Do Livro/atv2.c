#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Semaforo{
    char cor[10];
    int id;
};


int main(void){
    struct Semaforo semaforo[3];
    strcpy(semaforo[0].cor, "Vermelho");
    semaforo[0].id = 1;
    strcpy(semaforo[1].cor, "Amarelo");
    semaforo[1].id = 2;
    strcpy(semaforo[2].cor, "Verde");
    semaforo[2].id = 3;

    struct Semaforo *ptr;
    ptr = (struct Semaforo *) malloc(sizeof(struct Semaforo));
    *ptr->cor = semaforo[0].cor;

    printf("%s", *ptr->cor);

    return 0;
}