#include <stdio.h>

int main() {
    int soldadosAliado, tanquesAliado, avioesAliado, lancamisseisAliado;
    int soldadosInimigo, tanquesInimigo, avioesInimigo, lancamisseisInimigo;
    int soldadosReforco, tanquesReforco, avioesReforco, lancamisseisReforco;

    // Leitura dos valores de entrada
    scanf("%d %d %d %d", &soldadosAliado, &tanquesAliado, &avioesAliado, &lancamisseisAliado);
    scanf("%d %d %d %d", &soldadosInimigo, &tanquesInimigo, &avioesInimigo, &lancamisseisInimigo);
    scanf("%d %d %d %d", &soldadosReforco, &tanquesReforco, &avioesReforco, &lancamisseisReforco);

    // Cálculo das forças após a chegada dos reforços
    soldadosInimigo += soldadosReforco;
    tanquesInimigo += tanquesReforco;
    avioesInimigo += avioesReforco;
    lancamisseisInimigo += lancamisseisReforco;

    // Verificação das condições
    if (soldadosAliado > (soldadosInimigo + soldadosReforco) / 2 &&
        tanquesAliado > (tanquesInimigo + tanquesReforco) / 2 &&
        avioesAliado > (avioesInimigo + avioesReforco) / 2 &&
        lancamisseisAliado > (lancamisseisInimigo + lancamisseisReforco) / 2) {
        printf("Avancar\n");
    } else if (soldadosInimigo > (soldadosAliado + soldadosReforco) / 2 &&
               tanquesInimigo > (tanquesAliado + tanquesReforco) / 2 &&
               avioesInimigo > (avioesAliado + avioesReforco) / 2 &&
               lancamisseisInimigo > (lancamisseisAliado + lancamisseisReforco) / 2) {
        printf("Recuar\n");
    } else {
        printf("Permanecer\n");
    }

    return 0;
}