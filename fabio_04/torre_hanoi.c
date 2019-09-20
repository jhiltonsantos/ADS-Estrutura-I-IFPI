#include <conio.h>
//#include <ncurses.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 7

typedef struct{
    int topo;
    char elemento[tam];
} pilha;

pilha torreX;
pilha torreY;
pilha torreZ;


void inicializacao(pilha *p){
    p->topo = -1;
}


void empilhar(pilha *p, int valor){
    p-> topo = p-> topo + 1;
    p->elemento[p->topo] = valor;
}


int desempilhar(pilha *p){
    int valor;

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
    printf("\nX\n");
    mostrarTorre(p2);
    printf("\nY\n");
    mostrarTorre(p3);
    printf("\nZ\n");
}


int tamanho(pilha *p){
    return (p->topo + 1);
}


int valorTopo(pilha *p){
    return p->elemento[p->topo];
}


int novoMovimento(pilha *p1, pilha *p2){
    int aux;
    if (valorTopo(p1)>-1)
    {
        aux = desempilhar(p1);
        empilhar(p2, aux);
    }
    else{
        printf("Movimento nao permitido!!! --novoMovimento()");
    }
    
}


int movimentar(pilha *p1, pilha *p2, pilha *p3){
    
    // INFORMACOES
    int exibir[3];
    exibir[0] = tamanho(&torreX);
    printf("\nTamanho torre X: %d", exibir[0]);

    exibir[1] = tamanho(&torreY);
    printf("\nTamanho torre Y: %d", exibir[1]);

    exibir[2] = tamanho(&torreZ);
    printf("\nTamanho torre Z: %d\n\n", exibir[2]);

    int valor_topo[3];
    valor_topo[0] = valorTopo(p1);
    printf("\nValor Topo X: %d", valor_topo[0]);

    valor_topo[1] = valorTopo(p2);
    printf("\nValor Topo Y: %d", valor_topo[1]);

    valor_topo[2] = valorTopo(p3);
    printf("\nValor Topo Z: %d\n", valor_topo[2]);




    int movimento;
    printf("\n\n        -----------------------------\n");
    printf("        | X -> Y -- 1 | X -> Z -- 2 |\n");
    printf("        -----------------------------\n");
    printf("        | Y -> X -- 3 | Y -> Z -- 4 |\n");
    printf("        -----------------------------\n");
    printf("        | Z -> X -- 5 | Z -> Y -- 6 |\n");
    printf("        -----------------------------\n");
    printf("        \nDigite o proximo movimento: ");
    scanf("%d", &movimento);

    switch (movimento){
        case 1: // X -> Y
            if (novoMovimento(p1, p2) == 0){
                return 3;
            }
            break;
    
        case 2: // X -> Z
            if (novoMovimento(p1, p3) == 0){
                return 3;
            }
            break;

        case 3: // Y -> X
            if (novoMovimento(p2, p1) == 0){
                return 3;
            }
            break;
        
        case 4: // Y -> Z
            if (novoMovimento(p2, p3) == 0){
                return 3;
            }
            break;
        
        case 5: // Z -> X
            if (novoMovimento(p3, p1) == 0){
                return 3;
            }
            break;

        case 6: // Z -> Y
            if (novoMovimento(p3, p2) == 0){
                return 3;
            }
            break;
        
        default:
            printf("Movimento nao permitido --movimentar()");
            return 3;
            break;
    }

    return 4;
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
    inicializacao(&torreX);
    inicializacao(&torreY);
    inicializacao(&torreZ);

    inicio_torre(&torreX, num_discos);
    
    mostrarPinos(&torreX, &torreY, &torreZ);

}


void menu(){
    int opcao = 1;

    system("cls");
    printf("TORRE DE HANOI\n\n");
    printf("1 - Iniciar Jogo\n");

    do
    {
        switch (opcao)
        {
        case 1:
            system("cls");
            comeco();
            opcao = 2;
            break;

        case 2:
            system("cls");
            mostrarPinos(&torreX, &torreY, &torreZ);

        case 3:
            opcao = movimentar(&torreX, &torreY, &torreZ);
            break;

        case 4:
            /*if (tamanho(&torreY) == 0)
            {
                opcao == 5;
            }
            else
            {
                opcao == 2;
            }*/

        case 5:
            //esvaziarTorres(&torreX);
            //esvaziarTorres(&torreY);
            //esvaziarTorres(&torreZ);
            opcao = 9;

        default:
            printf("\n\nOpcao Invalida --menu");
        }
    } while (opcao != 9);
}

int main(){
    menu();
    mostrarPinos(&torreX, &torreY, &torreZ);
}