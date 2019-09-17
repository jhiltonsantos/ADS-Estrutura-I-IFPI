#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define tam 50

int main(){
    char *nome, *ultimo, *outros, *saida;
    nome = malloc(tam * sizeof(char));
    ultimo = malloc(tam * sizeof(char));
    outros = malloc(tam * sizeof(char));
    saida = malloc(tam * sizeof(char));

    printf("Digite seu nome: ");
    fgets(nome, tam, stdin);
    int tamanho = strlen(nome);

    int k = tamanho;
    while (nome[k] != ' '){
            k --;
    }
    k++;

    int x = 0;
    outros[0] = nome[0];
    strcpy(&outros[1], ".");
    x++;
    
    for(int i=0; i < (k-1); i++){
        if ((nome[i] == ' ')){
            if(i != k){
                x ++;
                outros[x] = nome[i];
                outros[x+1] = nome[i+1];
                strcpy(&outros[x+2], ".");
                x = x+2;
            }
        }
    }
    outros[x+1] = '\0';
    
    for(int i=0; i < tamanho; i++){
        if (i == (tamanho-1)){
            int j = 0;
            while (k < (tamanho-1)){
                    ultimo[j] = nome[k];
                    j++;
                    k++;
            }
            ultimo[k-1] = '\0';                    
        }
    }

    printf("\nUltimo:%s", ultimo);
    printf("\nOutros: %s\n", outros);

    int x, y;
    for(x=0; x<(strlen(ultimo)-1); x++){
        saida[x] = ultimo[x];
    }
    
    strcpy(&saida[x], "/");
    x++;
    
    for(y=0; y<(strlen(outros)); y++, x++){
        saida[x] = outros[y];
    }
    saida[x] = '\0';
    strupr(saida);
    
    printf("\n%s", saida);

    free(nome);
    free(ultimo);
    free(outros);
    return 0;
}