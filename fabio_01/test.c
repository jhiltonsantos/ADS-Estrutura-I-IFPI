#include <stdio.h>
#include <stdlib.h>

int main(void){
    int idade, soma=0, count=0;
    float media=0.0;
    scanf("%d", &idade);
    
    while (idade != 0)
    {
        soma += idade;
        count ++;
        scanf("%d", &idade);
    }
    
    media = (float)soma / (float)count;

    printf("%.2f", media);
    
    

    return 0;



    /*
    #include <stdio.h>
#include <stdlib.h>

typedef struct ficha_sistema
{
    int Cod_Sys;
    char Nome[20];
} System;

typedef struct quantidade_nome
{
    int Quantidade;
    char Nome[20];
} Quant;



int main(void){
    System sistema[50];
    
    int codigo=0, i=0;
    do
    {
        printf("Qual o melhor Sistema Operacional para uso em servidores?\n");
        printf("[1- Windows Server || 2- Linux  || 3- Unix || 4- Netware || 5- MacOS]: ");
        scanf("%d", &codigo);
        if (codigo != 0){
            sistema[i].Cod_Sys = codigo;
        }
        i ++;
    }while (codigo != 0);


    Quant dados[5];

    int total=0;
    dados[0].Quantidade = 0;
    dados[1].Quantidade = 0;
    dados[2].Quantidade = 0;
    dados[3].Quantidade = 0;
    dados[4].Quantidade = 0;

    for (int j=0; j<5; j++)
    {
        if (sistema[j].Cod_Sys == 1){
            dados[0].Nome == "Windows Server";
            dados[0].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 2){
            //sistema[j].Nome == "Linux";
            dados[1].Nome == "Linux";
            dados[1].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 3){
            dados[2].Nome == "Unix";
            dados[2].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 4){
            dados[3].Nome == "Netware";
            dados[3].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 5){
            dados[4].Nome == "MacOS";
            dados[4].Quantidade++;
            total++;
        }
        else{
            sistema[j].Cod_Sys = 0;
        }
    }

    float porcentagem[5];
    for (int j=0; j < 5; j++)
    {
        porcentagem[j] = (dados[j].Quantidade * 100) / total;
    }

    printf("\n\nSistema Operacional     Votos   %%\n");
    printf("____________________________\n");
    printf("Windows Server  %d  %.0f%%\n", quantidade[0], porcentagem[0]);
    printf("Linux  %d  %.0f%%\n", quantidade[1], porcentagem[1]);
    printf("Unix  %d  %.0f%%\n", quantidade[2], porcentagem[2]);
    printf("Netware  %d  %.0f%%\n", quantidade[3], porcentagem[3]);
    printf("MacOS  %d  %.0f%%\n", quantidade[4], porcentagem[4]);
    printf("____________________________\n");
    printf("\nTotal         %d\n\n", total);

    int mais_votado = quantidade[0];
    char mais_nome[20];
    for(int j=0; j<5;j++){}
    {
        if(mais_votado<quantidade[j])
        {
            mais_votado = quantidade[j];
         
        }
    }

    printf("O Sistema Operacional mais votado foi");
    return 0;

}
    */
}