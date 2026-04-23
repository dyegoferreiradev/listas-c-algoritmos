#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float delta, raiz1, raiz2;

    printf("Digite os coeficientes a, b e c da equação do segundo grau (ax^2 + bx + c = 0):\n");
    scanf("%f %f %f", &a, &b, &c);

    delta = (b * b) - 4 * a * c;

    if (delta >= 0) {

        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("As raízes reais são: %.2f e %.2f\n", raiz1, raiz2);
    } 
    
    else 

        printf("A equação não possui raízes reais!\n");
    
    return 0;
}