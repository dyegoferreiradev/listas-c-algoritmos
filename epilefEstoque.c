#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct{
    char nome[50];
    float preco;
    int quantidade;
}Produto;
 
int main(){
    
    int i, j, qtdProdutos;
    scanf("%d", &qtdProdutos);
    Produto produto[qtdProdutos][qtdProdutos];
    
    for(i=0; i<qtdProdutos; i++){
        for(j=0; j<qtdProdutos; j++){
            strcpy(produto[i][j].nome, "vazio");
            produto[i][j].preco=0;
            produto[i][j].quantidade=0;            
        }
    }
    int flag, count=0;
    for(flag=0;flag!=1;){
        char acao[40], nome[50];
        int linha, coluna, quantidade;
        float preco;
        scanf("%s", acao);
        if(strcmp(acao, "EXIT")==0){
            printf("Saindo...\n");
            flag=1;
        }if(strcmp(acao, "CREATE")==0){
            scanf(" %d %d", &linha, &coluna);
            if(strcmp(produto[linha][coluna].nome, "vazio")!=0){
                printf("ERRO: espaco ja ocupado\n");
            }else{
                scanf(" %s %d %f", nome, &quantidade, &preco);
                produto[linha][coluna].preco=preco;
                produto[linha][coluna].quantidade=quantidade;
                strcpy(produto[linha][coluna].nome, nome);
                printf("Produto adicionado no produto!\n");
                count++;
            }
        }if(strcmp(acao, "READ")==0){
            scanf("%s", nome);
            int flag2=0;
            for(i=0; i<qtdProdutos && flag2!=1; i++){
                for(j=0; j<qtdProdutos; j++){
                    if(strcmp(produto[i][j].nome, nome)==0){
                        printf("LINHA: %d COLUNA: %d QTD: %d PRECO: %.2f\n", i, j, produto[i][j].quantidade, produto[i][j].preco);
                        flag2=1;
                        break;
                    }
                }
            }
            if(flag2==0){
                printf("ERRO: Produto nao encontrado.\n");
            }
        }if(strcmp(acao, "UPDATE")==0){
            scanf("%s %d %f", nome, &quantidade, &preco);
            int flag2=0;
            for(i=0; i<qtdProdutos && flag2!=1; i++){
                for(j=0; j<qtdProdutos; j++){
                    if(strcmp(produto[i][j].nome, nome)==0){
                        produto[i][j].quantidade=quantidade;
                        produto[i][j].preco=preco;
                        printf("Produto atualizado!\n");
                        flag2=1;
                        break;
                    }
                }
            }
            if(flag2==0)
                printf("Produto nao encontrado!\n");
        }if(strcmp(acao, "DELETE")==0){
            scanf("%s", nome);
            int flag2=0;
            for(i=0; i<qtdProdutos && flag2!=1; i++){
                for(j=0; j<qtdProdutos; j++){
                    if(strcmp(produto[i][j].nome, nome)==0){
                        strcpy(produto[i][j].nome, "vazio");
                        produto[i][j].quantidade=0;
                        produto[i][j].preco=0.0;
                        printf("Produto removido!\n");
                        flag2=1;
                        break;
                    }
                }
            }
            if(flag2==0){
                printf("Produto nao encontrado!\n");
            }
        }if(strcmp(acao, "PRINT")==0){
            for(i=0; i<qtdProdutos; i++){
                for(j=0; j<qtdProdutos; j++){
                    if(strcmp(produto[i][j].nome, "vazio")!=0){
                        printf("LINHA: %d COLUNA: %d NOME: %s QTD: %d PRECO: %.2f\n", i, j, produto[i][j].nome, produto[i][j].quantidade, produto[i][j].preco);
                    }
                }
            }
        }
    }
 
    return 0;
}