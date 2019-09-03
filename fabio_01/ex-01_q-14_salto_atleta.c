//
// Created by hilton on 31/08/2019.
//

#include <stdio.h>
#include <string.h>


int main(void){

	char nome[50];
	float media = 0, distancia[5];
	
    printf("Qual o nome do atleta? ");
	gets(nome);
	setbuf(stdin, NULL);
	
    while (strcmp(nome,"")!=0)
    {
        printf("Atleta: %s.\n\n", nome);
		int salto[5];
		float soma = 0;
		
		for (int i=0; i<5; i++)
        {
			salto[i] = i + 1;
			printf("%d Salto: ", salto[i]);
			scanf("%f", &distancia[i]);
			setbuf(stdin, NULL);
			soma += distancia[i]; 			
		}
		
        media = soma / 5;
		printf("\n\nResultado final: \n");
        printf("Atleta: %s \n", nome);
        printf("Saltos: ");
        
		for (int i=0; i<4; i++)
        { 
			printf("%.1f - " , distancia[i]);
		}
		printf("%.1f\n", distancia[4]);
		printf("Media dos saltos: %.2f m\n\n", media);
		
		printf("Qual o nome do atleta? ");
		gets(nome);
	}

	return 0;
}