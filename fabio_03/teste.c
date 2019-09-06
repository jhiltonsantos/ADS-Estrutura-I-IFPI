#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void desenha(){
    printf("\n============================ \n");
}

int main(void){

    desenha();

    char palavra[100];
    printf("Digite a palavra: ");

    setbuf(stdin, 0);
    fgets(palavra, 100, stdin);
    palavra[strlen(palavra-1)] = '\0';

    printf("A palavra eh: %s", palavra);

    int x = 20;
    int *p;
    p = &x;

    printf("%d", p);

    *p = 5;

    printf("\nNovo valor de x: %d", x);

    desenha();


}