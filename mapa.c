#include <stdio.h>

int main (){

  char direcao;
  int d, e, f;
  int cont, cont2 = 1, contf, contf2 = 0, conte = 0, conte2, contd, contd2;


  while (direcao != 'x')
    {
      scanf (" %c", &direcao);
      while (cont2 == 1)
	{
	  cont = 20;
	  cont2--;
	}

      if (direcao == 'd')
	{
	  scanf ("%d", &d);
	  contd = cont;
	  contd += (d * 2);

	  printf (".");
	  while (cont > 0)
	    {
	      printf (" ");
	      cont--;
	    }

	  while (d > 0)
	    {
	      if (d > 1)
		printf ("->");
	      else if (d == 1)
		printf ("->\n");
	      d--;
	    }

	  cont = contd;
	}




      if (direcao == 'e')
	{
	  scanf ("%d", &e);

	  cont -= (e * 2);
	  conte = cont;


	  printf (".");
	  while (cont > 0)
	    {
	      printf (" ");
	      cont--;
	    }

	  while (e > 0)
	    {
	      if (e > 1)
		printf ("<-");
	      else if (e == 1)
		printf ("<-\n");
	      e--;
	    }

	  cont = conte;
	}




      if (direcao == 'f')
	{
	  scanf ("%d", &f);

	  while (f > 0)
	    {
	      contf = cont;

	      printf (".");
	      while (contf > 0)
		{
		  printf (" ");
		  contf--;
		}
	      if (f > 1)
		{
		  printf ("|\n");
		}
	      else if (f == 1)
		printf ("|\n");
	      f--;
	      contf = cont;
	    }
	}

    }

  printf (".");
  while (cont > 0)
    {
      printf (" ");
      cont--;
    }
  printf ("x");

  return 0;

}
