#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     char A, B, C, D, E, F;

    scanf("%c %c %c %c %c %c", &A, &B, &C, &D, &E, &F);

    if(A != 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x'){
        if((A == 'g') && (B!='g') && (C!='g') && (D!='g') && (E!='g') && (F!='g')){
            printf("corta a");
        } else if((A != 'g') && (B =='g') && (C !='g') && (D !='g') && (E !='g') && (F !='g')){
            printf("corta b");
        }  else if((A != 'g') && (B !='g') && (C =='g') && (D !='g') && (E !='g') && (F !='g')){
            printf("corta c");
        }  else if((A != 'g') && (B !='g') && (C !='g') && (D =='g') && (E !='g') && (F !='g')){
            printf("corta d");
        }  else if((A != 'g') && (B !='g') && (C !='g') && (D !='g') && (E =='g') && (F !='g')){
            printf("corta e");
        } else if((A != 'g') && (B !='g') && (C !='g') && (D !='g') && (E !='g') && (F =='g')){
            printf("corta f");
        } else{
            printf("corta e");
        }
    }

    if(A == 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x' || A != 'x' && B == 'x' && C != 'x' && D != 'x' && E != 'x' && F != 'x' || A != 'x' && B != 'x' && C == 'x' && D != 'x' && E != 'x' && F != 'x' || A != 'x' && B != 'x' && C != 'x' && D == 'x' && E != 'x' && F != 'x' || A != 'x' && B != 'x' && C != 'x' && D != 'x' && E == 'x' && F != 'x' || A != 'x' && B != 'x' && C != 'x' && D != 'x' && E != 'x' && F == 'x'){
        if(A== 'y' && B == 'y'){
            printf("corta a");
        }  else if(B=='y' && C=='y' && A == 'x'){
            printf("corta b");
        } else if(A=='y' && C=='y' && B=='x'){
            printf("corta a");
        } else if(A == 'x' || B == 'x'){
            printf("corta c");
        } else if(C == 'x' || D== 'x' || E == 'x' || F == 'x' ) {
            printf("corta b");
        }
    }

    if(A == 'x' && B == 'x' & C != 'x' && D!='x' && E!='x' && F!='x'){
        if(C != 'r' && D != 'r' && E != 'r' && F != 'r' ){
            printf("corta d");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta c");
        }
    } else if(A == 'x' && B != 'x' & C == 'x' && D!='x' && E!='x' && F!='x'){
        if(B != 'r' && D != 'r' && E != 'r' && F != 'r' ){
            printf("corta d");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta b");
        }
    } else if(A == 'x' && B != 'x' & C != 'x' && D =='x' && E!='x' && F!='x'){
        if(B != 'r' && C!= 'r' && E != 'r' && F != 'r' ){
            printf("corta c");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta b");
        }
    } else if(A == 'x' && B != 'x' & C != 'x' && D != 'x' && E =='x' && F!='x'){
        if(B != 'r' && C!= 'r' && D != 'r' && F != 'r' ){
            printf("corta c");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta b");
        }
    } else if(A == 'x' && B != 'x' & C != 'x' && D !='x' && E!='x' && F =='x'){
        if(B != 'r' && C!= 'r' && E != 'r' && D != 'r' ){
            printf("corta c");
        } else if(E == 'b'){
            printf("corta e");
        } else{
            printf("corta b");
        }
    } else if(A != 'x' && B == 'x' & C == 'x' && D != 'x' && E !='x' && F !='x'){
        if(A != 'r' && D != 'r' && E != 'r' && F != 'r' ){
            printf("corta d");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B == 'x' & C != 'x' && D == 'x' && E !='x' && F !='x'){
        if(A != 'r' && C != 'r' && E != 'r' && F != 'r' ){
            printf("corta c");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B == 'x' & C != 'x' && D != 'x' && E == 'x' && F !='x'){
        if(A != 'r' && C != 'r' && D != 'r' && F != 'r' ){
            printf("corta c");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B == 'x' & C != 'x' && D != 'x' && E != 'x' && F == 'x'){
        if(A != 'r' && C != 'r' && D != 'r' && E != 'r' ){
            printf("corta c");
        }else if(E == 'b'){
            printf("corta e");
        }else{
            printf("corta a");
        }


    } else if(A != 'x' && B != 'x' & C == 'x' && D == 'x' && E != 'x' && F != 'x'){
        if(A != 'r' && B != 'r' && E != 'r' && F != 'r' ){
            printf("corta b");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B != 'x' & C == 'x' && D != 'x' && E == 'x' && F != 'x'){
        if(A != 'r' && B != 'r' && D != 'r' && F != 'r' ){
            printf("corta b");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta a");
        }
    }  else if(A != 'x' && B != 'x' & C == 'x' && D != 'x' && E != 'x' && F == 'x'){
        if(A != 'r' && B != 'r' && D != 'r' && E != 'r' ){
            printf("corta b");
        } else if(E == 'b'){
            printf("corta e");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B != 'x' & C != 'x' && D == 'x' && E == 'x' && F != 'x'){
        if(A != 'r' && B != 'r' && C != 'r' && F != 'r' ){
            printf("corta b");
        } else if(F == 'b'){
            printf("corta f");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B != 'x' & C != 'x' && D == 'x' && E != 'x' && F == 'x'){
        if(A != 'r' && B != 'r' && C != 'r' && E != 'r' ){
            printf("corta b");
        } else if(E == 'b'){
            printf("corta e");
        } else{
            printf("corta a");
        }
    } else if(A != 'x' && B != 'x' & C != 'x' && D != 'x' && E == 'x' && F == 'x'){
        if(A != 'r' && B != 'r' && C != 'r' && D != 'r' ){
            printf("corta b");
        }else if(D == 'b'){
            printf("corta d");
        } else{
            printf("corta a");
        }
    }


	return 0;
}