#include <stdio.h>

int main (){
  
 
float A, B, C;
  
int N;
  
scanf ("%f %f %d %f", &A, &B, &N, &C);
  
float vX = (B - A) / N;
  
float form = 0.0;
  
for (int i = 1; i <= N; i++)
    {
      
float x = A + i * vX;
      
form += x * x * vX;
  
} 
if (form > C)
    {
      
printf ("Maior\n");
    
}
  else if (form == C)
    {
      
printf ("Igual\n");
    
}
  else
    {
      
printf ("Menor\n");
    
}
  
 
return 0;

}
