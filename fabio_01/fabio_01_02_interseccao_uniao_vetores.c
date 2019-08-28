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
    /*
    for (int i=0; i<quantA;i++){
        printf("Vetor A");
        printf("Valor na posicao %d: %d\n", i+1,vetorA[i]);
    }
    for (int i=0; i<quantB;i++){
        printf("Vetor B");
        printf("Valor na posicao %d: %d\n", i+1,vetorB[i]);
    }
    */

    /*
    int tamanho;
    soma = quantA + quantB;
    for (int i=0; i<soma;i++){
        if (vetorA[i]!=vetorB[i]){
            tamanho = tamanho+1;
        }
    }



    int vetorU[tamanho], vetorI[soma];

    for (int i=0;i<quantA;i++){
        vetorU[i] = vetorA[i];
    }

    for (int i=0;i<tamanho;i++){
        for (int i=0;i<quantB;i++){
            if (vetorU[i] != vetorB[i]){
                vetorU[i+1] = vetorB[i];
            }
        }
    }


    for (int i=0; i<tamanho;i++){
        printf("Valor na posicao %d: %d\n", i+1,vetorU[i]);
    }
    */

    return 0;


}
