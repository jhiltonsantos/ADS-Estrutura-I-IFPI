#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ficha_jogador
{
    int Numero, Votos;
    float Porcentual;
} Player;

int main(void){
    Player jogador[23];

    for(int i=0; i<23; i++){
        jogador[i].Numero = i+1;
        jogador[i].Votos = 0;
    }
    
    int i=0, total=0, dado=0;
    do
    {
        printf("Digite o Numero do melhor Jogador  ");
        scanf("%d", &dado);
        while ((dado<0) || (dado>23))
        {
            printf("Informe um valor entre 1 e 23 ou 0 para sair!\n");
            printf("Numero do jogador (0=fim):  ");
            scanf("%d", &dado);
        }
        
        for(int j=0; j<23; j++)
        {
            if (dado == jogador[j].Numero)
            {
                jogador[j].Votos += 1;
                total ++;
            }
        }
        i++;

    } while (dado != 0);

    printf("\n\nResultado da votacao: \n\n");
    printf("Foram computados %d votos. \n\n", total);

    printf("Jogador Votos       %%");
    for (int j=0; j<23; j++)
    {
        jogador[j].Porcentual = (jogador[j].Votos*100)/total;
        
        if (jogador[j].Votos > 0)
        {
            printf("\n%d        %d      %.2f %%",\
                 jogador[j].Numero, jogador[j].Votos, jogador[j].Porcentual);
        }
    }

    float melhor;
    melhor = jogador[0].Porcentual;
    for (int j=0; j<23; j++)
    {
        if (jogador[j].Porcentual > melhor){
            melhor = jogador[j].Porcentual;
        }
    }
    
    for (int j=0; j<23; j++)
    {
        if (jogador[j].Porcentual == melhor)
        {
            printf("\n\nO melhor jogador foi o numero %d, com %d votos, sendo %.2f%% do total de votos.\n\n",\
            jogador[j].Numero, jogador[j].Votos, jogador[j].Porcentual);
        }    
    }
    
    return 0;
}
