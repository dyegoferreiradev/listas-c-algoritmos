#include <stdio.h>

int main() {

    int R1, DIV1, R2, DIV2, R3, DIV3;
    scanf("%d %d", &R1, &DIV1); 
    scanf("%d %d", &R2, &DIV2); 
    scanf("%d %d", &R3, &DIV3);

    int x=0;
    int freio=0;

    while (!freio) {
        if ((x-R1)%DIV1==0 && (x-R2)%DIV2==0 && (x-R3)%DIV3==0) {
            printf("%d", x);
            freio = 1;
        } 
        x++;
    }
    

    return 0;
}
