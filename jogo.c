#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char matriz[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    int qtdJog;
    scanf("%d", &qtdJog);

    int contadorPassados = 0;  

    // Loop para cada jogador
    for (int i = 0; i < qtdJog; i++) {
        int qtdMov;
        scanf("%d", &qtdMov);
        char movJog[qtdMov];
        for (int j = 0; j < qtdMov; j++) {
            scanf(" %c", &movJog[j]);
        }
        int passando = 1;
        int posX = 0; 
        int posY = 0;  

        for (int j = 0; j < qtdMov; j++) {
            char movimento = movJog[j];
            if (movimento == 'D') {
                posX++;
            } else if (movimento == 'E') {
                posX--;
            } else if (movimento == 'B') {
                posY++;
            } else if (movimento == 'C') {
                posY--;
            }
            if (matriz[posY][posX] == '.') {
                passando=0;
                break;
            }
            if (posX >= 0 && posX < n && posY >= 0 && posY < n) {
            passando=1;
            }
            else {
                passando=0;
                break;
            }
            if (matriz[posY][posX] == 'x') matriz[posY][posX] = '.';
            
        }
        
        
        if (passando==0) {
            passando = 1;
            for (int j = 0; j < qtdMov / 2; j++) {
                if (movJog[j] != movJog[qtdMov - j - 1]) {
                    passando = 0; 
                    break;
                }
            }
        }
        if (passando) {
            contadorPassados++;
        }
    }

    printf("%d", contadorPassados);

    return 0;
}