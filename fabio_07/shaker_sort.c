#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void mostrar_array(int tam, int array[tam])
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void shaker_sort(int tam, int array[tam])
{
    int inferior = 0;
    int topo = tam - 1;
    bool continua = true;
    int aux;
    int volta = 1;

    printf("\nAntes do Shaker Sort: \n");
    mostrar_array(tam, array);

    do
    {
        printf("\nVolta %d: \n", volta);
        continua = false;

        for (int i = inferior; i < topo; i++)
        {
            if (array[i] > array[i + 1])
            {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                continua = true;
                mostrar_array(tam, array);
            }
        }
        
        topo--;
        
        for (int i = topo; i > inferior; i--)
        {
            if (array[i] < array[i - 1])
            {
                aux = array[i];
                array[i] = array[i - 1];
                array[i - 1] = aux;
                continua = true;
                mostrar_array(tam, array);
            }
        }
        
        inferior++;
        volta++;
        
    } while (continua == true && inferior < topo);

    printf("\nDepois do Shaker Sort: \n");
    mostrar_array(tam, array);
}


int main(void)
{
    srand(time(NULL));

    int tam = 5;
    int array[tam];
    //int array[5] = {5,4,2,3,1};

    for (int i = 0; i < tam; i++)
    {
        array[i] = rand() % 5;
    }

    shaker_sort(tam, array);
    //shaker_sort(5, array);
}