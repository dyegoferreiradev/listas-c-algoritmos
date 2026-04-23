#include <stdio.h>
#include <string.h>
 
int main(){
    int qtd;
    char nome[qtd][11]; //qtd=quantidade
    char senha[qtd][50]; 
    scanf("%d", &qtd);
 
    for(int i=0; i<qtd; i++){
        char cpf[12];
        scanf(" %10s", nome[i]);
        scanf(" %11s", cpf);
        strcpy(senha[i], nome[i]); 
        strcat(senha[i], " ");
        int senhaInicio=strlen(senha[i]);
 
        for(int j=0; nome[i][j]!='\0'; j++){
            int troca;  
            char letra;
            letra=nome[i][j];
            troca=cpf[j]-'0';
            char letraAtualizada=((letra+troca+26-'a')%26+'a');
            senha[i][senhaInicio+j]=letraAtualizada;
        }
        for(int k=0; k<2; k++){
            senha[i][senhaInicio+strlen(nome[i])+k]=cpf[9+k];
        }
        senha[i][senhaInicio+strlen(nome[i])+2]='\0';
    }
    for(int i=0; i<qtd-1; i++){
        for(int j=0; j<qtd-i-1; j++){
            if(strcmp(senha[j], senha[j+1])>0){
                char aux[50];
                strcpy(aux, senha[j]);
                strcpy(senha[j], senha[j+1]);
                strcpy(senha[j+1], aux);
            }
        }
    }
    printf("\n");
 
    for (int i=0; i<qtd; i++) {
        printf("%s\n", senha[i]);
    }
 
    return 0;
}