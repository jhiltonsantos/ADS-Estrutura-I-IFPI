//
// Created by hilton on 29/08/2019.
//

#include <stdio.h>

int main(){
    int quantidade;
    
    printf("Determine quantidade de posicoes no vetor A: ");
    scanf("%d", &quantidade);

    printf("\n");

    int vetorA[quantidade], vetorB[quantidade];
	// Valores do Vetor A
    for (int i=0; i<quantidade; i++){
        printf("Digite o valor na %dª posicao do vetor A: ", i+1);
        scanf("%d", &vetorA[i]);
    }
    printf("\n");
    
    // Gerando Vetor B
    for (int i=0; i<quantidade; i++){
        if (vetorA[i] % 2 == 0){
            vetorB[i] = 0;
        }
        else{
            vetorB[i] = 1;
        }
    }

    for (int i=0; i<quantidade; i++){
        printf("Valor do Vetor B na %dª posicao: %d\n", i+1, vetorB[i]);
    }
    
    return 0;

}
