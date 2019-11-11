#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
//#include <ncurses.h>

// Structs
#define tipo_info int

typedef struct elem{
    //int element;
    tipo_info info;
    struct elem *lig; //next
}tipo_elem; //tipo_elem

typedef struct {
    //int size;
    tipo_elem *start;
    tipo_elem *end;
} Row;

Row row;


void initialize (Row *r) {
    r -> start = NULL;
    r -> end = NULL;
    //r -> size = 0;
}


bool row_empty (Row *r) {
    return (r->start == NULL);
}


int show_start (Row *r) {
    tipo_elem *ptr;

    if (row_empty(r)) {
        printf("\n\nFILA VAZIA\n");
        return 999;
    }
    else {
        ptr = r -> start;
        return ptr;
    }
}


void new_element (Row *r, tipo_info info) {
    tipo_elem *ptr;

    ptr = malloc (sizeof(tipo_elem));
    if (ptr == NULL){
        printf("\n\nNÃO FOI POSSÍVEL ALOCAR MEMÓRIA!\n");
    }
    else{
        ptr->info = info;
        ptr->lig = NULL;

        if (row_empty(r)){
            r->start = ptr;
        }
        else{
            r->end->lig = ptr;
        }

        r->end = ptr;
    }
}


int remove_element (Row *r, tipo_info *e) {
    tipo_elem *ptr;

    if (row_empty(r)) {
        printf("\n\nFILA VAZIA\n");
        return 999;
    }
    else{
        ptr = r->start;
        e = ptr-> info;
        r->start = ptr->lig;

        if (r->start == NULL) {
            r->end = NULL;
        }

        free (ptr);
        return e;
    }
}


int size_row (Row *r) {
    tipo_elem *ptr;
    int count = 0;

    ptr = r->start;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->lig;
    }

    return count;
}

void show_row (Row *r) {
    tipo_elem *ptr;

    if (row_empty(r)) {
        printf ("\n\nFILA VAZIA\n");
    }
    else{
        printf ("\n\nFILA: ");
        ptr = r->start;
        
        while (ptr != NULL){
            printf ("%d ", ptr->info);
            ptr = ptr->lig;
        }
    }
}


void removeALL_row (Row *r) {
    tipo_elem *nextDel, *nextNo;

    if (!row_empty(r)) {
        nextNo = r->start;
        while (nextNo != NULL){
            nextDel = nextNo;
            nextNo = nextNo->lig;
            free (nextDel);
        }
    }
    initialize (r);
}


void menu () {
    int option, e;
    int press;

    initialize(&row);
    // COLOCAR O TEMPO POR VOLTAS DENTRO DO WHILE
    int volta = 1;


    do
    {
        system ("clear");
        printf ("FILA DE IMPRESSÃO DE DOCUMENTOS\n\n");
        printf ("1 - SOLICITAR IMPRESSÃO\n");
        printf ("2 - MOSTRAR FILA DE IMPRESSÃO\n");
        printf ("0 - SAIR\n");
        printf ("OPCAO: ");
        scanf ("%d", &option);
        press = getchar();

        switch (option)
        {
            case 1:
            {   
                int id, voltas;
                system ("clear");
                printf ("SOLICITAR IMPRESSÃO\n\n");
                
                printf ("ID DO ARQUIVO: \n");
                scanf ("%d", &id);
                printf ("NUMERO DE VOLTAS: \n");
                scanf ("%d", &voltas);

                new_element (&row, id);
                volta = volta + voltas;
                break;
            }
            
            case 2:
            {
                show_row (&row);
            }
            
            default:
            {
                if (option != 0) {
                    printf ("OPCAO INVÁLIDA!!!\n\n");
                }
                break;
            }
        }

        volta--;
        int inicio, saiu;
        if (volta <= 0) {
            inicio = show_start(&row);
            if (!inicio == 999) {
                saiu = remove_element(&row);
                printf("O ELEMENTO %d SAIU DA FILA!!!\n");
            }
        }
        press = getchar();

    } while (option != 0);
    
}


int main (void) {
    menu ();
}
