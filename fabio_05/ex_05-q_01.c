#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <ncurses.h>
#include <stdbool.h>

#define size 10

typedef struct {
    int top;
    char element[size];
}Stack;

Stack stack;

//BOOT STACK
void boot(Stack *stack){
    stack -> top = -1;
}

//EMPTY STACK
bool stack_empty(Stack *stack){
    if (stack -> top == -1){
        return true;
    }
    return false;
}



void menu(){
    int option;
    boot (&stack);

    do{
        system("clear");
        printf("\nCALCULADORA PÓS-FIXADA\n\n");
        printf("0 - INSTRUCOES\n");
        printf("1 - ENTRADA DE VALOR\n");
        printf("2 - MOSTRAR ULTIMO RESULTADO\n");
        printf("9 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &option);

        switch (option){
            case 0: // INSTRUCTIONS
                printf("\n\nADICIONE DOIS VALORES E EM SEGUIDA ADICIONE O OPERADOR (-, +, *, /)\n");
                printf("\nEXEMPLO:\n 1 2 - 4 5 + *");
                int c = getchar();
                break;
            
            case 1:
                break;

            case 2:
                break;
            
            case 9:
                break;

            default:
                printf("\n\nOPCAO INVALIDA!!!");
                c = getchar();
                break;
        }
        printf("\n\n");
        int c = getchar();
    } while (option != 9);
    
    
}




int main(void){
    menu();
}