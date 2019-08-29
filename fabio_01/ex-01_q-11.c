#include <stdio.h>
#include <math.h>

int main(){
    int vetor[5];

    for(int i=0; i<5; i++){
        printf("Digite o dado %dª posicao: ", i+1);
        scanf("%d", &vetor[i]);
        while ((vetor[i]<1) || (vetor[i]>6)){
            printf("VALOR INVALIDO!!! DIGITE NOVAMENTE!!!\n\n");
            printf("Digite o dado %dª posicao: ", i+1);
            scanf("%d", &vetor[i]);
        }
    }

    int quant1, quant2, quant3, quant4, quant5, quant6;
    for (int i=0; i<5; i++){
        if (vetor[i] == 1){
            quant1++;
        }
        else if(vetor[i]==2){
            quant2++;
        }
        else if(vetor[i]==3){
            quant3++;
        }
        else if(vetor[i]==4){
            quant4++;
        }
        else if(vetor[i]==5){
            quant5++;
        }
        else if(vetor[i]==6){
            quant6++;
        }
    }
    int por1;
    //por1 = (quant1/100)*50;

    printf("Porcentagem que o dado deu 1: %d", por1);


    return 0;
}