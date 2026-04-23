#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int lim_vel, vel_min;
    float distancia, tempo_kwid, tempo_tesla, tempo_gol, vel_kwid, vel_tesla, vel_gol;
    scanf("%d %f", &lim_vel, &distancia);
    scanf("%f", &tempo_kwid);
    scanf("%f", &tempo_tesla);
    scanf("%f", &tempo_gol);

    vel_min = lim_vel/2;
    vel_kwid = distancia/tempo_kwid;
    vel_tesla = distancia/tempo_tesla;
    vel_gol = distancia/tempo_gol;


    if( (lim_vel>=vel_kwid && vel_kwid>=vel_min) && (lim_vel>=vel_tesla && vel_tesla>=vel_min) && (lim_vel>=vel_gol && vel_gol>=vel_min) ){

                if(vel_kwid >= vel_tesla && vel_tesla >= vel_gol){
                    printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
                    printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
                    printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f", vel_gol);
                } else if(vel_kwid >= vel_gol && vel_gol >= vel_tesla){
                    printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
                    printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
                    printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f", vel_tesla);
                } else if(vel_tesla >= vel_kwid && vel_kwid >= vel_gol){
                    printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
                    printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
                    printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f", vel_gol);
                } else if(vel_tesla >= vel_gol && vel_gol>= vel_kwid){
                    printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
                    printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
                    printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f", vel_kwid);
                } else if(vel_gol >= vel_tesla && vel_tesla >= vel_kwid){
                    printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
                    printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
                    printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f", vel_kwid);
                } else {
                    printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
                    printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
                    printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f", vel_tesla);
                }
    }

    if(vel_gol >= vel_min && vel_gol <= lim_vel && (vel_kwid<vel_min || vel_kwid > lim_vel ) && (vel_tesla<vel_min || vel_tesla > lim_vel)){
        printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f \n", vel_gol);
    } else if(vel_tesla >= vel_min && vel_tesla <= lim_vel && (vel_kwid<vel_min || vel_kwid > lim_vel ) && (vel_gol<vel_min || vel_gol > lim_vel)){
        printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f \n", vel_tesla);
    } else if(vel_kwid >= vel_min && vel_kwid <= lim_vel && (vel_tesla<vel_min || vel_tesla > lim_vel ) && (vel_gol<vel_min || vel_gol > lim_vel)){
        printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f \n", vel_kwid);
    }

    if((vel_kwid >= vel_min && vel_kwid <= lim_vel) && (vel_tesla >= vel_min && vel_tesla <= lim_vel) && (vel_gol > lim_vel || vel_gol < vel_min)){
        if(vel_kwid>=vel_tesla){
          printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
          printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
        } else{
          printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
          printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
        }
    } else if((vel_tesla >= vel_min && vel_tesla <= lim_vel) && (vel_gol >= vel_min && vel_gol <= lim_vel) && (vel_kwid > lim_vel || vel_kwid < vel_min)){
         if(vel_tesla>=vel_gol){
          printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
          printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
        } else{
          printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
          printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", vel_tesla);
        }
    } else if((vel_kwid >= vel_min && vel_kwid <= lim_vel) && (vel_gol >= vel_min && vel_gol <= lim_vel) && (vel_tesla > lim_vel || vel_tesla < vel_min)){
         if(vel_kwid>=vel_gol){
          printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
          printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
         } else{
          printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", vel_gol);
          printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", vel_kwid);
         }
    }
    
    if((vel_gol < vel_min || vel_gol > lim_vel) && (vel_kwid < vel_min || vel_kwid > lim_vel ) && (vel_tesla<vel_min || vel_tesla > lim_vel)){
        printf("Infelizmente Xupenio nao podera ir ao evento mais importante do ano");
    }
	return 0;
}