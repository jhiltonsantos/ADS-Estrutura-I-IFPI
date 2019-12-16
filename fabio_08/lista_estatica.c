#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#define tamanho 5

typedef struct
{
    int elementos[tamanho];
    int primeiro, ultimo;
} ListaEstatistica;

void inicializar(ListaEstatistica *l)
{
    l->primeiro = 0;
    l->ultimo = 0;
}

bool listaVazia(ListaEstatistica *l)
{
    return l->ultimo == l->primeiro;
}

bool listaCheia(ListaEstatistica *l)
{
    return l->ultimo == (tamanho - 1);
}

int tamanho_lista(ListaEstatistica *l)
{
    return l->ultimo;
}

void mostrar_lista(ListaEstatistica *l)
{
    if (!listaVazia(l))
    {
        printf(" Lista:");
        for (int i = 0; i < l->ultimo; i++)
        {
            printf(" %d |", l->elementos[i]);
        }
    }
    else
    {
        printf(" Ops, lista vazia");
    }
    printf("\n");
}

int busca_sequencial(ListaEstatistica *l, int e)
{
    int pos = -1;
    for (int i = 0; i < l->ultimo; i++)
    {
        if (l->elementos[i] == e)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

int primeiro_elemento(ListaEstatistica *l)
{
    return l->elementos[l->primeiro];
}

int ultimo_elemento(ListaEstatistica *l)
{
    return l->elementos[l->ultimo - 1];
}

bool posicao_valida(ListaEstatistica *l, int pos)
{
    return (pos >= l->primeiro) && (pos <= l->ultimo);
}

bool inserir_elemento(ListaEstatistica *l, int e, int pos)
{
    if (!listaCheia(l) && posicao_valida(l, pos))
    {
        for (int i = l->ultimo; i > pos; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }
        l->elementos[pos] = e;
        l->ultimo++;

        return true;
    }

    return false;
}

bool remover_elemento(ListaEstatistica *l, int e)
{
    int pos_elemento = busca_sequencial(l, e);
    if (pos_elemento != -1)
    {
        for (int i = pos_elemento; i < l->ultimo; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }
        l->ultimo--;

        return true;
    }

    return false;
}

void remover_lista(ListaEstatistica *l)
{
    inicializar(l);
}

void menu(ListaEstatistica *l)
{
    mostrar_lista(l);
    printf(" 1 -> INSERIR\n");
    printf(" 2 -> REMOVER \n");
    printf(" 3 -> CONSULTAR\n");
    printf(" 4 -> PRIMEIRO VALOR\n");
    printf(" 5 -> ULTIMO VALOR\n");
    printf(" 6 -> TAMANHO\n");
    printf(" 9 -> SAIR\n");
    printf(" Opção: ");
}


void limpar_tela()
{
    char c;

    printf("\n Aperter qualquer tecla para continuar...");
    scanf("%c", &c);
    setbuf(stdin, NULL);
    system("cls");
}


int main()
{
    ListaEstatistica lista;
    int op;
    int elemento, posicao;
    int tam;

    inicializar(&lista);

    do
    {
        menu(&lista);
        scanf("%d", &op);
        setbuf(stdin, NULL);

        switch (op)
        {
        case 1:
            printf("\n Elemento: ");
            scanf("%d", &elemento);
            setbuf(stdin, NULL);

            printf(" Posição: ");
            scanf("%d", &posicao);
            setbuf(stdin, NULL);

            if (!inserir_elemento(lista, elemento, posicao))
            {
                printf(" Não foi possível realizar a inserção\n");
            }
            else
            {
                printf(" Inserção realizada\n");
            }
            break;

        case 2:
            
            printf("\n Elemento: ");
            scanf("%d", &elemento);
            setbuf(stdin, NULL);

            if (!remover_elemento(lista, elemento))
            {
                printf("\n Não foi possível remover o elemento");
            }
            else
            {
                printf("\n Elemento removido");
            }
            break;

        case 3:
        
            printf("\n Elemento: ");
            scanf("%d", &elemento);
            setbuf(stdin, NULL);

            posicao = busca_sequencial(lista, elemento);

            if (posicao == -1)
            {
                printf("\n Elemento não encontrado");
            }
            else
            {
                printf("\n Elemento na posição %d", posicao);
            }
            break;

        case 4:
            
            elemento = primeiro_elemento(lista);
            printf("\n Primeiro elemento -> %d", elemento);
            break;

        case 5:
        
            elemento = ultimo_elemento(lista);
            printf(" Ultimo elemento -> %d", elemento);
            break;

        case 6:
        
            tam = tamanho_lista(lista);
            printf("\n Tamanho da lista -> %d", tam);
            break;

        default:
            break;
        }

        limpar_tela();

    } while (op != 7);

    return 0;
}