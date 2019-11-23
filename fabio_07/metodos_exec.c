#include "metodos_ordenacao.h"

#define tam 5


int main(void)
{
    // Shaker Sort    
    int array_shaker[tam] = {5, 4, 2, 3, 1};
    printf("\nAntes do Shaker Sort: \n");
    mostrar_array(tam, array_shaker);
    shaker_sort(tam, array_shaker);
    printf("\nDepois do Shaker Sort: \n");
    mostrar_array(tam, array_shaker);

    // Selection Sort
    int array_selection[tam] = {3, 4, 1, 5, 2};
    printf("\nAntes do Selection Sort: \n");
    mostrar_array(tam, array_selection);
    selection_sort(tam, array_selection);
    printf("\nDepois do Selection Sort: \n");
    mostrar_array(tam, array_selection);

    // Inserction Sort
    int array_inserction[tam] = {3, 4, 1, 5, 2};
    printf("\nAntes do Inserction Sort: \n");
    mostrar_array(tam, array_inserction);
    inserction_sort(tam, array_inserction);
    printf("\nDepois do Inserction Sort: \n");
    mostrar_array(tam, array_inserction);

    // Bubble Sort
    int array_bubble[tam] = {3, 4, 1, 5, 2};
    printf("\nAntes do Bubble Sort: \n");
    mostrar_array(tam, array_bubble);
    bubble_sort(tam, array_bubble);
    printf("\nDepois do Bubble Sort: \n");
    mostrar_array(tam, array_bubble);
}
