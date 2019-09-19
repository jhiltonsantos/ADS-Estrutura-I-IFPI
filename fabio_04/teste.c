#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 7

typedef struct
{
    int topo;
    char elemento[tam];
} pilha;

pilha torreA;
pilha torreB;
pilha torreC;

void inicializacao(pilha *p)
{
    p->topo = -1;
}

void empilhar(pilha *p, int e)
{
    p->topo = p->topo + 1;
    p->elemento[p->topo] = e;
}

void inicio_torre(pilha *p, int quantidade)
{
    int aux;
    aux = quantidade;
    while (aux > 0)
    {
        empilhar(p, aux);
        aux--;
    }
}

void ImprimirTorre(pilha *p)
{
    printf("\n");
    for (int i = 0; i < (p->topo); i++)
    {
        printf("%d ", p->elemento[i]);
    }
    printf("\n");
}

void mostrarTorres(pilha *p1, pilha *p2, pilha *p3)
{
    printf("\nX: ");
    ImprimirTorre(p1);

    printf("\nY: ");
    ImprimirTorre(p2);

    printf("\nZ: ");
    ImprimirTorre(p3);
}

void mostrarElementos(pilha *p)
{
    printf("\n\nTORRE\n");
    for (int i = p->topo; i >= 0; i--)
    {
        printf("\n %d", p->elemento[i]);
    }
}

void menu()
{
    // Quantidade de discos
    int n_discos = 0, opcao;
    printf("Digite o numero de discos: \n");
    scanf("%d", &n_discos);

    // Iniciando torres
    inicializacao(&torreA);
    inicializacao(&torreB);
    inicializacao(&torreC);

    inicio_torre(&torreA, n_discos);
    mostrarTorres(&torreA, &torreB, &torreC);

    /*do{
        
    }while(opcao != 0);*/
}

int main()
{
    menu();
}