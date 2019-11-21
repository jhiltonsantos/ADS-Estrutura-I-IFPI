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
        
        continua = false;

        for (int i = inferior; i < topo; i++)
        {
            if (array[i] > array[i + 1])
            {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                continua = true;
                
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
            }
        }
        
        inferior++;
        volta++;
        
    } while (continua == true && inferior < topo);

    printf("\nDepois do Shaker Sort: \n");
    mostrar_array(tam, array);
}


void selection_sort(int tam, int array[tam])
{   // Fixa uma posicao do vetor e compara com todas as outras,
    // até encontrar a posição de menor valor e troca a posição
    // atual com a menor

    int menor, aux;

    printf("\nAntes do Selection Sort: \n");
    mostrar_array(tam, array);

    for (int i=0; i<tam-1; i++)
    {   
        menor = i;
        for (int j=i+1; j<tam; j++)
        {
            if (array[menor] > array[j]) 
            {
                menor = j;
            }
        }
        if (i != menor) 
        {
            aux = array[i];
            array[i] = array[menor];
            array[menor] = aux;
        }
    }
    
    printf("\nDepois do Selection Sort: \n");
    mostrar_array(tam, array);
}

void inserction_sort(int tam, int array[tam])
{
    int troca, j;

    printf("\nAntes do Inserction Sort: \n");
    mostrar_array(tam, array);

    for (int i = 0; i < tam; i++)
    {
        troca = array[i];
        j = i-1;

        while (j>=0 && array[j] >troca)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = troca;
    }

    printf("\nDepois do Inserction Sort: \n");
    mostrar_array(tam, array);
}


int main(void)
{
    srand(time(NULL));

    int tam = 5;
    
    int array[5] = {5, 4, 2, 3, 1};
    shaker_sort(tam, array);

    int array_2[5] = {3, 4, 1, 5, 2};
    selection_sort(tam, array_2);

    int array_3[5] = {3, 4, 1, 5, 2};
    inserction_sort(tam, array_3);
}