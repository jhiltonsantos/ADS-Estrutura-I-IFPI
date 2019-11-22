#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tipo_info int

typedef struct elem{
    tipo_info info;
    struct elem *lig;
}tipo_elem;

typedef struct{
    tipo_elem *inicio, *fim;
}fila;

fila Fila;

void inicializar (fila *F);
bool fila_vazia (fila *F);
void esvaziar_fila (fila *F);
bool inserir_fila (fila *F, tipo_info e);
bool remover_fila (fila *F, tipo_info e);
int tamanho_fila (fila *F);


void inicializar (fila *F)
{
    F-> inicio = NULL;
    F-> fim = NULL;
}

bool fila_vazia (fila *F)
{
    return (F->inicio == NULL);
}

void esvaziar_fila (fila *F)
{
    tipo_elem *aux, *proxNo;

    if (!fila_vazia(F))
    {
        proxNo = F->inicio;
        while (proxNo != NULL)
        {
            aux = proxNo;
            proxNo = proxNo->lig;
            free(aux);
        }
    }
    inicializar(F);
}

bool inserir_fila(fila *F, tipo_info e)
{
    tipo_elem *valor;
    valor = (tipo_elem *) malloc (sizeof(tipo_elem));
    if (valor = NULL)
    {
        return false;
    }

    valor->info = e;
    valor->lig = NULL;

    if (fila_vazia(F)){
        F->inicio = valor;
    }
    else{
        F->fim->lig = valor;
    }

    F->fim = valor;
    return true;
}

bool remover_fila(fila *F, tipo_info e)
{
    tipo_elem *valor;

    if (fila_vazia(F))
    {
        return false;
    }

    valor = F->inicio;
    e = valor->info;
    F->inicio = valor->lig;

    if (F->inicio == NULL)
    {
        F->fim = NULL;
    }

    free(valor);
    return true;
}

int tamanho_fila(fila *F) 
{
    tipo_elem *valor;
    int i=0;

    valor = F->inicio;
    while (valor != NULL)
    {
        i++;
        valor = valor->lig;
    }

    return i;    
}

void mostrar_fila(fila *F)
{
    tipo_elem *valor;

    if (fila_vazia(F))
    {
        printf("FILA VAZIA!!!");
    }
    else
    {
        printf("\n\nFIla: ");
        valor = F->inicio;
        while (valor != NULL)
        {
            printf("%d ", valor->lig);
            valor = valor->lig;
        }        
    }
}