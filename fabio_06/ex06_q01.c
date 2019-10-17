#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
//#include <conio.h>
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

void iniciar_fila(fila *C){
    C -> inicio = -1;
    C -> fim = -1;
}


bool fila_completa(fila *C){
    if(C -> fim == tam-1){
        return true;
    }
    return false;
}

bool fila_vazia(fila *C){
    if ((C->fim == -1) && (C->inicio == -1))
    {
        return true;
    }
    return false;
}

//funcao tamanho
void quantidade_clientes(fila *C){
    int tamanho;
    if (fila_vazia(C)){
        printf("\nFILA SEM CLIENTES (quantidade_clientes)\n");
    }
    else{
        tamanho = ((C->fim) - (C->inicio)) + 1;
        printf("\nQUANTIDADE DE CLIENTES: %i (quantidade_clientes)\n", tamanho);
    }
}

int consultar_primeiro(fila *C){
    if (fila_vazia(C)){
        printf("\nFILA SEM CLIENTES (consultar_primeiro)\n");
        return 0;
    }
    else{
        int cliente = C->elemento[C->inicio];
        printf("\nCLIENTE: %i (consultar_primeiro)\n", cliente);
        return cliente;
    }
}

void mostrar_fila(fila *C){
    if (fila_vazia(C)){
        printf("\nFILA SEM CLIENTES (mostrar_fila)\n");
    }
    else{
        printf("\nFILA DE CLIENTES: ");
        for (int i = C->inicio; i <= C->fim; i++){
            printf("%i ", C -> elemento[i]);
        }
    }
}

void entrar_fila(fila *C, int valor){
    if(fila_vazia(C)){
        C->inicio = C->inicio +1;
    }
    C->fim = C->fim +1;
    C->elemento[C->fim] = valor;
}

int sair_fila(fila *C){
    int valor;
    valor = C->elemento[C->inicio];
    if (C->inicio == C->fim){
        // FILA VAZIA
        C->inicio = -1;
        C->fim = -1;
    }
    else{
        C->inicio = C->inicio + 1;
    }

    return valor;
}

void esvaziar_fila(fila *C){
    int valor;
    if (fila_vazia(C)){
        printf("\nFILA SEM CLIENTES (esvaziar_fila)\n");
    }
    else{
        printf("\nESVAZIANDO FILA\n");
        while (fila_vazia(C) == false)
        {
            valor = sair_fila(C);
            printf("\nCLIENTE RETIRADO: %i", valor);
        }
        printf("\nFILA ESVAZIADA\n");
        }
}


void menu(){
    char opcao;
    int e, c;

    iniciar_fila(&Cliente);
    iniciar_fila(&Guiche);

    do{
        system("clear");
        //int c = getchar();
        printf("AGENCIA BANCARIA\n\n");
        printf("1 - ENTRAR NUMERO DE GUICHES\n");
        printf("2 - ENTRAR CLIENTE\n");
        printf("3 - ATENDER CLIENTE\n");
        printf("4 - ATENDENDIMENTO CONCLUIDO\n");
        printf("5 - MOSTRAR FILA CLIENTES\n");
        printf("6 - MOSTRAR FILA GUICHES\n");
        printf("7 - TAMANHO FILA CLIENTES\n");
        printf("9 - SAIR\n");
        printf("OPCAO: ");
        scanf("%c", &opcao);
        c = getchar();

        switch (opcao)
        {
            case '1':
            {
                // ENTRADA DE GUICHES
                int n_guiches;
                printf("DIGITE O NUMERO DE GUICHES: \n");
                scanf("%d", &n_guiches);

                for (int i = 0; i < n_guiches; i++){
                    entrar_fila(&Guiche, (i+1));
                }
                c = getchar();
                break;
            
            }
            
            default:
            {
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
