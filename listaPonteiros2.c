#include <stdio.h>

int main(){

    int vet[5] = {1, 2, 3, 4, 5};
    int *p = vet;

    printf("a) O endereco guardado em vet: %p, e o endereco guardado em p: %p\n", &vet, p);
    printf("b), c) e d) Todos os valores de vet:\n");

    for(int i=0; i<5 ; i++){
        printf(" %d", p[i]);
    }
    printf("\n");
    for(int i=0; i<5 ; i++){
        printf(" %d", *(p+i));
    }
    printf("\n");
    for(int i=0; i<5 ; i++){
        printf(" %d", vet[i]);
    }
    printf("\n");
    for(int i=0; i<5 ; i++){
        printf(" %d", *(vet+i));
    }
    
    return 0;
}