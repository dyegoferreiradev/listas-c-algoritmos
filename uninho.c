#include <stdio.h>

int main()
{

    float hrsaida, hrvolta, tempo;
    char destino;
    int pessoas;

    scanf("%f %f %c %d", &hrsaida, &hrvolta, &destino, &pessoas);

    if (hrsaida < 0 || hrvolta < 0 || hrsaida >= 24 || hrvolta >= 24 || hrsaida >= hrvolta || (destino != 'A' && destino != 'B') || pessoas <= 0)
    {
        printf("Entrada Invalida\n");
    }
    else
    {
        tempo = hrvolta - hrsaida;

        if (destino == 'A')
        {

            if ((tempo > 1.0 && pessoas <= 5) || (tempo >= 1.5 && pessoas <= 9))
            {
                printf("O uninho faz a boa, obrigado querida mae line\n");
            }
            else
            {
                printf("Infelizmente o uninho nao tanka, rodamos!\n");
            }
        }

        else if (destino == 'B')
        {

            if ((tempo > 0.75 && pessoas <= 5) || (tempo >= 1.125 && pessoas <= 9))
            {
                printf("O uninho faz a boa, obrigado querida mae line\n");
            }
            else
            {
                printf("Infelizmente o uninho nao tanka, rodamos!\n");
            }
        }
    }

    return 0;
}