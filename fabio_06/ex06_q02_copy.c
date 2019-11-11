#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
//#include <ncurses.h>

// Structs
#define tipo_info int

typedef struct elem
{
    int element;
    //tipo_info info;
    struct elem *next;
} no;

typedef struct
{
    int size;
    no *start;
    no *end;
} Row;

Row row;

void initialize(Row *r)
{
    r->start = NULL;
    r->end = NULL;
    r->size = 0;
}

bool row_empty(Row *r)
{
    if (r->size == 0)
    {
        return true;
    }
    return false;
}

void size(Row *r)
{
    if (row_empty(r))
    {
        printf("\n\nFILA VAZIA\n");
    }
    else
    {
        printf("\n\nTAMANHO: %d\n", r->size);
    }
}

int show_start(Row *r)
{
    no *ptr;

    if (row_empty(r))
    {
        printf("\n\nFILA VAZIA\n");
        return 999;
    }
    else
    {
        ptr = r->start;
        printf("\n\nFIM: %d", ptr->element);
        return ptr;
    }
}

void new_element(Row *r, int e)
{
    no *ptr;

    ptr = (no *)malloc(sizeof(no));
    if (ptr == NULL)
    {
        printf("\n\nNÃO FOI POSSÍVEL ALOCAR MEMÓRIA!\n");
    }
    else
    {
        ptr->element = e;
        ptr->next = NULL;

        if (row_empty(r))
        {
            r->start = ptr;
            r->end = ptr;
        }
        else
        {
            r->end->next = ptr;
            r->end = ptr;
        }
        r->size = r->size + 1;
    }
}

int remove_element(Row *r)
{
    no *ptr;
    int e;

    if (r->start == r->end)
    {
        r->end = NULL;
    }

    ptr = r->start;
    e = ptr->element;
    r->start = r->start->next;
    r->size = r->size - 1;
    free(ptr);

    return e;
}

void show_row(Row *r)
{
    no *ptr;

    if (row_empty(r))
    {
        printf("\n\nFILA VAZIA\n");
    }
    else
    {
        printf("\n\nFILA: ");
        ptr = r->start;

        while (ptr != NULL)
        {
            printf("%d ", ptr->element);
            ptr = ptr->next;
        }
    }
}

void removeALL_row(Row *r)
{
    int e;

    if (row_empty(r))
    {
        printf("\n\nFILA VAZIA!!!\n");
    }
    else
    {
        printf("\n\nESVAZIANDO FILA\n\n");
        while (!row_empty(r))
        {
            e = remove_element(r);
            printf("SAINDO ELEMENTO: %d\n", e);
        }
        printf("\n\nFILA ESVAZIADA\n");
    }
}

void menu()
{
    int option, e;
    int press;

    initialize(&row);
    // COLOCAR O TEMPO POR VOLTAS DENTRO DO WHILE
    int volta = 1;

    do
    {
        system("clear");
        printf("FILA DE IMPRESSÃO DE DOCUMENTOS\n\n");
        printf("1 - SOLICITAR IMPRESSÃO\n");
        printf("2 - MOSTRAR FILA DE IMPRESSÃO\n");
        printf("0 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &option);
        press = getchar();

        switch (option)
        {
        case 1:
        {
            int id, voltas;
            system("clear");
            printf("SOLICITAR IMPRESSÃO\n\n");

            printf("ID DO ARQUIVO: \n");
            scanf("%d", &id);
            printf("NUMERO DE VOLTAS: \n");
            scanf("%d", &voltas);

            new_element(&row, id);
            volta = volta + voltas;
            break;
        }

        case 2:
        {
            show_row(&row);
        }

        default:
        {
            if (option != 0)
            {
                printf("OPCAO INVÁLIDA!!!\n\n");
            }
            break;
        }
        }

        volta--;
        int inicio, saiu;
        if (volta <= 0)
        {
            inicio = show_start(&row);
            if (!inicio == 999)
            {
                saiu = remove_element(&row);
                printf("O ELEMENTO %d SAIU DA FILA!!!\n");
            }
        }
        press = getchar();

    } while (option != 0);
}

int main(void)
{
    menu();
}
