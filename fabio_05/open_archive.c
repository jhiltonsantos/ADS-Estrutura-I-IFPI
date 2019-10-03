#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    FILE *arquivo;
    char frase[80], nomeDoArquivo[20];

    system("cls");
    printf("Nome do arquivo: ");
    fflush(stdin);
    gets(nomeDoArquivo);

    arquivo = fopen(nomeDoArquivo, "r");

    if (arquivo == NULL){
        printf("Erro na abertura do Arquivo : %s. Tecle algo !\n", nomeDoArquivo);
        getch();
    }
    
    else{
        printf("\n\n");
        fgets(frase, 80, arquivo);
        while (!feof(arquivo)){
            printf("%s", frase);
            fgets(frase, 80, arquivo);
        }
        fclose(arquivo);
        printf("\n\n *** fim de texto *** Tecle algo !");
        getch();
    }
}