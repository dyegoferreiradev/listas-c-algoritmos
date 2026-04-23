#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[31];
    int diversao, lvAborrecimento;
}Brinquedo;

int main(){
    char nome_atracao[41];
    Brinquedo parque[3];
    int curticao[10];
    int count=0;
    int i, j;

    for(i=0; i<3; i++){
        scanf(" %[^\n] %d %d", parque[i].nome, &parque[i].diversao, &parque[i].lvAborrecimento);
    }
    for(j=0; j<3; j++){
        int alegria=0;
        for(i=0; i<3; i++){
            alegria+=parque[j].diversao-(i)*(i)*parque[j].lvAborrecimento;
        }
        curticao[j]=alegria;
        count++;
    }
    int cont=0;
    for(i=0; i<2; i++){
        cont+=parque[0].diversao-parque[0].lvAborrecimento*i*i;
    }
    curticao[count]=cont+parque[1].diversao;
    count++;
    cont=0;
    for(i=0; i<2; i++){
        cont+=parque[0].diversao-parque[0].lvAborrecimento*i*i;
    }
    curticao[count]=cont+parque[2].diversao;
    count++;
    cont=0;
    for(i=0; i<2; i++){
        cont+=parque[1].diversao-parque[1].lvAborrecimento*i*i;
    }
    curticao[count]=cont+parque[0].diversao;
    count++;
    cont=0;
    for(i=0; i<2; i++){
        cont+=parque[1].diversao-parque[1].lvAborrecimento*i*i;
    }
    curticao[count]=cont+parque[2].diversao;
    count++;
    cont=0;
    for(i=0; i<2; i++){
        cont+=parque[2].diversao-parque[2].lvAborrecimento*i*i;
    }
    curticao[count]=cont+parque[0].diversao;
    count++;
    cont=0;
    for(i=0; i<2; i++){
        cont+=parque[2].diversao-parque[2].lvAborrecimento*i*i;
    }
    curticao[count]=cont+parque[1].diversao;
    count++;
    for(i=0; i<3;i++){
        curticao[count]+=parque[i].diversao;
    }
    count++;
    int numIndice=0;
    int numValor=curticao[0];
    for(i=1; i<count; i++){
        if(curticao[i]>numValor || (curticao[i]==numValor && i<numIndice)){
            numValor=curticao[i];
            numIndice=i;
        }
    }
    printf("A maior diversao foi: %d\n", numValor);
    
    if(numIndice == 0) 
        printf("indo nos brinquedos: %s 3 vezes.", parque[0].nome);
    if(numIndice == 1) 
        printf("indo nos brinquedos: %s 3 vezes.", parque[1].nome);
    if(numIndice == 2) 
        printf("indo nos brinquedos: %s 3 vezes.", parque[2].nome);
    if(numIndice == 3) 
        printf("indo nos brinquedos: %s 2 vezes, %s 1 vez.", parque[0].nome, parque[1].nome);
    if(numIndice == 4) 
        printf("indo nos brinquedos: %s 2 vezes, %s 1 vez.", parque[0].nome, parque[2].nome);
    if(numIndice == 5) 
        printf("indo nos brinquedos: %s 2 vezes, %s 1 vez.", parque[1].nome, parque[0].nome);
    if(numIndice == 6) 
        printf("indo nos brinquedos: %s 2 vezes, %s 1 vez.", parque[1].nome, parque[2].nome);
    if(numIndice == 7) 
        printf("indo nos brinquedos: %s 2 vezes, %s 1 vez.", parque[2].nome, parque[0].nome);
    if(numIndice == 8) 
        printf("indo nos brinquedos: %s 2 vezes, %s 1 vez.", parque[2].nome, parque[1].nome);
    if(numIndice == 9) 
        printf("indo nos brinquedos: %s 1 vez, %s 1 vez, %s 1 vez.", parque[0].nome, parque[1].nome, parque[2].nome);

    return 0;
}
