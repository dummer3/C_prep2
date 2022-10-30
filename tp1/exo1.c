#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"string.h"

void AfficheTab(int * tab, unsigned int taille)
{
  if (tab != NULL)
    {
      for(int i = 0; i < taille;i++)
	{
	  printf("%d,",tab[i]);
	}
    }
}

int * monMalloc(unsigned int n)
{
  int * tab = malloc(sizeof(int)*n);
  tab[0] = 1;
  tab[1] = 1;
  for (int i = 2; i < n;i++)
    {
      tab[i] = tab[i-1]+tab[i-2];
    }
  return tab;
}

void taille()
{
  printf("Taille de int : %lu \n Taille de int* : %lu \n Taille de void : %lu \n Taille de void * : %lu \n Taille de long int : %lu \n Taille de long int * : %lu \n Taille de char : %lu \n",sizeof(int),sizeof(int*),sizeof(void),sizeof(void *),sizeof(long int),sizeof(long int *),sizeof(char));
}

int exo5(int * tab,unsigned int n)
{
  for(int i = 0; i < n; i++)
    {
      if (tab[i] < 0 || tab[i] > n-1)
	{
	  return 0;
	}
      for(int j = i+1; j < n; j++)
	{
	  if(tab[i] == tab[j])
	    {
	      return 0;
	    }
	}
    }
  return 1;
}

int verificationExo6(int * tab, int valeur,int tailleActuelle)
{
  for (int i = 0; i <tailleActuelle;i++)
    {
      if(tab[i] == valeur)
	{
	  return 1;
	}
    }
  return 0;
}

int * exo6 (unsigned int taille)
{
  int * tab = malloc(sizeof(int)*taille);
  int alea;
  for(int i = 0; i< taille ;i++)
    {
      do
	alea = rand()%taille;
      while(verificationExo6(tab,alea,i));
      tab[i] = alea;
    }
  return tab;
}

void exo7(char * T, int * tab, unsigned int taille)
{
 
  for (int i = 0; i < taille; i++)
    {
      char s = T[i];
      T[i] = T[tab[i]];
      T[tab[i]] = s;

      for( int j = 0; j <taille;j++)
	{
	  if(tab[j] == i)
	    {
	      tab[j] = tab[i];
	    }
	}
    }
  
}

float ** exo8 (unsigned int n, unsigned int m)
{
  float ** tab2D = malloc(sizeof(float*)*n);
  for (int i = 0; i < n; i++)
    {
      tab2D[i] = malloc(sizeof(float) * m);
      if(tab2D[i] == NULL){printf("ERROR");}
    }
  return tab2D;
}

void exo9IN(float ** tab,unsigned int n, unsigned int m)
{
  for(int i = 0; i<n;i++)
    {
      for(int j = 0;j<m;j++)
	{
	  printf("Entree pour la case[%d][%d]\n",i,j);
	  scanf("%f",&tab[i][j]);
	}
    }
}

void exo9OUT(float ** tab,unsigned int n, unsigned int m)
{
  for(int i = 0; i<n;i++)
    {
      for(int j = 0;j<m;j++)
	{
	  printf("|%.2f|",tab[i][j]);
	}
      printf("\n");
    }
}

void exo10(float ** tab,unsigned int n,unsigned int m)
{
  float ** tempo = exo8(m,n);
  for (int i = 0; i<n;i++)
    {
      for(int j = 0; j<m;j++)
	{
	  tempo[j][i] = tab[n-1-i][j];
	}
    }
  free(tab);
  memcpy(tab,tempo,sizeof(float)*n*m);
}

void exo11(float ** tab,int n)
{
  for (int i = 0; i < n; i++)
    {
      free(tab[i]);
      tab[i] = NULL;
    }
  free(tab);
  tab = NULL;

}

float ** exo12(int n)
{
  float ** tab = exo8(n,n);
  
  for(int i = 0; i < n; i ++)
    {
      tab[i][0] = 1;
     
      for (int j = 1; j < n;j++)
	{

	  if(j<i)
	    {
	      tab[i][j] = tab[i-1][j] + tab [i-1][j-1];
	    }
	  else if(j == i)
	    {
	      tab[i][j] = 1;
	    }
	  else
	    {
	      tab[i][j] = 0;  
	    }
	}
    }
  return tab;
}

int main()
{
  srand(time(NULL));
  int * tab = monMalloc(5);
  
  AfficheTab(tab,5);
  printf("\n Le résultat est : %u",exo5(tab,5));
  free(tab);
  taille();


  void * Z = malloc(10*4);
  int * X = Z ;
  AfficheTab(X,10);
  AfficheTab((int *)((char *)X+8),8);
  free(X);
  tab = exo6(7);
  AfficheTab(tab,7);
  printf("Le résultat est : %u",exo5(tab,7));

  char c[7] = "Bonjour";
  exo7(c,tab,7);
  printf("\n %s \n",c);

  float ** tab2D = exo8(2,3);
  exo9IN(tab2D,2,3);
  exo9OUT(tab2D,2,3);
  exo10(tab2D,2,3);
  exo9OUT(tab2D,3,2);
  exo11(tab2D,3);
  
  float ** ok = exo12(5);
  exo9OUT(ok,5,5);
  printf("%p,%p",ok[0],ok[4]);

  
  return 0;
}
