#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <ncurses.h>
#include <stdbool.h>

#include "stack.h"


void menu(){
    int option;
    boot (&Stack);
    int c;

    do{
        //system("clear");
        system("cls");
        printf("\nCALCULADORA POS-FIXADA\n\n");
        printf("0 - INSTRUCOES\n");
        printf("1 - ENTRADA DE VALORES\n");
        printf("2 - MOSTRAR ULTIMO RESULTADO\n");
        printf("9 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &option);

        int num1, num2, operacao;
        
        switch (option){
            case 0:
            { // INSTRUCTIONS
                printf("\n\nADICIONE DOIS VALORES E EM SEGUIDA ADICIONE O OPERADOR (-, +, *, /)\n");
                printf("\nEXEMPLO:\n 1 2 - 4 5 + *");
                c = getchar();
                break;
            }
            case 1:
            {
                char value, compare, cNum, op;   

                printf("\nDIGITE UM VALOR OU OPERADOR: ");
                scanf("%s%*c", &value);

                push_stack(&Stack, value);
                
                //Verificar se é numero ou operador
                compare = check_value(&Stack);
                if (compare== '+'){
                    op = pop_stack(&Stack);
                    cNum = pop_stack(&Stack);
                    num1 = (int) (cNum>47 && c<58)? c-48 : -1;
                    printf("Numero 1: ", num1);
                    cNum = pop_stack(&Stack);
                    num2 = (int)(cNum > 47 && c < 58) ? c - 48 : -1;

                    operacao = num1 + num2;
                    push_stack(&Stack, operacao);
                }

                c = getchar();
                break;
            }
            case 2:
            {
                show_stack(&Stack);
                
                c = getchar();
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
        printf("\n\n");
        c = getchar();
    } while (option != 9);
    
    
}




int main(void){
    menu();
}