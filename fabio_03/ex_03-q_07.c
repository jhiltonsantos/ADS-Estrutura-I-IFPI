#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <ncurses.h>

#define tam 50

int main(){
    char *nome, *primeiro, *ultimo, *formatado;
    nome = malloc(tam * sizeof(char));
    primeiro = malloc(tam * sizeof(char));
    ultimo = malloc(tam * sizeof(char));
    formatado = malloc(tam * sizeof(char));

    printf("\nDigite seu nome completo: ");
    fgets(nome, tam, stdin);   
    
    int quantidade_palavras = 1;
    int tamanho = (strlen(nome));
    int k = tamanho;

    while (nome[k] != ' '){
            k --;
    }
    k++;

    for(int i=0; i < tamanho; i++){

        if ((nome[i] == ' ') && (quantidade_palavras==1)){
            for (int j = 0; j < i; j++){
                primeiro[j] = nome[j];
            }
            primeiro[i] = '\0';        
        }

        if (i == (tamanho-1)){
            int j = 0;
            while (k < (tamanho-1)){
                    ultimo[j] = nome[k];
                    j++;
                    k++;
            }
            ultimo[k-1] = '\0';                    
        }

        if (nome[i] == ' '){
            quantidade_palavras++;
        }
    }

    int x, y;
    for(x=0; x<(strlen(ultimo)-1); x++){
        formatado[x] = ultimo[x];
    }
    
    strcpy(&formatado[x], "/");
    x++;
    
    for(y=0; y<(strlen(primeiro)); y++, x++){
        formatado[x] = primeiro[y];
    }
    formatado[x] = '\0';
    strupr(formatado);
    printf("%s", formatado);


    free(nome);    
    free(primeiro);    
    free(ultimo);    
    free(formatado);  

    return 0;
    system("PAUSE");
}
