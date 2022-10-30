#include <stdio.h>
#include <stdlib.h>

void Affiche1(int * T,int n)
{
  for(int i = 0; i<n;i+=2)
    {
      printf("|%d|",T[i]);
    }
  
    for(int i = 1; i<n;i+=2)
    {
      printf("|%d|",T[i]);
    }    
  printf("\n");
}

void Affiche2(int * T,int n)
{
  for(int i = 0; i<n;i++)
    {
      if(i%2 == 0)
	{
	  printf("|%d|",T[i/2]);
	}
      else
	{
	  printf("|%d|",T[n-i/2-1]);
	}
    }
  printf("\n");
}
void AfficheNULL(int * T,int n)
{
  for(int i = n-1; i>=0;i--)
    {
      printf("|%d|",T[i]);	
    }
  printf("\n");
}

void AfficheTab(int * T,int n,void (* fonc)(int *,int))
{
  if (fonc == NULL)
    {
      AfficheNULL(T,n);
    }
  else
    {
      fonc(T,n);
    }
}

int main()
{
  int tab[6] = {0,1,2,3,4,5};
  
  AfficheTab(tab,6,&Affiche1);
  AfficheTab(tab,6,&Affiche2);
  AfficheTab(tab,6,&AfficheNULL);
  AfficheTab(tab,6,NULL);

  printf("-------------------\n");
  
  int tab2[5] = {0,-1,-2,-3,-4};
  
  AfficheTab(tab2,5,&Affiche1);
  AfficheTab(tab2,5,&Affiche2);
  AfficheTab(tab2,5,&AfficheNULL);
  AfficheTab(tab2,5,NULL);
  
  return 0;
}
