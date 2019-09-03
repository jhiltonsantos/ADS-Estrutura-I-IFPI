//
// Created by hilton on 27/08/2019.
//

#include <stdio.h>
#include <math.h>

int main(){

    int vetor[20], calc, resultado;

    for (int i=0;i<20;i++){
        printf("Digite o valor na %d posicao: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for (int i=0; i<20;i++){
        if ((19-i) >= 10){
            calc = (vetor[i] - vetor[19-i]);
            resultado += (calc*calc);
        }
    }

    printf("O resultado eh: %d", resultado);
    return 0;
}
