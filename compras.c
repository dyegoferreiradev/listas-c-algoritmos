#include <stdio.h>
#include <string.h>

//struct dos produtos

typedef struct{ 
    char nome[100];
    int qtd;
    float valor;
}Produto;

int main(){

    //Entrada de dados

    int i, N;
    scanf("%d", &N);
    Produto produto[N];
    for(i=0; i<N; i++){
        scanf("%s %f %d ", produto[i].nome, &produto[i].valor, &produto[i].qtd);
    }
    char data[40], pago[10];
    scanf("%39[^\n] ", data);
    scanf("%9[^\n]", pago);

    //Processamento de dados
    
    for(i = 0; i < N - 1; i++){ //Ordenando os produtos em ordem alfabética (usando bubble sort)
        for(int j = 0; j < N - i - 1; j++){
            if(strcmp(produto[j].nome, produto[j + 1].nome) > 0){
                Produto temp = produto[j];
                produto[j] = produto[j + 1];
                produto[j + 1] = temp;
            }
        }
    }

    float valorTotal = 0; //Calculo dos valores
    for(i=0; i<N; i++){
        produto[i].valor = produto[i].valor * produto[i].qtd;
        valorTotal += produto[i].valor;
    }
    char dataFinal[6]; //Retirando a data da string principal
    unsigned int comprimentoData = strlen(data);
        strncpy(dataFinal, &data[comprimentoData - 5], 5);
        dataFinal[5] = '\0';

    char pagoFinal[10]; //Retirando o número da string pago
    unsigned int indiceInicio = 0;
    unsigned int j = 0;
    while(pago[indiceInicio] != '\0' && pago[indiceInicio] != '$'){
        indiceInicio++;
    }
    if(pago[indiceInicio] == '$'){
        indiceInicio++;
        while (pago[indiceInicio] != '\0' && j < 9) {
            pagoFinal[j++] = pago[indiceInicio++];
        }
        pagoFinal[j] = '\0';
    }

    float numPagoReal = 0.0f; //Convertendo a string do numero pago para um número real
    int sinal = 1;
    if(pagoFinal[0] == '-'){
        sinal = -1;
    }else{
        numPagoReal = pagoFinal[0] - '0';
    }
    float divisor = 10.0f;
    int k = 1;
    while(pagoFinal[k] != '\0'){
        if(pagoFinal[k] == '.'){
            for (++k; pagoFinal[k] != '\0'; ++k) {
                numPagoReal = numPagoReal + (pagoFinal[k] - '0') / divisor;
                divisor *= 10.0f;
            }
            break;
        }else{
            numPagoReal = numPagoReal * 10.0f + (pagoFinal[k] - '0');
        }
        k++;
    }
    numPagoReal *= (float)sinal;

    float troco = numPagoReal - valorTotal; //Troco

    //Saida de dados
    printf("=============\n");
    printf("NF - 0123\n");
    printf("Data - %s\n", dataFinal);
    printf("=============\n");
    for(i=0; i<N; i++){
        printf("%dx %s - R$%.2f\n", produto[i].qtd, produto[i].nome, produto[i].valor);
    }
    printf("\n");
    printf("Valor Total - R$%.2f\n", valorTotal);
    printf("Pago - R$%s\n", pagoFinal);
    printf("Troco - R$%.2f\n", troco);
    printf("=============");
    
    return 0;
}