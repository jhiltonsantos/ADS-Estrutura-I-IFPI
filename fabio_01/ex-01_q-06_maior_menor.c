#include <stdio.h>
#include <math.h>

int main(){
    int quantidade, maior, menor;
    
    printf("Determine quantidade de posicoes no vetor: ");
    scanf("%d", &quantidade);
    printf("\n");

    int vetor[quantidade];
    for(int i=0; i<quantidade; i++){
        printf("Digite o valor na %dª posicao do vetor: ", i+1);
        scanf("%d", &vetor[i]);

        if (i==0){
            maior = vetor[i];
            menor = vetor[i];
        }
    }

    for (int i=0; i<quantidade; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }

        if (vetor[i] < menor){
            menor = vetor[i];
        } 
    }

    printf("\n\nO maior valor eh: %d.\nE o menor valor eh: %d.\n", maior, menor);

    return 0;
}
