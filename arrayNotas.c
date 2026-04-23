#include <stdio.h>

int main() {
    
    int N;
    scanf("%d", &N);
   
    int notas[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &notas[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (notas[j] > notas[j + 1]) {
                int aux = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = aux;
            }
        }
    }

    float media = 0;
    for (int i = 0; i < N; i++) {
        media += notas[i];
    }
    media /= N;

    float mediana;
    if (N % 2 == 0) {
        mediana = (notas[N / 2 - 1] + notas[N / 2]) / 2.0;
    } else {
        mediana = notas[N / 2];
    }
        
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);

    int modaCont = 0, maxModaCont = 0; 
    float modaValue;
    for (int i = 0; i < N; i++) {
        int contador = 1;
        for (int j = i + 1; j < N; j++) {
            if (notas[i] == notas[j]) {
                    contador++;
            }
        }
        if (contador > maxModaCont) {
            maxModaCont = contador;
            modaCont = 1;
            modaValue = notas[i];
        } else if (contador == maxModaCont) {
            modaCont++;
        }
    }

    if (modaCont == 1) {
        printf("Moda: %.2f\n", modaValue);
    } else {
        printf("Nao tem moda\n");
    }

    return 0;
}
