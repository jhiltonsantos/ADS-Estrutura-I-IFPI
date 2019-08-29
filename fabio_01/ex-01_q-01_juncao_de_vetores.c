//
// Created by hilton on 27/08/2019.
//

#include <stdio.h>

int main(){
    int quantA, quantB, soma;
    printf("Determine quantidade de posicoes no vetor A: ");
    scanf("%d", &quantA);
    printf("Determine quantidade de posicoes no vetor B: ");
    scanf("%d", &quantB);

    printf("\n");
    int vetorA[quantA], vetorB[quantB];

    for (int i=0;i<quantA;i++){
        printf("Digite o valor na posicao %d no vetor A: ", i+1);
        scanf("%d", &vetorA[i]);
    }
    printf("\n");
    for (int i=0;i<quantB;i++){
        printf("Digite o valor na posicao %d no vetor B: ", i+1);
        scanf("%d", &vetorB[i]);
    }

    soma = quantA + quantB;
    int vetorC[soma];

    for (int i=0; i<quantA;i++){
        vetorC[i] = vetorA[i];
    }
    for (int i=0; i<quantB;i++){
        vetorC[i+quantA]= vetorB[i];
    }

    printf("\n");

    for (int i=0; i<soma;i++){
        printf("Valor na posicao %d: %d\n", i+1,vetorC[i]);
    }

    return 0;
}



