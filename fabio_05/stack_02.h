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

    for (int i = 0; i < str_size; i++)
    {
        Stack->element[Stack->top][i] = value[i];
        if (value[i] == '\0')
        {
            break;
        }
    }
}

// POP
void pop_stack(stack *Stack){
    char value[str_size];
    Stack->element[Stack->top];
    Stack->top = Stack->top - 1;
}

/*char check_value(stack *Stack){
    int j = strlen(Stack->element[Stack->top]);
    char valor[j];
    
    for (int i = 0; i < str_size; i++)
    {
        valor[i] = Stack->element[Stack->top][i];
        if (Stack->element[Stack->top][i] == '\0')
        {
            break;
        }
    }

    return valor;
}*/