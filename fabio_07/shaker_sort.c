#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void shaker_sort(int tam, int array[tam])
{
    int inferior = 0;
    int topo = tam - 1;
    bool continua = true;
    int aux;

    do
    { //Se não houver troca de posições ou o ponteiro que sobe ultrapassar o que desce, o vetor esta ordenado
        continua = false;
        //Este for é a “ida” para a direita
        for (int i = inferior; i < topo; i++)
        {
            if (array[i] > array[i+1]) 
            {   //indo pra direita: testa se o próximo é topo indo pra direita:se o proximo é topo que o atual,
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                continua = true;
            }
        }
        // diminui o  `topo` porque o elemento com o topo valor
        // já está na direita (atual posição topo)
        topo --;
        //Este for é a “ida” para a esquerda
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
        //aumenta o `inferior` porque o inferior valor já está
        //na posição inicial (inferior)
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
