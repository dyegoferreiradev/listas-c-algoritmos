#include <stdio.h>
#include <stdlib.h>

int main(){

    char **str, *temp;  
    int qtdStrings=0;  
    str=(char **)malloc(sizeof(char*));
    if(str==NULL){ printf("Erro de alocação de memória!\n"); exit(1);}

    while(1){
        temp=(char*)malloc(100*sizeof(char));
        if(temp==NULL){ printf("Erro de alocação de memória!\n"); exit(1);}
        printf("Digite uma string (ou pressione enter para sair): ");
        if(fgets(temp, 100, stdin)==NULL || temp[0]=='\n'){
            free(temp);
            break;
        }
        temp[strcspn(temp, "\n")]='\0';
        char *tempStr=(char*)realloc(str, (qtdStrings+1)*sizeof(char*));
        if(tempStr==NULL){ printf("Erro de realocação de memória!\n"); exit(1);}
        str=tempStr;
        str[qtdStrings]=temp;
        qtdStrings++;
    }

    printf("\nStrings armazenadas:\n");

    for(int i=0; i<qtdStrings; i++){
        printf("%s\n", str[i]);
        free(str[i]);
    }
    
    free(str);
    return 0;
}