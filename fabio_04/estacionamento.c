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

int saida_topo_estaciomento(pilha *Pilha){ // desempilhar
    int veiculo;
    veiculo = Pilha->elemento[Pilha->topo]; // elemento do topo da pilha
    Pilha->topo = Pilha->topo-1; // decrementa uma posicao do topo da pilha

    return veiculo;
}

void retornar_veiculos(pilha *Pilha, pilha *aux){ // retornar os veiculos para a pilha principal
    int topo, auxiliar;

    while (estacionamento_vazio(aux) == false){
        topo = aux->elemento[aux->topo];
        novo_veiculo(Pilha, topo);
        auxiliar = saida_topo_estaciomento(aux);
    }
}

void saida_veiculo_selecionado(pilha *Pilha, pilha *aux, int veiculo){ 
    // remove veiculo da pilha principal
    int removeu_topo, saiu_principal;

    do{ // move os veiculos não removidos para a pilha auxiliar
        removeu_topo = saida_topo_estaciomento(Pilha);
        if (removeu_topo != veiculo){
            novo_veiculo(aux, removeu_topo);
        }    
    } while (veiculo != removeu_topo);
    
    retornar_veiculos(Pilha, aux);
}


// MENU
void menu(){
    int placa, opcao, i;
    int veiculo;

    inicializacao(&alameda);
    inicializacao(&auxiliar);

    do{
        //system("cls");
        printf("\33[H\33[2J");

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
                    
                    mostrarEstacimento(&alameda);
                    printf("\n\nDIGITE A PLACA DO VEICULO: ");
                    scanf("%d", &veiculo);

                    saida_veiculo_selecionado(&alameda, &auxiliar, veiculo);
                    printf("\nO VEICULO %d FOI REMOVIDO!!!\n", veiculo);
                    mostrarEstacimento(&alameda);

                    int c = getchar();
                    printf("\n\nPrecione qualquer tecla para continuar...");
                
                }
                break;
            }
            case 3:
            {
                mostrarEstacimento(&alameda);
                int c = getchar();
                printf("\n\nPrecione qualquer tecla para continuar...");
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
        int c = getchar();
        //system("PAUSE");

    } while (opcao != 9);
}


// MAIN
int main(){
    menu();

}
