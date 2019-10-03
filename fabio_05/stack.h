
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <ncurses.h>
#include <stdbool.h>

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
    int value;
    int top = Stack->top;

    if (stack_empty(Stack)){
        printf("\n\nPILHA VAZIA!!!\n");
    }
    else{
        printf("\nVALORES NA PILHA\n");
        for (int i = top; i >= 0; i--)
        {
            value = Stack->element[i];
            printf("\nValor - %d", value);
        }
    }
}

// PUSH ON TOP
void push_stack(stack *Stack, int value){
    Stack->top = Stack->top + 1;
    Stack->element[Stack->top] = value;
}

// POP
char pop_stack(stack *Stack){
    int value;
    value = Stack->element[Stack->top];
    Stack->top = Stack->top-1;

    return value;
}

// CHECK VALUE
char check_value(stack *Stack){
    return Stack->element[Stack->top];    
}

