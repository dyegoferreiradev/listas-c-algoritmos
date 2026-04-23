#include <stdio.h>

int main(){

    char c = 'a';
    char *pc = &c;

    printf("a) Endereco de c: %p, Valor de c: %c\n", &c, c);
    printf("b) Valor que pc armazena: %p, Valor guardado no endereco de pc: %c\n", pc, *pc);
    printf("c) Endereco de pc: %p\n", &pc);
    printf("d) Endereco do valor guardado no endereco apontado por pc: %p, Valor guardado no endereco de pc: %p", &*pc, *&pc);

    /*Explicação letra d: São iguais pois, mesmo sendo lidados com os termos em ordens diferentes, 
    ambos se referem ao endereço de memoria do vetor pc, que esta diretamente ligado a variavel c.*/

    return 0;
}