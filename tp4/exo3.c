#include <stdlib.h>
#include <stdio.h>



union monInt
{
  int i;
  char c[4];
};




int main()
{
  char c[8];
  int i;
  printf("Quel est votre nombre\n");
  scanf("%d",&i);

  union monInt m;
  m.i = i;
  for(int j = 0; j < 4; j++)
    {
      int n = 0;
      int k = 0;
      for (int l = 0; l < 8;l++)
	{
      	    
	  if ((m.c[j] & 1<< l))
	    {
	      if(l <4)
		{
		  n += 1<<l;
		}
	      else
		{
		  k += 1<<(l-4);
		}
	    }
	}
      if(n < 10)
	{
	  c[8-1-j*2] = '0' + n;
	}
      else
	{
	  c[8-1-j*2] = 'a' + n-10;
	}
      if(k < 10)
	{
	   c[8-2-j*2] = '0' + k;
	}
      else
	{
	  c[8-2-j*2] = 'a' + k-10;
	}
    }

  printf("%s",c);
  printf("\n Il vaut %x en héxadécimal.\n",i);

  return 0;
}
