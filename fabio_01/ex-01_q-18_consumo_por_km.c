#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct ficha_veiculo
{
        char Nome[20];
        float Consumo;
        float Valor;
} Carro;


int main(void){
    Carro veiculo[5];
    
    srand(time(NULL));
    for (int i=0; i<5; i++)
    {
        printf("Digite o nome do carro na %dª posicao: ", i+1);
        scanf("%s", veiculo[i].Nome);
        veiculo[i].Consumo = (7 + (rand()) % 20);
        veiculo[i].Valor = (1000 / veiculo[i].Consumo) * 2,25;    
    }

    float mais_economico;
    mais_economico = veiculo[0].Valor;
    for(int i=0; i<5; i++)
    {
        if (veiculo[i].Valor < mais_economico)
        {
            mais_economico = veiculo[i].Valor;
        }
    }

    printf("\n\nComparativo de Consumo de Combustivel\n");
    for(int i=0; i<5; i++){
        printf("Veiculo %d\n", i+1);
        printf("Nome: %s\n", veiculo[i].Nome);
        printf("Km por litro: %.1f\n", veiculo[i].Consumo);
        
    }

    printf("\n\nRelatorio Final\n");
    for(int i=0; i<5; i++){
        float quantLitros;
        quantLitros = 1000 / veiculo[i].Consumo;
        printf("%d-%s    - %.1f - %.1f litros - R$ %.2f\n", i+1, veiculo[i].Nome,\
         veiculo[i].Consumo, quantLitros, veiculo[i].Valor);    
    }

    for(int i=0; i<5; i++)
    {
        if (veiculo[i].Valor == mais_economico)
        {   
            printf("\nO menor consumo eh do %s.\n\n", veiculo[i].Nome);
        }
    }
}
