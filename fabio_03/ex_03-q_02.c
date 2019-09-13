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
    char mes_ext[20];
    
    if (mes=="01"){
        strcpy (mes_ext, "janeiro");
    }
    else if (mes=="02"){
        strcpy (mes_ext, "Fevereiro");
    }
    else if (mes=="03"){
        strcpy (mes_ext, "Marco");
    }
    else if (mes=="04"){
        strcpy (mes_ext, "Abril");
    }
    else if (mes=="05"){
        strcpy (mes_ext, "Maio");
    }
    else if (mes=="06"){
        strcpy (mes_ext, "Junho");
    }
    else if (mes=="07"){
        strcpy (mes_ext, "Julho");
    }
    else if (mes=="08"){
        strcpy (mes_ext, "Agosto");
    }
    else if (mes=="09"){
        strcpy (mes_ext, "Setembro");
    }
    else if (mes=="10"){
        strcpy (mes_ext, "Outubro");
    }
    else if (mes=="11"){
        strcpy (mes_ext, "Novembro");
    }
    else if (mes=="12"){
        strcpy (mes_ext, "Dezembro");
    }

    printf("\n\n%s de %s de %s.\n", dia, mes_ext, ano);
       
    

}