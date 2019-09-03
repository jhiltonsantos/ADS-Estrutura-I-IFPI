#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ficha_jogador
{
    int Numero, Votos, Melhor;
    float Porcentual;
} Player;

int main(void){
    Player jogador[23];

    for(int i=0; i<23; i++){
        jogador[i].Numero = i+1;
    }
    
    int i=0, total=0, dado=0;
    int voto[23];
    do
    {
        printf("Digite o Numero do melhor Jogador  ");
        scanf("%d", &dado);
        while ((dado<0) || (dado>23))
        {
            printf("VALOR INVALIDO!!! DIGITE NOVAMENTE!!!\n\n");
            printf("Digite o Numero do melhor Jogador:  ");
            scanf("%d", &dado);
        }
        
        if (dado != 0){
            voto[i] = dado;
            total ++;
        }
        i ++;
        asdasdasd
        

    } while (dado != 0);

    printf("Total de Votos: %d. \n\n", total);
    return 0;
}
