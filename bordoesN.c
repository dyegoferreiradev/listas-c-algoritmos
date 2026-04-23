#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
      long long int n, a, b, soma_intervalo, soma_a, soma_b, ab, fim;

    scanf("%lli", &n);
    scanf("%lli %lli", &a, &b);

    soma_intervalo = n*(1+n)/2;
    soma_a = (1+n/a)*(n/a)*a/2;
    soma_b = (1+n/b)*(n/b)*b/2;
    ab = (a * b * ((n/(a*b)) * (n/(a*b)+1)))/2;

    fim = soma_intervalo -(soma_a + soma_b) + ab ;

    if(fim%2 != 0){
        printf("%lli\n", fim);
        printf("Opa xupenio AULAS...");
    } else{
        printf("%lli\n", fim);
        printf("Lá ele!!!");
    }
	return 0;
}