#include <stdio.h>
#include <stdlib.h>

int main(void){
    int idade, soma=0, count=0;
    float media=0.0;
    scanf("%d", &idade);
    
    while (idade != 0)
    {
        soma += idade;
        count ++;
        scanf("%d", &idade);
    }
    
    media = (float)soma / (float)count;

    printf("%.2f", media);
    
    

    return 0;
}