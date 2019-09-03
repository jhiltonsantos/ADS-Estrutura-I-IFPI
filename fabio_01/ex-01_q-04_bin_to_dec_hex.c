//
// Created by hilton on 27/08/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(){
    int vetor[8];
    int numero, x;

    printf("Digite o numero: ");
    scanf("%d", &numero);

    for (int i=7;i>-1;i--){
        x = numero %10;
        numero = numero / 10;
        vetor[i] = x;
    }

    // Binario para Decimal
    int k=8, valor=0;

    for (int i=0; i<8; i++){
        valor += (vetor[i] * pow(2, k))/2;
        k--;
    }

    printf("Valor Decimal eh: %d!!!\n", valor);

    // Binario para Hexadecimal
    //printf("Hexadecimal eh: %x.\n", valor);


    return 0;


}

