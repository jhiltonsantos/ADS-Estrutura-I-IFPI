#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void cocktail_sort(int list[10])
{
    int tamanho, inferior, topo, trocar, i, aux;
    tamanho = 10;
    inferior = 0;
    topo = tamanho - 1;
    trocar = 0;
    while (trocar == 0 && inferior < topo) //Se não houver troca de posições ou o ponteiro que
    {                                    //sobe ultrapassar o que desce, o vetor esta ordenado
        trocar = 1;
        //Este for é a “ida” para a direita
        for (i = inferior; i < topo; i = i + 1)
        {
            if (list[i] > list[i + 1]) //indo pra direita:testa se o próximo é topo
            {                          //indo pra direita:se o proximo é topo que o atual,
                //troca as posições
                aux = list[i];
                list[i] = list[i + 1];
                list[i + 1] = aux;
                trocar = 0;
            }
        } //fecha for
        // diminui o  `topo` porque o elemento com o topo valor
        // já está na direita (atual posição topo)
        topo = topo - 1;
        //Este for é a “ida” para a esquerda
        for (i = topo; i > inferior; i = i - 1)
        {
            if (list[i] < list[i - 1])
            {
                aux = list[i];
                list[i] = list[i - 1];
                list[i - 1] = aux;
                trocar = 0;
            }
        }
        //aumenta o `inferior` porque o inferior valor já está
        //na posição inicial (inferior)
        inferior = inferior + 1;
    } //fecha while
} // fim da funçao


void mostrar_array(int tam, int list[tam]){
    for (int i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(void){
    int array[10] = {1,3,4,5,6,2,8,7,9,0};
    
    printf("\nAntes do Shaker Sort: \n");
    mostrar_array(10, array);

    cocktail_sort(array);
    printf("\nDepois do Shaker Sort: \n");
    mostrar_array(10, array);
    
}