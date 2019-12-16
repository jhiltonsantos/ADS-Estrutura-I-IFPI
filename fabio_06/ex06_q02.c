#include "fila_dinamica.h"

void menu()
{
    int option, e;
    int press;

    inicializar(&Fila);
    // COLOCAR O TEMPO POR VOLTAS DENTRO DO WHILE
    int volta = 1;

    do
    {
        system("clear");
        printf("FILA DE IMPRESSÃO DE DOCUMENTOS\n\n");
        printf("1 - SOLICITAR IMPRESSÃO\n");
        printf("2 - MOSTRAR FILA DE IMPRESSÃO\n");
        printf("0 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &option);
        press = getchar();

        switch (option)
        {
        case 1:
        {
            int id, voltas;
            bool inseriu;
            system("clear");
            printf("SOLICITAR IMPRESSÃO\n\n");

            printf("ID DO ARQUIVO: \n");
            scanf("%d", &id);
            printf("NUMERO DE VOLTAS: \n");
            scanf("%d", &voltas);

            inseriu = inserir_fila(&Fila, id);
            if (inseriu)
            {
                printf ("\n\nID INSERIDO!!!");
            }
            else
            {
                printf("\n\nID NÃO FOI INSERIDO!!!");
            }
                    
            volta = volta + voltas;
            break;
        }

        case 2:
        {
            mostrar_fila(&Fila);
        }

        default:
        {
            if (option != 0)
            {
                printf("OPCAO INVÁLIDA!!!\n\n");
            }
            break;
        }
        }

        volta--;
    } while (option != 0);
}

int main(void)
{
    menu();
}
