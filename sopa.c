#include <stdio.h>
#include <string.h>
 
int main() {
    char sopa[30];
    int numpalavras;
 
    // Leia a string principal
    //printf("Digite a string principal: ");
    scanf("%29s", sopa);
 
    // Leia o número de substrings
   // printf("Digite o número de substrings (até 5): ");
    scanf("%d", &numpalavras);
 
    char substrings[numpalavras][30];  // Supondo um máximo de 5 substrings, cada uma com comprimento máximo de 20
    int indices[numpalavras][30];      // Para armazenar os índices de cada palavras
    int counts[numpalavras];           // Para armazenar a contagem de caracteres encontrados para cada palavras
    
    int achador = 0;
 
    // Leia cada palavras
    for (int k = 0; k < numpalavras; k++) {
       // printf("Digite a palavras %d: ", k + 1);
        scanf("%29s", substrings[k]);
        counts[k] = 0;  // Inicialize a contagem como 0 para cada palavras
    }
 
    // Encontre e armazene os índices de cada palavras
    for (int k = 0; k < numpalavras; k++) {
        int count = 0;
 
        for (int j = 0; j < strlen(substrings[k]); j++) {
            char currentChar = substrings[k][j];
            int found = 0;
 
            for (int i = 0; i < strlen(sopa); i++) {
                if (currentChar == sopa[i]) {
                    indices[k][count++] = i;
                    found = 1;
                    break;
                }
            }
 
            // Se o caractere não for encontrado, defina seu índice como -1
            if (!found) {
                indices[k][count++] = -1;
            }
        }
 
        counts[k] = count;  // Atualize a contagem para a palavras atual
    }
 
    // Realize as remoções na ordem da entrada do usuário
    for (int k = 0; k < numpalavras; k++) {
        // Verifique se a palavras inteira está presente na string principal
        int substringPresente = 1;
        for (int i = 0; i < counts[k]; i++) {
            if (indices[k][i] == -1) {
                substringPresente = 0;
                break;
            }
        }
 
        // Remova a palavras se estiver totalmente presente na string principal
        if (substringPresente) {
            achador++;
            for (int i = 0; i < counts[k]; i++) {
                sopa[indices[k][i]] = '0';
            }
        }
    }
 
    // Imprima a string principal após remover as substrings
    //printf("String principal após remover as substrings: %s\n", sopa);
 
    // Imprima o número de substrings encontradas
    printf("E possivel formar %d palavras com esse conjunto\n", achador);
 
    return 0;
}