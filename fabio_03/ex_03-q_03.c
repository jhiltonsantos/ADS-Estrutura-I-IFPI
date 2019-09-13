#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 3


int main(void){
    char horario[30];
    char hora[tam], minuto[tam], segundo[tam];

    printf("Digite a a hora: ");
    fgets(horario, sizeof(horario), stdin);
    int tamanho = strlen(horario);

    for (int i=0, pos = 0; i < tamanho; i++, pos++){
        if (horario[pos] == ':'){
            if (pos==2){
                hora[0] = horario[pos-2];
                hora[1] = horario[pos-1];
                hora[2] = '\0';
            }
            else if(pos==5){
                minuto[0] = horario[pos-2];
                minuto[1] = horario[pos-1];
                minuto[2] = '\0';            
            }
        }
        else if(pos>5){
            segundo[0] = horario[pos-2];
            segundo[1] = horario[pos-1];
            segundo[2] = '\0';            
        }
    }
    
    printf("\n\n%s hora(s), %s minuto(s) e %s segundo(s).\n\n", hora, minuto, segundo);

}
