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
        consumo[i] = (7 + (rand()) % 20);
    }
    

    float mais_economico;
    mais_economico = consumo[0];
    for(int i=0; i<5; i++)
    {
        if (consumo[i] < mais_economico)
        {
            mais_economico = consumo[0];
        }
        
    }


    printf("\n\nComparativo de Consumo de Combustivel\n");
    printf("O menor consumo é: %.2f", mais_economico);


}