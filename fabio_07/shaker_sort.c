#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void cocktail_sort(int array[10]){
    int tamanho = 10;
    int inferior = 0;
    int topo = tamanho - 1;
    int trocar = 0;
    int aux;

    while (trocar==0 && inferior<topo){ //Se não houver troca de posições ou o ponteiro que
                                        //sobe ultrapassar o que desce, o vetor esta ordenado
        trocar = 1;
        //Este for é a “ida” para a direita
        for (int i = inferior; i < topo; i++){
            if (array[i] > array[i+1]){ //indo pra direita:testa se o próximo é topo
                                      //indo pra direita:se o proximo é topo que o atual,
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                trocar = 0;
            }
        }
        // diminui o  `topo` porque o elemento com o topo valor
        // já está na direita (atual posição topo)
        topo --;
        //Este for é a “ida” para a esquerda
        for (int i = topo; i > inferior; i--){
            if (array[i] < array[i-1]){
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
                trocar = 0;
            }
        }
        //aumenta o `inferior` porque o inferior valor já está
        //na posição inicial (inferior)
        inferior ++;
    }
}


void mostrar_array(int tam, int array[tam]){
    for (int i = 0; i < 10; i++){
        printf("%d ", array[i]);
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