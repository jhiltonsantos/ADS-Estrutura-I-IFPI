// PROBLEMA NA 80

//#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 10

typedef struct{
    int topo;
    char elemento[tam];
} pilha;

pilha alameda;
pilha auxiliar;

// INICIAR PILHAS
void inicializacao(pilha *Pilha){
    Pilha -> topo = -1;
}


// PILHA CHEIA E VAZIA
bool estacionamento_lotado(pilha *Pilha){
    if(Pilha -> topo == tam -1){
        return true;
    }
    return false;
}

bool estacionamento_vazio(pilha *Pilha){
    if (Pilha -> topo == -1){
        return true;
    }
    return false;
}


// MOSTRAR VEICULOS NO ESTACIOMENTO
void mostrarEstacimento(pilha *Pilha){
    int saida;
    if (estacionamento_vazio(Pilha))
    {
        printf("\n\nESTACIONAMENTO VAZIO!!!\n");
    }
    else
    {
        printf("\nESTACIOMENTO  -> ESPACOS OCUPADOS\n");
        for (int i = Pilha->topo; i >= 0; i--)
        {
            saida = Pilha->elemento[i];
            printf("\n Veiculo - %d", saida);
        }
    }
}


// PUSH - POP
void novo_veiculo(pilha *Pilha, int veiculo){ // empilhar
    Pilha -> topo = Pilha -> topo + 1;
    Pilha -> elemento[Pilha -> topo] = veiculo;
}

void retornar_veiculos(pilha *Pilha, pilha *aux){
    while (estacionamento_vazio(aux) == false){
        novo_veiculo(Pilha, aux->elemento[aux->topo]);
    }
}

void saida_topo_estaciomento(pilha *Pilha){ // desempilhar
    int veiculo;
    veiculo = Pilha->elemento[Pilha->topo];
    Pilha->topo = Pilha->topo-1;
}

void saida_veiculo_selecionado(pilha *Pilha, pilha *aux, int veiculo){ 
    int removeu_topo;
    do{
        saida_topo_estaciomento(Pilha);
        removeu_topo = Pilha->elemento[Pilha->topo];

        novo_veiculo(aux, removeu_topo);
    } while (veiculo != removeu_topo);
    
    saida_topo_estaciomento(Pilha);
    retornar_veiculos(Pilha, aux);
}


// MENU
void menu(){
    int placa, opcao, i;
    int veiculo;

    inicializacao(&alameda);
    inicializacao(&auxiliar);

    do{
        system("cls");
        printf("\nESTACIONAMENTO\n\n");
        printf("1 - ENTRADA DE VEICULO\n");
        printf("2 - REMOVER VEICULO\n");
        printf("3 - MOSTRAR VEICULOS NO ESTACIONAMENTO\n");
        printf("9 - SAIR\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        // CASOS
        switch (opcao){
            case 1: // ENTRADA DE NOVO VEICULO
            {   
                if (estacionamento_lotado(&alameda)){
                    printf("\n\nESTACIONAMENTO LOTADO!!!");
                } 
                else{
                    printf("\n\nDIGITE A PLACA DO VEICULO:  ");
                    scanf("%d", &placa);
                    novo_veiculo(&alameda, placa);
                    i++;                    
                }
                break;
            }
            
            case 2: // SAIDA DE VEICULO
            {
                if (estacionamento_vazio(&alameda)){
                    printf("\n\nESTACIONAMENTO VAZIO\n");
                }
                else{
                    int saiu;
                    mostrarEstacimento(&alameda);
                    printf("\n\nDIGITE A PLACA DO VEICULO: ");
                    scanf("%d", &veiculo);

                    saida_veiculo_selecionado(&alameda, &auxiliar, veiculo);
                    printf("\nO veiculo foi removido.\n");
                    mostrarEstacimento(&alameda);
                }
                break;
            }
            case 3:
            {
                mostrarEstacimento(&alameda);
                break;
            }
            case 9:
            {
                printf("\n\nSAINDO...");
                break;
            }
            default: 
            {
                printf("\n\nOPCAO INVALIDA\n");
                break;
            }
        }
        printf("\n\n");
        system("pause");

    } while (opcao != 9);
    
}


// MAIN
int main(){
    menu();

}