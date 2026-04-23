#include <stdio.h>

int main (){
  
int n;
scanf ("%d", &n);
  
 
if (n < 1 || n > 300)
    {
      
return 1;
    
}
  
 
double soma = 0.0;
int cont = 0;
int primo = 2;
  
 
while (cont < n)
    {
      
 
int fprimo = 1;
      
if (primo <= 1)
	{
	  
fprimo = 0;
	
}
      else if (primo <= 3)
	{
	  
fprimo = 1;
	
}
      else if (primo % 2 == 0 || primo % 3 == 0)
	{
	  
fprimo = 0;
	
}
      else
	{
	  
for (int i = 5; i * i <= primo; i += 6)
	    {
	      
if (primo % i == 0 || primo % (i + 2) == 0)
		{
		  
fprimo = 0;
		  
break;
		
}
	    
}
	
}
      
 
 
int fprimo2 = 1;
int primo2 = primo + 2;
      
 
if (primo2 <= 1)
	{
	  
fprimo2 = 0;
	
}
      else if (primo2 <= 3)
	{
	  
fprimo2 = 1;
	
}
      else if (primo2 % 2 == 0 || primo2 % 3 == 0)
	{
	  
fprimo2 = 0;
	
}
      else
	{
	  
for (int i = 5; i * i <= primo2; i += 6)
	    {
	      
if (primo2 % i == 0 || primo2 % (i + 2) == 0)
		{
		  
fprimo2 = 0;
		  
break;
		
}
	    
}
	
}
      
 
 
if (fprimo && fprimo2)
	{
	  
soma += (1.0 / primo + 1.0 / primo2);
	  
cont++;
	
}
      
 
primo++;
    
}
  
 
printf ("%.10lf\n", soma);
  
return 0;

}
