#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <ncurses.h>

#define tam 50

int main(void){
    char *nome, *primeiro, *ultimo;
    nome = malloc(tam * sizeof(char));
    primeiro = malloc(tam * sizeof(char));
    ultimo = malloc(tam * sizeof(char));

    printf("\nDigite seu nome completo: ");
    fgets(nome, tam, stdin);   
    
    int quantidade_palavras = 1;

    for(int i=0; i<(strlen(nome)); i++){
        if ((nome[i] == ' ') && (quantidade_palavras==1)){
            for (int j = 0; j < i; j++){
                primeiro[j] = nome[j];
            }        
        }

        if (i == strlen(nome)-1){
            for (int j = 0, k=(strlen(nome)-1); j < i; j++, k--){
                while (nome[k] != ' '){
                    ultimo[j] = nome[k+];
                    k --;
                    j ++;
                }
                break;
            }
                    
        }

        if (nome[i] == ' '){
            quantidade_palavras++;
        }
    }

    //parou no inverso


    printf("\n\nO primeiro nome eh: %s. \n", primeiro);
    printf("O ultimo nome eh: %s. \n", ultimo);

    free(nome);    
    free(primeiro);    
    free(ultimo);    
}
