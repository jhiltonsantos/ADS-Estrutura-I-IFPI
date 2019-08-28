//
// Created by hilton on 27/08/2019.
//

#include <stdio.h>

int main(){
    // TAMANHO DOS VETORES 'A' E 'B'
    int quantA, quantB;
    printf("Determine quantidade de posicoes no vetor A: ");
    scanf("%d", &quantA);
    printf("Determine quantidade de posicoes no vetor B: ");
    scanf("%d", &quantB);

    printf("\n");
    int vetorA[quantA], vetorB[quantB];
	// ADICIONANDO VALORES EM VETOR 'A' E 'B'
    for (int i=0;i<quantA;i++){
        printf("Digite o valor na posicao %d no vetor A: ", i+1);
        scanf("%d", &vetorA[i]);
    }
    printf("\n");
    for (int i=0;i<quantB;i++){
        printf("Digite o valor na posicao %d no vetor B: ", i+1);
        scanf("%d", &vetorB[i]);
    }
    
    // DETERMINANDO VETOR DE UNIAO
    /*int maior_vetor;
    if (quantA>quantB){
        maior_vetor = quantA;
    }
    else{
        maior_vetor = quantB;
    }*/

    int soma;
    soma = quantA + quantB;
    int vetorU[soma];

    for (int i=0;i<quantA;i++){
        vetorU[i] = vetorA[i];
    }
    
    for (int i=0; i<soma;i++){
        for (int k=0;k<quantB;k++){
            if (vetorU[i] == vetorB[k]){
                vetorU[i] = vetorB[k];
            }
        }
    }

    for (int i=0; i<soma;i++){
        printf("Valor na posicao %d: %d\n", i+1,vetorU[i]);
    }



    return 0;
    //system("PAUSE");

}
