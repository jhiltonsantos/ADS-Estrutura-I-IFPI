#include <stdio.h>
#include <stdlib.h>


typedef struct ficha_notas
{
    float Notas;
    int Valida;
}Notas;


int main(){
    Notas ficha[100];
    int i=-1;
    
    do
    {
        i++;
        printf("Digite o valor da nota: ");
        scanf("%f", &ficha[i].Notas);
         
        while ((ficha[i].Notas<-1) || (ficha[i].Notas>10)){
            printf("VALOR INVALIDO!!! DIGITE NOVAMENTE!!!\n\n");
            printf("Digite o valor da nota: ");
            scanf("%f", &ficha[i].Notas);
        }
        ficha[i].Valida = 1;

    } while (ficha[i].Notas != -1);
    
    printf("\nQuantidade de notas lidas: %d.\n\n", i);
    printf("Notas Lidas Na Ordem: ");
    
    float soma=0, media=0;
    int divisor=0, abaixo=0;
    for (int i=0; i<100; i++)
    {
        if ((ficha[i].Valida == 1) && (ficha[i].Notas >= 0))
        {
            //printf("\nNota na %d posicao: %.1f.", i+1, ficha[i].Notas);
            printf("%.1f - " , ficha[i].Notas);
            
            if (ficha[i].Notas < 7.0)
            {
                abaixo++;
            }
            soma += ficha[i].Notas;
            divisor++;
        }
        
    }
    media = soma / divisor;
    printf("\n\nSoma das Notas: %.1f.", soma);
    printf("\nMedia das Notas: %.1f.", media);
    printf("\nQuantidade de Notas Abaixo de 7: %d\n\n", abaixo);
    printf("\n\nFIM DO PROGRAMA");

    return 0;
}
