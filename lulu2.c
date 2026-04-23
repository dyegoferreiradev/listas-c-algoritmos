#include <stdio.h>
#include <stdlib.h>
int main (){
  
int N, qtdCanais;
  
 
scanf ("%d %d", &N, &qtdCanais);
  
 
int termoMaisProx = abs (N), canalProx = 0;
  
int passo = 1;
  
int soma = 0;
  
int valorMaisProxN = 0, valorSoma = 0;
  
 
for (int canal = 1; canal <= qtdCanais; canal++)
    
    {
      int soma = 0;
      
int primeiro, segundo;
      
scanf ("%d %d", &primeiro, &segundo);
      
 
int termoAtual, termoAnterior = primeiro;
      
int passoAtual = 1;
      
if ((N < primeiro || N > primeiro) && (N < segundo))
	
	{
	  
 
if (N < primeiro || N > primeiro)
	    
	    {
	      
valorMaisProxN = primeiro;
	    
}
	  
int disAtual = abs (N - primeiro);
	  
if (disAtual < termoMaisProx)
	    
	    {
	      
termoMaisProx = disAtual;
	      
canalProx = canal;
	      
passo = 1;
	      
valorSoma = primeiro;
	    
}
	
}
      
if (N == primeiro)
	
	{
	  
passo = 1;
	  
canalProx = canal;
	  
canal = 999999;
	
}
      
 
if (N > primeiro && N == segundo)
	
	{
	  
passo = 2;
	  
canalProx = canal;
	  
canal = 999999;
	
}
      
passoAtual++;
      
passoAtual++;
      
      do
	
	{
	  
termoAtual = primeiro + segundo;
	  
int disAtual = abs (N - termoAtual);
	  
 
 
if (disAtual < termoMaisProx)
	    
	    {
	      
termoMaisProx = disAtual;
	      
canalProx = canal;
	      
valorSoma = termoAtual;
	      
valorMaisProxN = termoAtual;
	      
passo = passoAtual;
	    
}
	  
 
termoAnterior = termoAtual;
	  
primeiro = segundo;
	  
segundo = termoAtual;
	  
passoAtual++;
	
}
      while (abs (segundo - N) <= abs (primeiro - N));
    
}
  
while (valorSoma != 0)
    
    {
      
soma += valorSoma % 10;
      
valorSoma = valorSoma / 10;
    
}
  
if (soma > 10)
    
printf
      ("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n",
       canalProx, passo);
  
  else
    
printf
      ("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n",
       canalProx, passo);
  
 
return 0;

}


