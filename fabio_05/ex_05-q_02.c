#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#include "stack_02.h"
#define tam 50


void verifica_texto(){
    boot(&Stack);

    char *texto, *tag;
    int x=0;
    
    texto = malloc(tam * sizeof(char));
    tag = malloc(tam * sizeof(char));

    printf("\n\nDigite o texto: \n");
    fgets(texto, tam, stdin);

    int tamanho_texto = strlen(texto);
   
    for (int i=0, j=0; i < tamanho_texto; i++, j++){
        if (texto[i] == '<'){
            do{
                tag[x] = texto[j];
                x++;
                j++;
            } while (texto[j-1] != '>');
            j = i;
            x = 0;

            push_stack(&Stack, tag);
            show_stack(&Stack);
            
        }
        
    }

    printf("\n\nTexto Completo: %s", texto);

    free(texto);
    free(tag);
}

int main(){
    verifica_texto();

    
    return 0;
}
