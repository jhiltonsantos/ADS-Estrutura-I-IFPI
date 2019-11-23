#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 5

typedef struct
{
    int elemento[tam];
    int inicio, fim;
} fila;

fila Cliente;
fila Guiche;

void iniciar_fila (fila *C);
void finalizar_fila(fila *C);
bool fila_cheia (fila *C);
bool fila_vazia (fila *C);
int tamanho (fila *C);
int consultar_primeiro (fila *C);
void mostrar_fila (fila *C);
void entrar_fila (fila *C, int valor);
int sair_fila_cliente(fila *C);
int sair_fila(fila *C);
void esvaziar_fila(fila *C);


void iniciar_fila(fila *C)
{
    C->inicio = -1;
    C->fim = -1;
}

void finalizar_fila(fila *C)
{
    C->inicio = tam;
    C->fim = tam;
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
        return 999;
    }
    else
    {
        int cliente = C->elemento[C->inicio];
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

int sair_fila_cliente(fila *C)
{
    int valor;
    valor = C->elemento[C->inicio];
    if (C->inicio == C->fim)
    {
        finalizar_fila(C);
    }
    else
    {
        C->inicio = C->inicio + 1;
    }

    return valor;
}

int sair_fila(fila *C)
{
    int valor;
    valor = C->elemento[C->inicio];
    if (C->inicio == C->fim)
    {
        iniciar_fila(C);
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
