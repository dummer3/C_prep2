#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include<ctype.h>

int POLONAIS(char * c, int  * d)
{
  int resultat;
  int premier = 0;
  char operation = c[*d];
  int nbr;

  while(c[*d] != ')')
    {
      printf("[%c],[%d]\n",c[*d],*d);
      if(isdigit(c[*d]))
	{
	  
	  sscanf(c + *d,"%d",&nbr);
	  while(isdigit(c[*d +1]))
	    {
	      
	      (*d)++;
	    }
	
	  if(premier == 0)
	    {
	      if(operation == '-')
		{
		  resultat = -nbr;
		}
	      else
		{
	      resultat = nbr;
		}
	      premier++;
	    }
	  else
	    {
	      if(operation == '*')
		{
		  resultat *= nbr;
		}
	      else if(operation == '+')
		{
		  resultat += nbr;
		}
	      else if(operation == '-')
		{
		  resultat -= nbr;
		}
	      else if(operation == '/')
		{
		  resultat /= nbr;
		}
	      else
		{
		  printf("ERROR\n");
		  return 0;
		}
	    }
	}
 
      else if(c[*d] == '(')
	{
	  printf("NOUVEAU POLONAIS \n");
	  (*d)++;
	  if(operation = '*')
	    {
	      resultat *= POLONAIS(c,d);
	    }
	  else if(operation = '+')
	    {
	      resultat += POLONAIS(c,d);
	    }
	  else if(operation = '-')
	    {
	      resultat -= POLONAIS(c,d);
	    }
	  else if(operation = '/')
	    {
	      resultat /= POLONAIS(c,d);
	    }
	  else
	    {
	      printf("ERROR\n");
	      return 0;
	    }
	
	    }    
      (*d)++;
    }
  printf("FIN POLONAIS avec resultat = %d\n",resultat);
  return resultat;
}

int main()
{
  char c[1000];
  printf("Le calcul est ?");
  fgets(c,999,stdin);
  printf("%s\n",c);
  int pos = 1;
  printf("%d",POLONAIS(c,&pos));
 
  return 0;
}
