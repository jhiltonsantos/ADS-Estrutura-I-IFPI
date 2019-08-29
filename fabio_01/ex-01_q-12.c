#include <stdio.h>
#include <stdlib.h>

int main(){
    int quantidade;
    printf("Quantidade de notas: ");
    scanf("%d", &quantidade);

    float notas[quantidade];
    int i=0;
    notas[0] = 0;
    while (notas[i] != -1)
    {
        printf("Digite o valor da nota: ");
        scanf("%f", &notas[i]);
        i++;
    }

    printf("%d", i);
    
    for (int i=0; i<quantidade; i++)
    {
        printf("\nNota na %dª posicao: %f%%.", i+1, notas[i]);
    }


    return 0;
}
