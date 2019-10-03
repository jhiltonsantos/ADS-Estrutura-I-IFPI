#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

void menu()
{
    int option;
    boot(&Stack);
    int c;

    do
    {
        //system("clear");
        system("cls");
        printf("\nCALCULADORA POS-FIXADA\n");
        show_stack(&Stack);

        printf("\n\n0 - INSTRUCOES\n");
        printf("1 - ENTRADA DE VALORES\n");
        printf("9 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
        { // INSTRUCTIONS
            printf("\n\nADICIONE DOIS VALORES E EM SEGUIDA ADICIONE O OPERADOR (-, +, *, /)\n");
            printf("\nEXEMPLO:\n 1 2 - 4 5 + *");
            c = getchar();
            break;
        }

        case 1:
        {
            char value;

            printf("\nDIGITE UM VALOR OU OPERADOR: ");
            scanf("%s%*c", &value);

            push_stack(&Stack, value);
            check_operator(&Stack);

            break;
        }

        case 9:
        {
            break;
        }

        default:
        {
            printf("\n\nOPCAO INVALIDA!!!");
            c = getchar();
            break;
        }
        }
        c = getchar();
    } while (option != 9);
}

int main(void)
{
    menu();
}
