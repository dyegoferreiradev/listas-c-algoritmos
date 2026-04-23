#include <stdio.h>
#include <math.h>

int main(){

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    if(x > 0 && y > 0 && z > 0){
        if(z > y && y > x || y > z && z > x){
            printf("2");
        } else if(z>x && x>y || x>z && z>y){
            printf("4");
        } else{
            printf("5");
        }
    }

    if(x < 0 && y > 0 && z > 0){
        if(abs(x)< y && y < z || abs(x)<z && z < y){
            printf("1");
        } else if(y<abs(x) && abs(x)<z || y<z && z<abs(x)){
            printf("3");
        } else{
            printf("6");
        }

    }

    if(x < 0 && y < 0 && z > 0){
        if(abs(x)<abs(y) && abs(y)<z || abs(x)<z && z<abs(y)){
            printf("4");
        } else if(abs(y)<abs(x) && abs(x)<z || abs(y)<z && z<abs(x)){
            printf("2");
        } else{
            printf("7");
        }
    }

    if(x > 0 && y < 0 && z > 0){
        if(x<abs(y) && abs(y) < z || x < z && z < abs(y)){
            printf("3");
        } else if(abs(y)<x && x<z || abs(y)<z && z<x){
            printf("1");
        } else{
            printf("8");
        }
    }

    if(x > 0 && y > 0 && z < 0){
        if(x<y && y<abs(z) || x<abs(z) && abs(z)<y){
            printf("6");
        } else if(y<abs(z) && abs(z)<x || y<x && x<abs(z)){
            printf("8");
        } else{
            printf("1");
        }
    }

    if(x < 0 && y > 0 && z < 0){
       if(abs(x)<y && y<abs(z) || abs(x)<abs(z) && abs(z)<y){
        printf("5");
       } else if(y<abs(x) && abs(x)<abs(z) || y<abs(z) && abs(z)<abs(x)){
        printf("7");
       } else{
        printf("2");
       }
    }

    if(x < 0 && y < 0 && z < 0){
        if(abs(x)<abs(y) && abs(y)<abs(z) || abs(x)<abs(z) && abs(z)<abs(y)){
            printf("8");
        } else if(abs(y)<abs(x) && abs(x)<abs(z) || abs(y)<abs(z) && abs(z)<abs(x)){
            printf("6");
        } else{
            printf("3");
        }
    }

    if(x > 0 && y < 0 && z < 0){
        if(x<abs(y) && abs(y)<abs(z) || x<abs(z) && abs(z)<abs(y)){
            printf("7");
        } else if(abs(y)<x && x<abs(z) || abs(y)<abs(z) && abs(z)<x){
            printf("5");
        } else{
            printf("4");
        }
    }
    return 0;
}
