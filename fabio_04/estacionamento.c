//#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 5

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


// PUSH - POP
void novo_veiculo(pilha *Pilha, char veiculo){ // empilhar
    Pilha -> topo = Pilha -> topo + 1;
    Pilha -> elemento[Pilha -> topo] = veiculo;
}

char valorTopo(pilha *p){
    return p->elemento[p->topo];
}

void retornar_veiculos(pilha *Pilha, pilha *aux){
    while (estacionamento_vazio(aux) == false){
        novo_veiculo(Pilha, aux->elemento[aux->topo]);
    }
}

char saida_topo_estaciomento(pilha *Pilha){ // desempilhar
    char veiculo;

    veiculo = Pilha -> elemento[Pilha -> topo];
    Pilha -> topo = Pilha -> topo-1;

    return veiculo;
}

char saida_veiculo_selecionado(pilha *Pilha, pilha *aux, char veiculo){ 
    char removeu_topo, retorno;
    removeu_topo = '$';
    printf("\n\nDIGITE A PLACA DO VEICULO: ");
    scanf("%c", &veiculo);

    while (removeu_topo != veiculo){
        removeu_topo = saida_topo_estaciomento(Pilha);
        novo_veiculo(aux, removeu_topo);
    }

    retorno = saida_topo_estaciomento(Pilha);
    retornar_veiculos(Pilha, aux);

    return retorno;
}



// MOSTRAR VEICULOS NO ESTACIOMENTO
void mostrarEstacimento(pilha *Pilha){
    char saida;
    if (estacionamento_vazio(Pilha)){
        printf("\n\nESTACIONAMENTO VAZIO!!!\n");
    }
    else{
        printf("\nESTACIOMENTO  -> ESPACOS OCUPADOS\n");
        printf("%d", Pilha->elemento[0]);
        printf("%d", Pilha->elemento[1]);
        
        
        for (int i = Pilha->topo; i >= 0; i--){
            saida = Pilha->elemento[i];
            printf("\n Veiculo - %d",  saida);
        }
    }
}


// MENU
void menu(){
    char veiculo[10];
    int opcao;
    int i;

    inicializacao(&alameda);
    inicializacao(&auxiliar);

    do{
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
                printf("Entrou");
                if (estacionamento_lotado(&alameda)){
                    printf("\n\nESTACIONAMENTO LOTADO!!!");
                } 
                else{
                    printf("\n\nDIGITE A PLACA DO VEICULO:  ");
                    scanf("%s", &veiculo[0]);
                    fgets(&veiculo[0], sizeof(&veiculo[0]), stdin);
                    //veiculo[0] = getchar();
                    novo_veiculo(&alameda, veiculo[0]);
                    i++;                    
                }
                printf("Saiu");
                break;
            }
            
            case 2: // SAIDA DE VEICULO
            {
                char remover_veiculo[3];
                if (estacionamento_vazio(&alameda)){
                    printf("\n\nESTACIONAMENTO VAZIO\n");
                }
                else{
                    char saiu;
                    mostrarEstacimento(&alameda);
                    scanf("%s", &remover_veiculo[0]);

                    saiu =  saida_veiculo_selecionado(&alameda, &auxiliar, remover_veiculo[0]);
                    printf("\nO veiculo %c foi removido.\n", saiu);
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

    } while (opcao != 9);
    
}


// MAIN
int main(){
    menu();

}