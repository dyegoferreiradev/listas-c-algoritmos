#include <stdio.h>
#include <string.h>

int main(){

    char str[50]; // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i = -1;

    scanf(" %49s", str); //Sem espaço na string
    //scanf(" %49[^\n]", str); //Com espaço na string
    //continue o código a partir daqu
    
    for(int i=strlen(str)-1; i>=0; i--){
        *(ptr_inv++) = *(ptr_str+i);
    }
    
    *ptr_inv = '\0';

    printf("O inverso da string: %s\n\n", str_inv);
    
    return 0;
}