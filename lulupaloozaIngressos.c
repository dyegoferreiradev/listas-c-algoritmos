#include <stdio.h>
#include <stdlib.h>

int main (){
  
 
int X, N;
  
int vip, soma;
  
 
scanf ("%i %i", &X, &N);
  
 
int sequencia;
  
int melhorCanal = 1, melhorMin = 0, distanciaMenor = __INT_MAX__, vipGanho = 0;
  
 
soma = 0;
  
 
for (vip = X; vip > 0; vip /= 10)
    {
      
soma += vip % 10;
    
}
  
 
if (soma > 10)
    {
      
vipGanho = 1;
    
}
  else
    vipGanho = 0;
  
 
 
 
for (int i = 0; i < N; i++)
    {
      
int a, b;
      
 
scanf ("%d %d", &a, &b);
      
 
 
for (int j = 1; j <= 2 * X; j++)
	{
	  
sequencia = a + b;
	  
 
int distancia_atual = abs (X - sequencia);
	  
 
if (distancia_atual < distanciaMenor)
	    {
	      
distanciaMenor = distancia_atual;
	      
 
melhorCanal = i + 1;
	      
melhorMin = j + 2;
	    
}
	  
 
a = b;
	  
b = sequencia;
	
 
}
    
 
}
  
 
if (vipGanho == 1)
    
printf
      ("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n",
       melhorCanal, melhorMin);
  
  else
    
printf
      ("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :( \n",
       melhorCanal, melhorMin);
  
 
return 0;

}
