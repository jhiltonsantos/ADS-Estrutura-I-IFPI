//#include <conio.h>
#include <ncurses.h>
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


char desempilhar(pilha *p){
    char valor;

    valor = p->elemento[p->topo];
    p->topo = p->topo - 1;

    return valor;
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
    Z\n");
    mostrarTorre(p2);
    mostrarTorre(p3);
}


int tamanho(pilha *p){
    return p->topo;
}


int topoPilha(pilha *p){
    if (p -> topo == 0){
        return -1;
    }
    return p->elemento[p->topo-1];
}


int novoMovimento(pilha *p1, pilha *p2){
    if ((tamanho(p1)) > 0 && (tamanho(p2) <= 0 || topoPilha(p1) < topoPilha(p2))){
        empilhar(p2, desempilhar(p1));
        return 1;
    }
    else{
        printf("Movimento nao permitido");
        return 0;
    }
}


char movimentar(pilha *p1, pilha *p2, pilha *p3){
    char mover[3] = {0,0,'\0'};
    printf("Digite o proximo movimento: ");
    scanf("%c%c", mover, mover-1);

    switch (mover[0]){
        case 'A':
            switch (mover[1]){
                case 'B':
                    if(novoMovimento(p1, p2) == 0){
                        return 4;
                    }
                    break;
            
                case 'C':
                    if(novoMovimento(p1, p3) == 0){
                        return 4;
                    }
                    break;
                default:
                    printf("Movimento nao permitido");
                    return 4;
            }
            break;

        case  'B':
            switch (mover[1])
            {
            case 'A':
                if (novoMovimento(p2, p1) == 0){
                    return 4;
                }
                break;

            case 'C':
                if (novoMovimento(p2, p3) == 0){
                    return 4;
                }
                break;
            default:
                printf("Movimento nao permitido");
                return 4;
            }
            break;

        case 'C':
            switch (mover[1])
            {
            case 'A':
                if (novoMovimento(p3, p1) == 0){
                    return 4;
                }
                break;

            case 'B':
                if (novoMovimento(p3, p2) == 0){
                    return 4;
                }
                break;
            default:
                printf("Movimento nao permitido");
                return 4;
            }
            break;
        
        default:
            printf("Movimento nao permitido");
            return 4;
            break;
    }   
    
    return 5;
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
    char opcao, e;
    comeco();


    do{
        system("cls");
        printf("TORRE DE HANOI\n\n");
        printf("1 - Mostrar Torres");

    }

// PAREI AQUI
}

// MAIN
int main(){
    menu();
}