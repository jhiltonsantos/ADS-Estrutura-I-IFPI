#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char data[30];
    char dia[3], mes[3], ano[5];

    printf("Digite a data: ");
    fgets(data, sizeof(data), stdin);
    int tamanho = strlen(data);

    for (int i=0, pos = 0; i < tamanho; i++, pos++){
        
        if (data[pos] == '/'){
            if (pos==2){
                dia[0] = data[pos-2];
                dia[1] = data[pos-1];
                dia[2] = '\0';
            }
            else if(pos==5){
                mes[0] = data[pos-2];
                mes[1] = data[pos-1];
                mes[2] = '\0';

                for (int j=0,k=6; j < 5; j++,k++)
                {
                    ano[j] = data[k];
                    ano[4] = '\0';
                }
                
            }
        }
        
        
    }

    printf("\nDia: %s", dia);

}