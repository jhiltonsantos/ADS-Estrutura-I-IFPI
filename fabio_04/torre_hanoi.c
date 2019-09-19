#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 7

typedef struct{
    int topo;
    char elemento[tam];
} pilha;

pilha torreA;
pilha torreB;
pilha torreC;


void inicializacao(pilha *p){
    p->topo = -1;
}


void empilhar(pilha *p, int e){
    p-> topo = p-> topo + 1;
    p->elemento[p->topo] = e;
}


void inicio_torre(pilha *p, int quantidade){
    int aux;
    aux = quantidade;
    while (aux > 0)
    {
        empilhar(p, aux);
        aux--;
    }
}


void mostrarTorre(pilha *p){
    for(int i = p->topo; i>=0; i--){
        printf("\n%d", p->elemento[i]);
    }
}


void mostrarPinos(pilha *p1, pilha *p2, pilha *p3){
    mostrarTorre(p1);
    printf("\nX\
    Y\
    Z");
    mostrarTorre(p2);
    mostrarTorre(p3);
}


int movimentar(){
    
}


int numeroDiscos(){
    int n_discos;
    printf("\nDigite o numero de discos: ");
    scanf("%d", &n_discos);
    while ((n_discos < 3) || (n_discos > 7))
    {
        printf("Valor Invalido!!!\
        (Quantidade minima 3 | Quantidade maxima: 7)\n");
        printf("\nDigite o numero de discos: ");
        scanf("%d", &n_discos);
    }

    return n_discos;
}


void comeco(){
    int num_discos = numeroDiscos();    

    // Iniciando torres
    inicializacao(&torreA);
    inicializacao(&torreB);
    inicializacao(&torreC);

    inicio_torre(&torreA, num_discos);
    
    mostrarPinos(&torreA, &torreB, &torreC);

}


void menu(){

}

// MAIN
int main(){
    comeco();
    menu();
}