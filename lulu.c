#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int A, C, M, qma, qmc, sobra_a, sobra_c, sobras;


    scanf("%d %d %d", &A, &C, &M);

    qma = A/M;
    qmc = C/M;
    sobra_a = A%M;
    sobra_c = C%M;
    sobras = sobra_a + sobra_c;


    if(sobra_a == 0 && sobra_c == 0){
        printf("%d mesas com adultos: R$%d\n", qma, 3*A);
        printf("%d mesas com criancas: R$%d\n", qmc, 2*C);

    }

    if(sobra_a != 0 && sobra_c == 0){
            if(sobra_a%2 != 0){
                if(sobra_a<4){
                    printf("%d mesas com adultos: R$%d\n", qma-sobra_a, 3*M*(qma-sobra_a));
                    printf("%d mesas com adultos+1: R$%d\n", sobra_a, 4*(M+1)*sobra_a);
                    printf("%d mesas com criancas: R$%d\n", qmc, 2*C);
                } else if(sobra_a >= 5){
                     printf("%d mesas com adultos: R$%d\n", qma+1, 3*M*(qma+1));
                     printf("%d mesas com criancas: R$%d\n", qmc, 2*C);

                }
            } else{
                if(sobra_a == 2 || sobra_a >= 4){
                    printf("%d mesas com adultos: R$%d\n", qma, 3*(A-sobra_a));
                    printf("%d mesas com criancas: R$%d\n", qmc, 2*C);
                    printf("%d mesas mistas: R$%d\n",1,2*M);
                }

            }


    }


    if(sobra_a == 0 && sobra_c != 0){
            if(sobra_c%2 != 0){
                    if(sobra_c<4){
                            printf("%d mesas com adultos: R$%d\n", qma, 3*A);
                            printf("%d mesas com criancas: R$%d\n", qmc-sobra_c, 2*M*(qmc - sobra_c));
                            printf("%d mesas com criancas+1: R$%d\n", sobra_c, 3*(M+1)*sobra_c );

                    } else if(sobra_c>4){
                        printf("%d mesas com adultos: R$%d\n", qma, 3*A);
                        printf("%d mesas com criancas: R$%d\n",qmc+1,M*(qmc+1)*2);
                    }

            } else{
                 if(sobra_c == 2 || sobra_c >= 4){
                    printf("%d mesas com adultos: R$%d\n", qma, 3*A);
                    printf("%d mesas com criancas: R$%d\n", qmc, 2*(C-sobra_c));
                    printf("%d mesas mistas: R$%d\n",1,2*M);
                }



            }


    }

    if(sobra_a != 0 && sobra_c != 0){
        if(sobras == M){
                printf("%d mesas com adultos: R$%d\n", qma,qma*M*3);
                printf("%d mesas com criancas: R$%d\n",qmc,qmc*M*2);
                printf("%d mesas mistas: R$%d\n",1,2*M);

        } else if(sobra_a%2 == 0 && sobra_c%2 == 0){
            if(sobras > M){
                printf("%d mesas com adultos: R$%d\n", qma,qma*M*3);
                printf("%d mesas com criancas: R$%d\n",qmc,qmc*M*2);
                printf("%d mesas mistas: R$%d\n",2,2*2*M);
            } else if(sobras < M){
                printf("%d mesas com adultos: R$%d\n", qma,qma*M*3);
                printf("%d mesas com criancas: R$%d\n",qmc,qmc*M*2);
                printf("%d mesas mistas: R$%d\n",1,2*M);
            }

        }else if(sobra_a%2 != 0 && sobra_c%2 != 0){
            if(sobra_a < 5 && sobra_c < 5){
                printf("%d mesas com adultos: R$%d\n",qma-sobra_a,3*M*(qma-sobra_a));
                printf("%d mesas com adultos+1: R$%d\n",sobra_a,4*(M+1)*(sobra_a));
                printf("%d mesas com criancas: R$%d\n",qmc-sobra_c,2*(M)*(qmc-sobra_c));
                printf("%d mesas com criancas+1: R$%d\n",sobra_c,3*(M+1)*sobra_c);
            } else if(sobra_a >= 5 && sobra_c >=5){
                printf("%d mesas com adultos: R$%d\n",qma+1,3*M*(qma+1));
                printf("%d mesas com criancas: R$%d\n",qmc+1,2*M*(qmc+1));
            } else if(sobra_a >=5 && sobra_c < 5){
                printf("%d mesas com adultos: R$%d\n",qma+1,3*M*(qma+1));
                printf("%d mesas com criancas: R$%d\n",qmc-sobra_c,2*(M)*(qmc-sobra_c));
                printf("%d mesas com criancas+1: R$%d\n",sobra_c,3*(M+1)*sobra_c);
            } else if(sobra_a < 5 && sobra_c >= 5){
                printf("%d mesas com adultos: R$%d\n",qma-sobra_a,3*M*(qma-sobra_a));
                printf("%d mesas com adultos+1: R$%d\n",sobra_a,4*(M+1)*(sobra_a));
                printf("%d mesas com criancas: R$%d\n",qmc+1,2*M*(qmc+1));
            }
        } else if(sobra_a%2 != 0 && sobra_c%2 == 0){
             if(sobra_a >= 5 && sobra_c >= 4){
                printf("%d mesas com adultos: R$%d\n",qma+1,3*M*(qma+1));
                printf("%d mesas com criancas: R$%d\n",qmc+1,2*M*(qmc+1));

        } else if(sobra_a >=5 && sobra_c < 4){
             printf("%d mesas com adultos: R$%d\n",qma+1,3*M*(qma+1));
             printf("%d mesas com criancas: R$%d\n",qmc-sobra_c,2*(M)*(qmc-sobra_c));
             printf("%d mesas com criancas+1: R$%d\n",sobra_c,3*(M+1)*sobra_c);
        } else if(sobra_a < 5 && sobra_c < 4){
              printf("%d mesas com adultos: R$%d\n",qma-sobra_a,3*M*(qma-sobra_a));
              printf("%d mesas com adultos+1: R$%d\n",sobra_a,4*(M+1)*(sobra_a));
              printf("%d mesas com criancas: R$%d\n",qmc-sobra_c,2*(M)*(qmc-sobra_c));
              printf("%d mesas com criancas+1: R$%d\n",sobra_c,3*(M+1)*sobra_c);
        } else if(sobra_a < 5 && sobra_c >= 4){
            printf("%d mesas com adultos: R$%d\n",qma-sobra_a,3*M*(qma-sobra_a));
            printf("%d mesas com adultos+1: R$%d\n",sobra_a,4*(M+1)*(sobra_a));
           printf("%d mesas com criancas: R$%d\n",qmc+1,2*M*(qmc+1));
        }

    } else if(sobra_a%2 == 0 && sobra_c%2 !=0){
        if(sobra_a >= 4 && sobra_c >=5){
             printf("%d mesas com adultos: R$%d\n",qma+1,3*M*(qma+1));
             printf("%d mesas com criancas: R$%d\n",qmc+1,2*M*(qmc+1));
        } else if(sobra_a >= 4 && sobra_c < 5){
             printf("%d mesas com adultos: R$%d\n",qma+1,3*M*(qma+1));
             printf("%d mesas com criancas: R$%d\n",qmc-sobra_c,2*(M)*(qmc-sobra_c));
             printf("%d mesas com criancas+1: R$%d\n",sobra_c,3*(M+1)*sobra_c);
        } else if(sobra_a < 4 && sobra_c < 5){
              printf("%d mesas com adultos: R$%d\n",qma-sobra_a,3*M*(qma-sobra_a));
              printf("%d mesas com adultos+1: R$%d\n",sobra_a,4*(M+1)*(sobra_a));
              printf("%d mesas com criancas: R$%d\n",qmc-sobra_c,2*(M)*(qmc-sobra_c));
              printf("%d mesas com criancas+1: R$%d\n",sobra_c,3*(M+1)*sobra_c);
        } else if(sobra_a < 4 && sobra_c >= 5){
             printf("%d mesas com adultos: R$%d\n",qma-sobra_a,3*M*(qma-sobra_a));
              printf("%d mesas com adultos+1: R$%d\n",sobra_a,4*(M+1)*(sobra_a));
               printf("%d mesas com criancas: R$%d\n",qmc+1,2*M*(qmc+1));
        }

    }


    }



	return 0;
}