#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila_estatica.h"

#define tam 5

void menu()
{
    char opcao;
    int e, c;

    iniciar_fila(&Cliente);
    iniciar_fila(&Guiche);

    system("clear");
    int n_guiches;
    printf("AGENCIA BANCARIA\n\n");
    printf("ENTRAR COM NUMERO DE GUICHES: ");
    scanf("%d", &n_guiches);
    c = getchar();
    system("clear");

    do
    {   
        
        system("clear");
        printf("AGENCIA BANCARIA\n\n");
        printf("1 - ENTRAR CLIENTE\n");
        printf("2 - ATENDER CLIENTE\n");
        printf("3 - ATENDENDIMENTO CONCLUIDO\n");
        printf("4 - MOSTRAR FILA CLIENTES\n");
        printf("5 - MOSTRAR FILA GUICHES\n");
        printf("6 - LIMPAR FILA CLIENTES\n");
        printf("7 - LIMPAR FILA GUICHES\n");
        printf("9 - SAIR\n");
        printf("OPCAO: ");
        scanf("%c", &opcao);
        c = getchar();

        switch (opcao)
        {
            case '1':
            { // ENTRADE DE CLIENTES NA FILA
                int cliente;
                if (fila_cheia(&Cliente))
                {
                    printf("\nFILA DE CLIENTES FINALIZADA!!!\n");
                }
                else
                {
                    printf("\nDIGITE O NOVO CLIENTE: ");
                    scanf("%d", &cliente);
                    entrar_fila(&Cliente, cliente);
                }
                
                c = getchar();
                break;
            }

            case '2':
            { // ATENDER CLIENTES NO GUICHE
                if (tamanho(&Guiche) == n_guiches)
                {
                    printf("\nGUICHES ESTAO LOTADOS!!!\n\n");
                }
                else
                {
                    if (fila_vazia(&Cliente)){
                        printf("FILA DE CLIENTES VAZIA!!!");
                    }
                    else{
                        int primeiro, saiu, ultimo = 0;
                        if (tamanho(&Cliente) == 1){
                            ultimo ++;
                        }
                        primeiro = consultar_primeiro(&Cliente);
                        if (primeiro != 999){ // FORÇAR FILA CLIENTES FINALIZAR
                            saiu = sair_fila_cliente(&Cliente);
                            if (ultimo == 1)
                            {
                                esvaziar_fila(&Cliente);
                            }
                            entrar_fila(&Guiche, primeiro);
                            printf("\nCLIENTE %d SAIU DA FILA E ESTA SENDO ATENDIDO!!!\n", saiu);
                        }
                    }
                }
                c = getchar();
                break;
            }

            case '3':
            {   // CLIENTE ATENDIDO
                if (tamanho(&Guiche) == 0)
                {
                    printf("Continuando...");
                    c = getchar();
                    break;
                }
                else
                {
                    int saiu;
                    saiu = sair_fila(&Guiche);
                    printf("\nCLIENTE %d FOI ATENDIDO!!!\n", saiu);
                }
            }

            case '4':
            { // MOSTRAR ELEMENTOS NA FILA CLIENTE
                mostrar_fila(&Cliente);
                c = getchar();
                break;
            }

            case '5':
            {   // MOSTRAR ELEMENTOS NA FILA GUICHE
                mostrar_fila(&Guiche);
                c = getchar();
                break;
            }

            case '6':
            {
                esvaziar_fila(&Cliente);
                c =getchar();
                break;
            }

            case '7':
            {
                esvaziar_fila(&Guiche);
                c = getchar();
                break;
            }

            default:
            {   
                if(opcao != '9'){
                    printf("\n\nOPCAO INVALIDA!!!");
                    c = getchar();
                }
                break;
            }
        }
    } while (opcao != '9');
}


int main(void){
    menu();
}
