#include<stdio.h>
#include<stdlib.h>

typedef struct Arbre arbre;
typedef struct SousArbre sousArbre;
struct Arbre
{
int  * valeur ;
struct SousArbre * sa ;
} ;


struct SousArbre
{
struct Arbre * sag ;
  struct Arbre * sad ;
} ;

void ajouterElement(arbre * a, int * nouvelleValeur )
{

  if (a->sa != NULL)
    {
      if(*(a->valeur) > *(nouvelleValeur))
	{
	   
	  if(a->sa->sag != NULL)
	    {
	      ajouterElement(a->sa->sag,nouvelleValeur);
	    }
	  else
	    {
	      arbre b = {nouvelleValeur,NULL};
	      a->sa->sag = &b;
	    }
	    
	}
      else
	{
	 
	  if(a->sa->sad != NULL)
	    {
	      ajouterElement(a->sa->sad,nouvelleValeur);
	    }
	  else
	    {
	      arbre b = {nouvelleValeur,NULL};
	      a->sa->sad = &b;
	    }
	}
    }
  else
    {
      sousArbre sab = {NULL,NULL};
      a->sa = &sab;
      arbre b = {nouvelleValeur,NULL};
      if(*(a->valeur) < *(nouvelleValeur))
	{
	  a->sa->sad = &b;
	}
      else
	{
	  a->sa->sag = &b;
	}

    }
}

int compteElement(arbre * a)
{
  int compt = 1;
  return compt;
}

int main()
{
  int * a = malloc(4);
  int * b= malloc(4);
  int * c= malloc(4);
  *a = 25;
  *b = 75;
  *c = 50;
  arbre racine = {c,NULL};
 
  ajouterElement(&racine,a);
  ajouterElement(&racine,b);
   if(racine.sa->sag != NULL)
    {
      printf("sag : %d",*((&racine)->sa->sag->valeur));
    }
   if(racine.sa->sad != NULL)
    {
      printf("sad : %d",*((&racine)->sa->sad->valeur));
    }


  //  compteElement(&racine);
   


  return 0;
}
