//
// Created by hilton on 29/08/2019.
//


#include <stdio.h>

int main(){
    int quantidade, x;
    
    printf("Determine quantidade de posicoes no vetor: ");
    scanf("%d", &quantidade);
    printf("\n");

    int vetor[quantidade];
    for(int i=0; i<quantidade; i++){
        printf("Digite o valor na %dª posicao do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for(int i=0; i<quantidade; i++){
        for(int j=i; j<quantidade; j++){
            if(vetor[i] > vetor[j]){
                x = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = x;
            }
        }
    }

    for (int i=0; i<quantidade; i++){
        printf("\nValor na %dª posicao: %d\n", i+1, vetor[i]);
    }

    return 0;
}