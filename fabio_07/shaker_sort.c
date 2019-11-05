#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void shaker_sort(int tam, int array[tam])
{
    int inferior = 0;
    int topo = tam - 1;
    bool continua = true;
    int aux;

    do
    { 
        continua = false;
        
        for (int i = inferior; i < topo; i++)
        {
            if (array[i] > array[i+1]) 
            {   
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                continua = true;
            }
        }
        topo --;
        
        for (int i = topo; i > inferior; i--)
        {
            if (array[i] < array[i-1])
            {
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
                continua = true;
            }
        }
        inferior ++;

    } while (continua == true && inferior < topo);
}


void mostrar_array(int tam, int array[tam]) 
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(void) 
{
    srand(time(NULL)); // semente

    int tam = 10;
    int array[tam];
    
    for (int i=0; i < tam; i++ )
    {
        array[i] = rand() % 100;
    }
    
    printf("\nAntes do Shaker Sort: \n");
    mostrar_array(tam, array);

    shaker_sort(tam, array);
    printf("\nDepois do Shaker Sort: \n");
    mostrar_array(tam, array);
    
}
