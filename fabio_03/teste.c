#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void desenha(){
    printf("\n============================ \n");
}

int main(void){

    int numero;
    numero = -11;

    int modulo;
    modulo = abs(numero);

    printf("Modulo: %d", modulo);

}