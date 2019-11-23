#include "metodos_ordenacao.h"

#define tamanho 5

int main(void)
{
    srand(time(NULL));

    int array[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        array[i] = rand() % 5;
    }

    printf("\nAntes do Shaker Sort: \n");
    mostrar_array(tamanho, array);

    shaker_sort(tamanho, array);

    printf("\nDepois do Shaker Sort: \n");
    mostrar_array(tamanho, array);
}
