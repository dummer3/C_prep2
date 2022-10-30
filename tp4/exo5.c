#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int affiche(int * tab,int taille)
{
  for (int i = 0; i < taille;i++)
    {
      printf("|%d|",tab[i]);
    }
  printf("\n-------------------------------------------\n");
}

int comp1(int a, int b)
{
  return (a<b)?1:0;
}
int comp2(int a, int b)
{
  return (a>b)?1:0;
}
int comp3(int a, int b)
{
  return ((!(a%2) && b%2) || (a>b && a%2 == b%2))?1:0;
}

int comp4(int a, int b)
{
  return (a%10 <= b%10)?1:0;
}






int comp(int a,int b, int (* comp)(int,int))
{
  return comp(a,b);
}


void tri(int * tab,int taille,int (* comp)(int a,int b))
{
  int i,m,tempo;
  for(i = 0; i <taille; i++)
    {
      for(m = i; m <taille;m++)
	{
	  if(comp(tab[i],tab[m]))
	    {
	      tempo = tab[i];
	      tab[i] = tab[m];
	      tab[m] = tempo;
	    }
	}
    }
}

int main()
{
  srand(time(NULL));
  
  int tab[25];
  for (int i = 0; i<25; i++)
    {
      tab[i] = rand()%100;
    }
  affiche(tab,25);
  tri(tab,25,&comp1);
  affiche(tab,25);
  tri(tab,25,&comp2);
  affiche(tab,25);
  tri(tab,25,&comp3);
  affiche(tab,25);
  tri(tab,25,&comp4);
  affiche(tab,25);


  return 0;
}

