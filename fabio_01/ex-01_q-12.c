#include <stdio.h>
#include <stdlib.h>

int main(){
    int quantidade;
    printf("Quantidade de notas: ");
    scanf("%d", &quantidade);

    float notas[quantidade];
    int i=-1;
    
    do
    {
        i++;
        printf("Digite o valor da nota: ");
        scanf("%f", &notas[i]);
         
        while ((notas[i]<-1) || (notas[i]>10)){
            printf("VALOR INVALIDO!!! DIGITE NOVAMENTE!!!\n\n");
            printf("Digite o valor da nota: ");
            scanf("%f", &notas[i]);
        }

    } while (notas[i] != -1);
    
    printf("%d", i);
    
    for (int i=0; i<quantidade; i++)
    {
        printf("\nNota na %d posicao: %.2f.", i+1, notas[i]);
    }


    return 0;
}
