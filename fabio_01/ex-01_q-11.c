#include <stdio.h>
#include <math.h>

int main(){
    int vetor[50];

    for(int i=0; i<50; i++){
        printf("Digite o dado %dª posicao: ", i+1);
        scanf("%d", &vetor[i]);
        while ((vetor[i]<1) || (vetor[i]>6)){
            printf("VALOR INVALIDO!!! DIGITE NOVAMENTE!!!\n\n");
            printf("Digite o dado %dª posicao: ", i+1);
            scanf("%d", &vetor[i]);
        }
    }

    int quant1=0, quant2=0, quant3=0, quant4=0, quant5=0, quant6=0;
    for (int i=0; i<50; i++){
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
    
    int total;
    total = quant1+quant2+quant3+quant4+quant5+quant6;

    int porcentagem[6];
    porcentagem[0] = (quant1*100) / total;
    porcentagem[1] = (quant2*100) / total;
    porcentagem[2] = (quant3*100) / total;
    porcentagem[3] = (quant4*100) / total;
    porcentagem[4] = (quant5*100) / total;
    porcentagem[5] = (quant6*100) / total;

    for (int i=0; i<6; i++){
        printf("\nPorcentagem de vezes que foi %d: %d%%.", i+1, porcentagem[i]);
    }
    printf("\n\n");
    

    return 0;
}
