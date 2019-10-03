
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#define size 10

typedef struct
{
    int top;
    char element[size];
} stack;

stack Stack;

//BOOT STACK
void boot(stack *Stack){
    Stack->top = -1;
}

//EMPTY STACK
bool stack_empty(stack *Stack){
    if (Stack->top == -1)
    {
        return true;
    }
    return false;
}

// SHOW STACK
void show_stack(stack *Stack){
    char value;
    int top = Stack->top;

    if (stack_empty(Stack)){
        printf("\n\nPILHA VAZIA!!!\n");
    }
    else{
        printf("\nVALORES NA PILHA\n");
        for (int i = top; i >= 0; i--)
        {
            value = Stack->element[i];
            printf("\nValor - %c", value);
        }
    }
}

// PUSH ON TOP
void push_stack(stack *Stack, char value){
    Stack->top = Stack->top + 1;
    Stack->element[Stack->top] = value;
}

// POP
char pop_stack(stack *Stack){
    char value;
    value = Stack->element[Stack->top];
    Stack->top = Stack->top - 1;
    return value;
}

// CHECK VALUE TOP
char check_value(stack *Stack){
    return Stack->element[Stack->top];    
}

// CONDITIONALS
void check_operator(stack *Stack)
{
    char op, resultado;
    int num1, num2, operacao;

    if (check_value(Stack) == '+')
    { // ADICAO
        op = pop_stack(Stack);
        num1 = pop_stack(Stack) - '0';
        num2 = pop_stack(Stack) - '0';
        resultado = (char)(num1 + num2) + '0';
        push_stack(Stack, resultado);
    }
    else if (check_value(Stack) == '-')
    { // SUBTRACAO
        op = pop_stack(Stack);
        num1 = pop_stack(Stack) - '0';
        num2 = pop_stack(Stack) - '0';
        operacao = num1 - num2;
        if (operacao < 0){
            resultado = '-' + (char)(operacao) + '0';
            printf("\nResultado: %c", resultado);
        }
        else{
            resultado = (char)(operacao) + '0';
            printf("\nResultado: %c", resultado);
        }
                
        push_stack(Stack, resultado);
    }
    else if (check_value(Stack) == '*')
    { // MULTIPLICACAO
        op = pop_stack(Stack);
        num1 = pop_stack(Stack) - '0';
        num2 = pop_stack(Stack) - '0';
        resultado = (char)(num1 * num2) + '0';
        push_stack(Stack, resultado);
    }
    else if (check_value(Stack) == '/')
    {
        op = pop_stack(Stack);
        num1 = pop_stack(Stack) - '0';
        num2 = pop_stack(Stack) - '0';
        resultado = (char)(num1 / num2) + '0';
        push_stack(Stack, resultado);
    }
    printf("\nPrecione qualquer tecla para continuar...");
}
