#include <stdio.h>

int main (){

    int i=1, x=1, nRodadas, A, divA=0, rA, B, divB=0, rB, vitA=0, vitB=0; // primo=1, par=2, impar=3, n=numero, div=divisor, r=resultado, vit=vitoria
    
    scanf("%d", &nRodadas);

    do{
        
        scanf("%d %d", &A, &B);

        while(i <= A){
            if(A % i == 0) {
            divA +=1 ;
            }
            i+=1;
        }

        if(divA==2){
            rA=1;
        }
        else if(A%2==0){
            rA=2;
        }
        else if(A%2==1){
            rA=3;
        }

        while(x <= B){
            if(B % x == 0) {
            divB +=1 ;
            }
            x+=1;
        }

        if(divB==2){
            rB=1;
        }
        else if(B%2==0){
            rB=2;
        }
        else if(B%2==1){
            rB=3;
        }
        
        nRodadas = nRodadas-1;

        if(rA==2 && rB==3 || rA==1 && rB==2 || rA==3 && rB==1){
            vitA=(vitA+1);
        }
        else if(rB==2 && rA==3 || rB==1 && rA==2 || rB==3 && rA==1){
            vitB=(vitB+1);
        }else{
            vitB = vitB + 0;
            vitA = vitA + 0;
        }
        

    }while(nRodadas>0);

        
    if(vitA>vitB){
        printf("Sapo sopa esta de boa na lagoa!");
    }
    else if(vitB>vitA){
        printf("Testemunhe a verdadeira forca!");
    }else{
        printf("Impending doom approaches...");
    }


    

    return 0;
    
}