#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include <conio.h>
#include <stdbool.h>

// AGENCIA BANCARIA ---> FILA ESTATICA
// CLIENTE EMITE SENHA - INICIA TEMPO
// CLIENTE SAI DA FILA - FINALIZA TEMPO
// CRIAR GUICHE
// VERIFICAR DISPONIBILIDADE DO GUICHE

/*
    OPERACOES:
                - ENTRAR NUMERO DE GUICHES
                - ENTRADA DE CLIENTE
                - ATENDER CLIENTE
                - SAIDA DE CLIENTE - CASO ATENDIDO
                - FIM DA FILA

*/

#define tam 5

typedef struct
{
    int elemento[tam];
    int inicio, fim;
} fila;

fila Cliente;
fila Guiche;

void iniciar_fila(fila *C)
{
    C->inicio = -1;
    C->fim = -1;
}

bool fila_cheia(fila *C)
{
    if (C->fim == tam - 1)
    {
        return true;
    }
    return false;
}

bool fila_vazia(fila *C)
{
    if ((C->fim == -1) && (C->inicio == -1))
    {
        return true;
    }
    return false;
}

//funcao tamanho
int tamanho(fila *C)
{
    int tamanho;
    if (fila_vazia(C))
    {
        printf("\nFILA VAZIA!!!\n");
        return 0;
    }
    else
    {
        tamanho = ((C->fim) - (C->inicio)) + 1;
        printf("\nQUANTIDADE: %i.\n", tamanho);
        return tamanho;
    }
}

int consultar_primeiro(fila *C)
{
    if (fila_vazia(C))
    {
        printf("\nFILA SEM CLIENTES!!!\n");
        return 0;
    }
    else
    {
        int cliente = C->elemento[C->inicio];
        printf("\nCLIENTE: %i\n", cliente);
        return cliente;
    }
}

void mostrar_fila(fila *C)
{
    if (fila_vazia(C))
    {
        printf("\nFILA SEM CLIENTES\n");
    }
    else
    {
        printf("\nFILA DE CLIENTES: ");
        for (int i = C->inicio; i <= C->fim; i++)
        {
            printf("%i ", C->elemento[i]);
        }
    }
}

void entrar_fila(fila *C, int valor)
{
    if (fila_vazia(C))
    {
        C->inicio = C->inicio + 1;
    }
    C->fim = C->fim + 1;
    C->elemento[C->fim] = valor;
}

int sair_fila(fila *C)
{
    int valor;
    valor = C->elemento[C->inicio];
    if (C->inicio == C->fim)
    {
        // FILA VAZIA
        C->inicio = -1;
        C->fim = -1;
    }
    else
    {
        C->inicio = C->inicio + 1;
    }

    return valor;
}

void esvaziar_fila(fila *C)
{
    int valor;
    if (fila_vazia(C))
    {
        printf("\nFILA SEM CLIENTES\n");
    }
    else
    {
        printf("\nESVAZIANDO FILA\n");
        while (fila_vazia(C) == false)
        {
            valor = sair_fila(C);
            printf("\nCLIENTE RETIRADO: %i", valor);
        }
        printf("\nFILA ESVAZIADA\n");
    }
}

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
                    printf("\nFILA DE CLIENTES ESTA LOTADA!!!\n");
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
                    int primeiro, saiu;
                    primeiro = consultar_primeiro(&Cliente);
                    saiu = sair_fila(&Cliente);
                    entrar_fila(&Guiche, primeiro);
                    printf("\nCLIENTE %d SAIU DA FILA E ESTA SENDO ATENDIDO!!!\n", saiu);
                }
                c = getchar();
                break;
            }

            case '3':
            {   // CLIENTE ATENDIDO
                if (tamanho(&Guiche) == 0){
                    printf("Continuando...");
                    c = getchar();
                    break;
                }
                else{
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
            { // MOSTRAR ELEMENTOS NA FILA GUICHE
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
                printf("\n\nOPCAO INVALIDA!!!");
                c = getchar();
                break;
            }
        }
    } while (opcao != '9');
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
