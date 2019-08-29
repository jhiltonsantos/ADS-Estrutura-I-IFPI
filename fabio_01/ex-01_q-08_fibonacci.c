#include <stdio.h>

int main(){
    int termos, fibonacci1=0, fibonacci2=1, fibonacci;
    printf("Determine a quantidade de termos da sequencia de Fibonacci: ");
    scanf("%d", &termos);

    printf("\n\nSEQUENCIA DE FIBONACCI\n");
    printf("0, 1");
    for (int i=2;i<termos;i++){
        fibonacci = fibonacci1 + fibonacci2;
        printf(", %d", fibonacci);
        fibonacci1 = fibonacci2;
        fibonacci2 = fibonacci;
    }
    printf(".\n\n");

    return 0;
}
