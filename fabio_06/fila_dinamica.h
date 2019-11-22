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
bool inserir_fila (fila *F, tipo_info *info);
bool remover_fila (fila *F, tipo_info *info);
int tamanho_fila (fila *F);



