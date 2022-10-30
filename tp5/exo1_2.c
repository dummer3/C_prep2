#include <stdio.h>
#include <stdlib.h>

#define S 10

int * methode1(int s)
{
  int * t = malloc(sizeof(int)*s);
  for (int i = 0; i<s;i++)
    {
      t[i] = i;
    }
   return t;
}

int * methode2(int s)
{
  int * t = malloc(sizeof(int)*s);
  for (int i = 0; i<s;i++)
    {
      if(i < s/2)
	{
	  t[i] = 2*i;
	}
      else
	{
	  t[i] = 2*(i-s/2)+1;
	}
    }
  return t;
}

int * methode3(int s)
{
  int * t = malloc(sizeof(int)*s);
  for (int i = 0; i<s;i++)
    {
      if(i%2)
	{
	  t[i] = s-i/2-1;
	}
      else
	{
	  t[i] = i/2;
	}
    }
  return t;
}




void affichage(int * T,int s,int * (* methode)(int))
{
  int * tab;
  if(methode != NULL)
    {
    tab = methode(s);
    }
  else
    {
      for(int i = 0; i < s; i++)
	{
	  tab[i] = s-i-1;
	}
    }
  for(int i = 0; i < s;i++)
    {
      printf("|%d|",T[tab[i]]);
    }
  printf("\n---------------------------------------\n");
  free(tab);
}

int main()
{
  int * T = malloc(sizeof(int)*S);
  for (int i = 0;i<S;i++)
    {
      T[i] = i;
    }
  
  affichage(T,S,&methode1);
  affichage(T,S,&methode2);
  affichage(T,S,&methode3);
  affichage(T,S,NULL);

  
  return 0;
}
