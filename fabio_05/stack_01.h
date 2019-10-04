#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#define size 10
#define str_size 50

typedef struct
{
    int top;
    char element[size][str_size];
} stack;

stack Stack;

//BOOT STACK
void boot(stack *Stack)
{
    Stack->top = -1;
}

//EMPTY STACK
bool stack_empty(stack *Stack)
{
    if (Stack->top == -1)
    {
        return true;
    }
    return false;
}

// SHOW STACK
void show_stack(stack *Stack)
{
    int top = Stack->top;

    if (stack_empty(Stack))
    {
        printf("\n\nPILHA VAZIA!!!\n");
    }
    else
    {
        printf("\nVALORES NA PILHA\n");
        for (int i = top; i >= 0; i--)
        {
            printf("\nValor - %s", Stack->element[i]);
        }
    }
}

// PUSH ON TOP
void push_stack(stack *Stack, char value[str_size])
{
    Stack->top = Stack->top + 1;
    
    for(int i=0; i<str_size;i++){
        Stack->element[Stack->top][i] = value[i];
        if (value[i] == '\0'){
            break;
        }
    }
    
}

void pop_stack(stack *Stack){
    char value[str_size];
    Stack->element[Stack->top];
    Stack->top = Stack->top - 1;

}

// CHECK VALUE TOP
char check_value(stack *Stack)
{
    char valor[str_size];
    for (int i = 0; i < str_size; i++){
        valor[i] = Stack->element[Stack->top][i];
        if (valor[i] == '\0'){
            break;
        }
    }
    
    return valor;
}

// CONDITIONALS
void check_operator(stack *Stack)
{
    char op, resultado;
    int num1, num2, operacao;

    if (check_value(Stack) == '+')
    { // ADICAO
        //num1 = pop_stack(Stack) - '0';
        pop_stack(Stack);
        num1 = check_value(Stack);
        pop_stack(Stack);
        num2 = check_value(Stack);
        pop_stack(Stack);
        resultado = (char)(num1 + num2) + '0';
        push_stack(Stack, *resultado);
    }
    else if (check_value(Stack) == '-')
    { // SUBTRACAO
        pop_stack(Stack);
        num1 = check_value(Stack);
        pop_stack(Stack);
        num2 = check_value(Stack);
        pop_stack(Stack);
        operacao = num1 - num2;
        if (operacao < 0)
        {
            resultado = (char)(operacao) + '0';
            //strcat('-',r)
            printf("\nResultado: %c", *resultado);
        }
        else
        {
            resultado = (char)(operacao) + '0';
            printf("\nResultado: %c", *resultado);
        }

        push_stack(Stack, *resultado);
    }
    else if (check_value(Stack) == '*')
    { // MULTIPLICACAO
        pop_stack(Stack);
        num1 = check_value(Stack);
        pop_stack(Stack);
        num2 = check_value(Stack);
        pop_stack(Stack);
        resultado = (char)(num1 * num2) + '0';
        push_stack(Stack, *resultado);
    }
    else if (check_value(Stack) == '/')
    {
        pop_stack(Stack);
        num1 = check_value(Stack);
        pop_stack(Stack);
        num2 = check_value(Stack);
        pop_stack(Stack);
        resultado = (char)(num1 / num2) + '0';
        push_stack(Stack, *resultado);
    }
    printf("\nPrecione qualquer tecla para continuar...");
}