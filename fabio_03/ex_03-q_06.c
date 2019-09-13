#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define tam 50

int main(void){
    char *nome;
    nome = malloc(tam * sizeof(char));
    
    printf("\nDigite o texto: ");
    fgets(nome, tam, stdin);
    
    int quantidade_palavras = 1;
    for(int i=0; i<(strlen(nome)-1); i++){
        if (nome[i] == ' '){
            quantidade_palavras++;
        }
    }
    printf("Numero de palavras digitadas: %d palavras.\n", quantidade_palavras);
    free(nome);    
}