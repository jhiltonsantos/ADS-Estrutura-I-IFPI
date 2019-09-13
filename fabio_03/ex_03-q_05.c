#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    char palavra[46], palindroma[46];
    
    printf("Digite a palavra: ");
    //fgets(palavra, sizeof(palavra), stdin);
    gets(palavra);
    
    for (int i=(strlen(palavra)-1), j=0; i>=0; i--, j++){
        palindroma[j] = palavra[i];        
    }
    palindroma[strlen(palavra)] = '\0';
    
    printf("\nPalavra: %s", palavra);
    printf("\nInvertida: %s", palindroma);

    if((strcmp(palindroma, palavra)) == 0){
        printf("\n\nA PALAVRA EH PALINDROMA\n");
    }
    else{
        printf("\n\nA PALAVRA NAO EH PALINDROMA\n");
    }
}
