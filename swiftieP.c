#include <stdio.h>

int main (){

    char A, B, C, D, E, F;
    int count = 0, countr = 0;

    scanf("%c %c %c %c %c %c", &A, &B, &C, &D, &E, &F);

    if(A == 'x')        //se count = 0, 6 fios conectados
        count += 1;     //se count = 1, 5 fios conectados 
    if(B == 'x')        //se count = 2, 4 fios conectados
        count += 1;
    if(C == 'x')
        count += 1;
    if(D == 'x')
        count += 1;
    if(E == 'x')
        count += 1;
    if(F == 'x')
        count += 1;

    
    if(A == 'r')        //countr = 0, não há fio vermelho conectado     
        countr += 1;      
    if(B == 'r')        
        countr += 1;
    if(C == 'r')
        countr += 1;
    if(D == 'r')
        countr += 1;
    if(E == 'r')
        countr += 1;
    if(F == 'r')
        countr += 1;


    

    if(A != 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x') {// 6 fios conectados
        if(A == 'g' && B != 'g' && C != 'g' && D != 'g' && E != 'g' && F != 'g') // apenas a é verde
            printf("corta a\n");
        else if(A != 'g' && B == 'g' && C != 'g' && D != 'g' && E != 'g' && F != 'g') // apenas b é verde
            printf("corta b\n");
        else if(A != 'g' && B != 'g' && C == 'g' && D != 'g' && E != 'g' && F != 'g') // apenas c é verde
            printf("corta c\n");
        else if(A != 'g' && B != 'g' && C != 'g' && D == 'g' && E != 'g' && F != 'g') // apenas d é verde
            printf("corta d\n");
        else if(A != 'g' && B != 'g' && C != 'g' && D != 'g' && E == 'g' && F != 'g') // apenas e é verde
            printf("corta e\n");
        else if(A != 'g' && B != 'g' && C != 'g' && D != 'g' && E != 'g' && F == 'g') // apenas f é verde
            printf("corta f\n");
        else
            printf("corta e\n");
    }

    else if(count == 1){ //5 fios conectados
        if(A == 'y' && B == 'y')
            printf("corta a\n");
        else if(A == 'x' && B == 'y' && C == 'y') //a = x
            printf("corta b\n");
        else if(A == 'y' && C == 'y'&& B == 'x') //b = x
            printf("corta a\n");
        else{
            if((A == 'x' && B != 'x') || (A != 'x' && B == 'x')) //a ou b desconectados
                printf("corta c\n");
            else if (A != 'x' && B != 'x') //a e b conectados
                printf("corta b\n");
        }
    }

    else if(count == 2){ //4 fios conectados 
        if(countr == 0){ //nenhum vermelho
            if((A == 'x' && B == 'x') || (A == 'x' && C == 'x') || (B == 'x' && C == 'x'))
                printf("corta d\n");
            else if(A != 'x' && B != 'x')
                printf("corta b\n");
            else if(A != 'x' && B == 'x' && C != 'x')
                printf("corta c\n");
        }
        else if (D == 'b' && E == 'x' && F == 'x')
            printf("corta d\n");
        else if(E == 'b' && F == 'x')
            printf("corta e\n");
        else if (F == 'b')
            printf("corta f\n");
        else {
            if(A != 'x')
                printf("corta a\n");
            else if(A == 'x' && B != 'x')
                printf("corta b\n");
            else if(A == 'x' && B == 'x')
                printf("corta c\n");
        }
    

    }

    return 0;
}
