#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    char veiculo[5];

    for (int i=0; i<5; i++)
    {
        printf("Digite o nome do carro na %dª posicao: ", i+1);
        scanf("%s", &veiculo[i]);
        
    }


    srand(time(NULL));
    float consumo[5];
    for(int i=0; i<5; i++)
    {
        consumo[i] = 7.0 + (rand()) % 20;
    }

    for(int i=0; i<5; i++)
    {
        printf("Valor na %dª posicao: %.2fl", i+1, consumo[i]);
    }



}