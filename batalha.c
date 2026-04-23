#include <stdio.h>

int main (){
    
    int soldadosAliado, tanquesAliado, avioesAliado, lancamisseisAliado;
    int soldadosInimigo, tanquesInimigo, avioesInimigo, lancamisseisInimigo;
    int soldadosReforco, tanquesReforco, avioesReforco, lancamisseisReforco;

    scanf("%d %d %d %d", &soldadosAliado, &tanquesAliado, &avioesAliado, &lancamisseisAliado);
    scanf("%d %d %d %d", &soldadosInimigo, &tanquesInimigo, &avioesInimigo, &lancamisseisInimigo);
    scanf("%d %d %d %d", &soldadosReforco, &tanquesReforco, &avioesReforco, &lancamisseisReforco);

    if(soldadosAliado > soldadosInimigo + soldadosReforco && tanquesAliado > tanquesInimigo + tanquesReforco && avioesAliado > avioesInimigo + avioesReforco && lancamisseisAliado > lancamisseisInimigo + lancamisseisReforco){
        printf("Avancar");
    }
    else if(soldadosAliado > soldadosInimigo + soldadosReforco && tanquesAliado > tanquesInimigo + tanquesReforco && avioesAliado > avioesInimigo + avioesReforco){
        printf("Avancar");
    }
    else if(soldadosAliado > soldadosInimigo + soldadosReforco && avioesAliado > avioesInimigo + avioesReforco && lancamisseisAliado > lancamisseisInimigo + lancamisseisReforco){
        printf("Avancar");
    }
    else if (soldadosAliado > soldadosInimigo + soldadosReforco && tanquesAliado > tanquesInimigo + tanquesReforco && lancamisseisAliado > lancamisseisInimigo + lancamisseisReforco){
        printf("Avancar");
    }
    else if (tanquesAliado > tanquesInimigo + tanquesReforco && avioesAliado > avioesInimigo + avioesReforco && lancamisseisAliado > lancamisseisInimigo + lancamisseisReforco){
        printf("Avancar");
    }
    else if(soldadosAliado < soldadosInimigo + soldadosReforco && tanquesAliado < tanquesInimigo + tanquesReforco && avioesAliado < avioesInimigo + avioesReforco && lancamisseisAliado < lancamisseisInimigo + lancamisseisReforco){
        printf("Recuar");
    }
    else if(soldadosAliado < soldadosInimigo + soldadosReforco && tanquesAliado < tanquesInimigo + tanquesReforco && avioesAliado < avioesInimigo + avioesReforco){
        printf("Recuar");
    }
    else if(soldadosAliado < soldadosInimigo + soldadosReforco && avioesAliado < avioesInimigo + avioesReforco && lancamisseisAliado < lancamisseisInimigo + lancamisseisReforco){
        printf("Recuar");
    }
    else if (soldadosAliado < soldadosInimigo + soldadosReforco && tanquesAliado < tanquesInimigo + tanquesReforco && lancamisseisAliado < lancamisseisInimigo + lancamisseisReforco){
        printf("Recuar");
    }
    else if (tanquesAliado < tanquesInimigo + tanquesReforco && avioesAliado < avioesInimigo + avioesReforco && lancamisseisAliado < lancamisseisInimigo + lancamisseisReforco){
        printf("Recuar");
    }
    else{
        printf("Permanecer");
    }

    return 0;
}