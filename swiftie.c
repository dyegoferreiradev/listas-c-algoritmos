#include <stdio.h>

int main(){

    char A, B, C, D, E, F;
    scanf("%c %c %c %c %c %c", &A, &B, &C, &D, &E, &F);

    if((A != 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x')){
            if (A == 'g' && B != 'g' && C != 'g' && D != 'g' && E != 'g' && F != 'g'){
                printf("corta a");
            }
            else if (B == 'g' && A != 'g' && C != 'g' && D != 'g' && E != 'g' && F != 'g'){
                printf("corta b");
            }
            else if (C == 'g' && A != 'g' && B != 'g' && D != 'g' && E != 'g' && F != 'g'){
                printf("corta c");
            }
            else if (D == 'g' && A != 'g' && B != 'g' && C != 'g' && E != 'g' && F != 'g'){
                printf("corta d");
            }
            else if (E == 'g' && A != 'g' && B != 'g' && C != 'g' && D != 'g' && F != 'g'){
                printf("corta e");
            }
            else if (F == 'g' && A != 'g' && B != 'g' && C != 'g' && D != 'g' && E != 'g'){
                printf("corta f");
            } else{
                printf("corta e");
    }
    if((A != 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F == 'x') || (A == 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x') || (A != 'x' && B == 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x') || (A != 'x' && B != 'x' && C == 'x' && D != 'x' && E != 'x' && F != 'x') || (A != 'x' && B != 'x' && C != 'x' && D == 'x' && E != 'x' && F != 'x') || (A != 'x' && B != 'x' && C != 'x' && D != 'x' && E == 'x' && F != 'x')){
        if (A == 'y' && B == 'y'){
            printf("corta a");    
        } else {
            printf("corta b");
        }
        if (A == 'y' && C == 'y'){
            printf("corta a");
        } else{
            printf("corta c");
        }
        if (A == 'y' && D == 'y'){
            printf("corta a");
        } else{
            printf("corta d");
        }
        if ((A == 'y' && E == 'y')){
            printf("corta a");
        } else{
            printf("corta e");
        }
        if ((A == 'y' && F == 'y')){
            printf("corta a");
        } else{
            printf("corta e");
        }
        if (B == 'y' && C == 'y'){
            printf("corta b");
        } else {
            printf("corta c");
        }
        if (B == 'y' && D == 'y'){
            printf("corta b");
        } else {
            printf("corta d");
        }
        if (B == 'y' && E == 'y'){
            printf("corta b");
        } else {
            printf("corta e");
        }
        if (B == 'y' && F == 'y'){
            printf("corta b");
        } else {
            printf("corta f");
        }
        if (C == 'y' && D == 'y'){
            printf("corta c");
        } else {
            printf("corta d");
        }
        if (C == 'y' && E == 'y'){
            printf("corta c");
        } else {
            printf("corta e");
        }
        if (C == 'y' && F == 'y'){
            printf("corta c");
        } else {
            printf("corta f");
        }
        if (D == 'y' && E == 'y'){
            printf("corta d");
        } else {
            printf("corta e");
        }
        if (D == 'y' && F == 'y'){
            printf("corta d");
        } else {
            printf("corta f");
        }
        if (E == 'y' && F == 'y'){
            printf("corta e");
        } else{
            printf("corta f");
        }



    }



    return 0;
}}