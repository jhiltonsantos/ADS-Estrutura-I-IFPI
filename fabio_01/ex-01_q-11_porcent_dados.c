#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int vetor[50];
    srand(time(NULL));

    for(int i=0; i<50; i++)
    {
        vetor[i] = ((rand() % 6) + 1);
    }
    
    int quant1=0, quant2=0, quant3=0, quant4=0, quant5=0, quant6=0;
    for (int i=0; i<50; i++)
    {
        if (vetor[i] == 1){
            quant1++;
        }
        else if (vetor[i]==2){
            quant2++;
        }
        else if (vetor[i]==3){
            quant3++;
        }
        else if (vetor[i]==4){
            quant4++;
        }
        else if (vetor[i]==5){
            quant5++;
        }
        else if (vetor[i]==6){
            quant6++;
        }
    }
    
    float porcentagem[6];
    porcentagem[0] = (quant1*100) / 50;
    porcentagem[1] = (quant2*100) / 50;
    porcentagem[2] = (quant3*100) / 50;
    porcentagem[3] = (quant4*100) / 50;
    porcentagem[4] = (quant5*100) / 50;
    porcentagem[5] = (quant6*100) / 50;

    for (int i=0; i<6; i++)
    {
        printf("\nPorcentagem de vezes que foi %d: %.2f%%.", i+1, porcentagem[i]);
    }
    printf("\n\n");
    

    return 0;
}
