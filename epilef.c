#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char tabuleiro[N][N];

    // Ler o tabuleiro
    for (int i = 0; i < N; i++) {
        scanf("%s", tabuleiro[i]);
    }

    int numMovimentos;
    scanf("%d", &numMovimentos);

    char movimentos[numMovimentos];

    // Ler os movimentos
    for (int i = 0; i < numMovimentos; i++) {
        scanf(" %c", &movimentos[i]);
    }

    // Encontrar a posição da casa vazia
    int posLinha, posColuna;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == 'x') {
                posLinha = i;
                posColuna = j;
                break;
            }
        }
    }

    // Executar os movimentos
    for (int k = 0; k < numMovimentos; k++) {
        char movimento = movimentos[k];

        switch (movimento) {
            case 'U':
                if (posLinha > 0) {
                    tabuleiro[posLinha][posColuna] = tabuleiro[posLinha - 1][posColuna];
                    tabuleiro[posLinha - 1][posColuna] = 'x';
                    posLinha--;
                }
                break;
            case 'D':
                if (posLinha < N - 1) {
                    tabuleiro[posLinha][posColuna] = tabuleiro[posLinha + 1][posColuna];
                    tabuleiro[posLinha + 1][posColuna] = 'x';
                    posLinha++;
                }
                break;
            case 'L':
                if (posColuna > 0) {
                    tabuleiro[posLinha][posColuna] = tabuleiro[posLinha][posColuna - 1];
                    tabuleiro[posLinha][posColuna - 1] = 'x';
                    posColuna--;
                }
                break;
            case 'R':
                if (posColuna < N - 1) {
                    tabuleiro[posLinha][posColuna] = tabuleiro[posLinha][posColuna + 1];
                    tabuleiro[posLinha][posColuna + 1] = 'x';
                    posColuna++;
                }
                break;
        }
    }

    // Imprimir a matriz resultante
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
