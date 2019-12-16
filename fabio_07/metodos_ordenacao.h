#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void mostrar_array(int tam, int array[]);
void bubble_sort(int tam, int array[]);
void shaker_sort(int tam, int array[]);
void selection_sort(int tam, int array[]);
void inserction_sort(int tam, int array[]);


void mostrar_array(int tam, int array[])
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


void bubble_sort (int tam, int array[]) 
{
    int aux;
    bool troca=true;

    while (troca)
    {   
        troca = false;
        for (int i = 0; i < tam-1; i++)
        {
            if (array[i] > array [i+1])
            {   
                troca = true;
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
        }
    }     
}


void shaker_sort(int tam, int array[])
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

    } while (continua == true && inferior < topo);
}


void selection_sort(int tam, int array[])
{   // Fixa uma posicao do vetor e compara com todas as outras,
    // até encontrar a posição de menor valor e troca a posição
    // atual com a menor
    int menor, aux;

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
}


void inserction_sort(int tam, int array[])
{
    int troca, j;

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
}
