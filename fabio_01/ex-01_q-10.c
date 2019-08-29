// ENTENDI A QUESTÃO COMO SENDO A MESMA COISA DA ANTERIOR

#include <stdio.h> 

int main(){
    int quantidade;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &quantidade);

    int vetor[quantidade];
    for (int i=0; i<quantidade; i++){
        printf("Digite o valor do %dº termo do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int soma=0, media=0;
    for (int i=0; i<quantidade; i++){
        soma += vetor[i];
    }
    
    media = soma / quantidade;

    printf("\n\nO valor da soma dos valores no vetor eh: %d.", soma);
    printf("\nO valor da media dos valores no vetor eh: %d.\n\n", media);

    return 0;
}
