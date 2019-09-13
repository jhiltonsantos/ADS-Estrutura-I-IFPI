#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
//#include <conio.h>


int main(void){
    int ch;
    char senha[30];
    int i = 0;
    
    printf("\n\nVERIFICA SENHA\n\n");

    
    while (true){
        ch = getch();
        if (ch == 13){
            break;
        }
        if (ch == 8){
            printf("Digite a senha: ");
            fflush(stdin);
            for(int a=0; a<i; a++){
                printf("*");
            
            }
            continue;
        }
    }
    
    printf("*");
    senha[i] = ch;
    i ++;


    

}