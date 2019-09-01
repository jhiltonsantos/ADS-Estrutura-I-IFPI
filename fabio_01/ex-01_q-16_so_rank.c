#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ficha_sistema
{
    int Cod_Sys;
} System;


typedef struct quantidade_nome
{
    int Quantidade;
    char Nome[30];
} Quant;


int main(void){
    System sistema[50];
    Quant dados[5];

    int codigo=0, i=0, total=0;
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

    for(int j=0; j<5;j++){
        dados[j].Quantidade = 0;
    }
    
    for (int j=0; j<50; j++)
    {
        if (sistema[j].Cod_Sys == 1){
            strcpy(dados[0].Nome, "Windows Server");
            dados[0].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 2){
            strcpy(dados[1].Nome, "Linux");
            dados[1].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 3){
            strcpy(dados[2].Nome, "Unix");
            dados[2].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 4){
            strcpy(dados[3].Nome, "NetWare");
            dados[3].Quantidade++;
            total++;
        }
        else if (sistema[j].Cod_Sys == 5){
            strcpy(dados[4].Nome, "MacOS");
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

    printf("\n\nSistema Operacional     Votos     %%\n");
    printf("____________________________\n");
    printf("Windows Server            %d     %.0f%%\n", dados[0].Quantidade, porcentagem[0]);
    printf("Linux                     %d     %.0f%%\n", dados[1].Quantidade, porcentagem[1]);
    printf("Unix                      %d     %.0f%%\n", dados[2].Quantidade, porcentagem[2]);
    printf("Netware                   %d     %.0f%%\n", dados[3].Quantidade, porcentagem[3]);
    printf("MacOS                     %d     %.0f%%\n", dados[4].Quantidade, porcentagem[4]);
    printf("____________________________\n");
    printf("Total         %d\n\n", total);

    
    int mais_votado = 0;
    char mais_nome[30];
    float maior_porcentagem;

    for(int k=0; k<5;k++)
    {
        if(mais_votado < dados[k].Quantidade)
        {
            mais_votado = dados[k].Quantidade;
            strcpy(mais_nome, dados[k].Nome);
            maior_porcentagem = porcentagem[k];
        }
    }

    printf("O Sistema Operacional mais votado foi o %s, com %d votos, sendo %.2f %% dos votos.\n\n", mais_nome, mais_votado, maior_porcentagem);
    return 0;
}