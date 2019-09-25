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
    while (aux > 0){
        empilhar(p, aux);
        aux--;
    }
}


void mostrarTorre(pilha *p){
    for(int i = p->topo; i>=0; i--){
        printf(" %d", p->elemento[i]);
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


bool torreVazia(pilha *p){
    if (p->topo == -1){
        return true;
    }
    return false;
}


void esvaziarTorre(pilha *p){
    int e;
    if (torreVazia(p) == false){
        printf("\n\nTorre Vazia!!!\n");
    }
    else{
        while (torreVazia(p) == false){
            e = desempilhar(p);
        }
        printf("\n\nTorre esvaziada\n");
    }
}


int tamanho(pilha *p){
    return (p->topo + 1);
}


int valorTopo(pilha *p){
    return p->elemento[p->topo];
}

int leia_origem_destino(int variavel)
{
    int valor;
    if (variavel == 1)
    {
        printf("\nTorre de origem: ");
    }
    else
    {
        printf("\nTorre de destino: ");
    }
    scanf("%d", &valor);
    while (valor < 1 && valor > 3)
    {
        printf("\nTorre invalida!!!\n");
        printf("\nDigite novamente: ");
        scanf("%d", &valor);
    }

    return valor;
}

int novoMovimento(pilha *p1, pilha *p2){
    int aux;
    if (tamanho(p1)>0 && (tamanho(p2)<=0)||(valorTopo(p1)<valorTopo(p2))){
            aux = desempilhar(p1);
            empilhar(p2, aux);
            return 1;
    }
    else{
        printf("Movimento nao permitido!!! --novoMovimento()");
        return 0;
    }
    
}


int movimentar(pilha *p1, pilha *p2, pilha *p3){
    int retorno;
    int origem, destino;
    mostrarPinos(p1, p2, p3);
    origem = leia_origem_destino(1);
    destino = leia_origem_destino(2);

    switch (origem){
        case 1:
            switch (destino){
                case 1:
                    printf("\nMOVIMENTO INVALIDO!!!");
                    return 3;
                    break;

                case 2:
                    retorno = novoMovimento(p1, p2);
                    if (retorno==0){
                        return 3;
                    }
                
                case 3:
                    retorno = novoMovimento(p1, p3);
                    if (retorno == 0){
                        return 3;
                    }
            }
        break;

        case 2:
            switch (destino)
            {
            case 1:
                retorno = novoMovimento(p2, p1);
                if (retorno == 0){
                    return 3;
                }
                
            case 2:
                printf("\nMOVIMENTO INVALIDO!!!");
                return 3;
                break;

            case 3:
                retorno = novoMovimento(p2, p3);
                if (retorno == 0)
                {
                    return 3;
                }
            }

        case 3:
            switch (destino)
            {
            case 1:
                retorno = novoMovimento(p3, p1);
                if (retorno == 0)
                {
                    return 3;
                }

            case 2:
                retorno = novoMovimento(p3, p2);
                if (retorno == 0){
                    return 3;
                }
                
            case 3:
                printf("\nMOVIMENTO INVALIDO!!!");
                return 3;
                break;
            }

        default:
            printf("\nMOVIMENTO NAO PERMITIDO");
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

    //system("cls");
    printf("TORRE DE HANOI\n\n");
    do{
        switch (opcao)
        {
        case 1:
            //system("cls");
            printf("\33[H\33[2J");
            comeco();
            opcao = 2;
            break;

        case 2:
            mostrarPinos(&torreX, &torreY, &torreZ);

        case 3:
            printf("\33[H\33[2J");
            opcao = movimentar(&torreX, &torreY, &torreZ);
            break;

        case 4:
            if (tamanho(&torreY) == 0){
                esvaziarTorre(&torreX);
                esvaziarTorre(&torreY);
                esvaziarTorre(&torreZ);
                int c = getchar();
                printf("\n\nPrecione qualquer tecla para continuar...");
                opcao = 9;
            }
            else{
                mostrarPinos(&torreX, &torreY, &torreZ);
                int c = getchar();
                printf("\n\nPrecione qualquer tecla para continuar...");
                opcao = 2;
            }
            break;
        }
    } while (opcao != 9);
    printf("\nFIM DE JOGO");

}

int main(){
    menu();
    mostrarPinos(&torreX, &torreY, &torreZ);
}