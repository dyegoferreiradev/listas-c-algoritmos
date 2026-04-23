#include <stdio.h>

int main() {
    int N, vinho;
    scanf("%d", &N);

    while (N--) {
        int nota, total_notas = 0, count_notas = 0;

        while (scanf("%d", &nota) && nota != 0) {
            total_notas += nota;
            count_notas++;
        }

        int media = total_notas / count_notas;
        vinho += media;
    }
    printf("Elas beberam %d taças!\n", vinho);
    return 0;
}
