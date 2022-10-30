#include <stdio.h>
#include <stdlib.h>

union b
{
  int i;
  char c[8];
};

int main()
{
  union b monUnion;
  char bitFaible = monUnion.c[0];

  monUnion.i = -10;
  if((bitFaible & 1) == 0)
    {
      printf("l'entier négatif est codé en C2 ou VAS\n");
      if((bitFaible & 1 << 2) == 0)
	{
	  printf("Plus précisément en C2\n");
	}
      else
	{
	  printf("Plus précisément en VAS\n");
	}
    }
  else
    {
      printf("l'entier négatif est codé en C1 \n");
    }

  
  return  0;

  
}
