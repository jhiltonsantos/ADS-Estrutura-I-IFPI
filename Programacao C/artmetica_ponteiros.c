#include <stdio.h>
#include <stdlib.h>

void main(){
    int *vetor;
    int *ponteiro;

    vetor = (int *)malloc(sizeof(int)*10); // vetor de ate 10 posicoes usando malloc
    vetor[4] = 44;

    ponteiro = vetor; //aponta para vetor[0]
    *ponteiro = 11;   //recebe valor para onde ele esta apontando vetor[2]
    ponteiro ++;      //passa para vetor[1]
    *ponteiro = 12;   //recebe valor para onde ele esta apontando vetor[2]

    printf("\nPosicao apontada: %p", ponteiro);
    printf("\nPonteiro: %d", *ponteiro);

    ponteiro --;      // Para dar free o Ponteiro tem que voltar para a posicao inicial
    free(ponteiro);
}
