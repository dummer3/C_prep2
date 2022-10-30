#include<stdio.h>
#include<stdlib.h>



typedef struct maillon maillon ;

struct maillon
{
  maillon * maillonSuivant ;
  maillon * maillonPrecedent ;
  int valeur ;
};



struct Liste
{
  int nbr ;
  maillon * premierMaillon ;
  maillon * dernierMaillon;
};

  typedef struct Liste liste ;


liste  listeVide()
{
  liste a = {0,NULL,NULL};
  return a;
}

int longueurDeLaliste(liste l)
{
  return l.nbr;
}

void AjoutElementFin(liste * l,maillon * m)
{
  if(l->dernierMaillon !=NULL)
    {
  l->dernierMaillon->maillonSuivant = m;
    }
   m->maillonPrecedent = l->dernierMaillon;
  l->dernierMaillon = m;
  (l->nbr)++;
}

void AjoutElementDebut(liste * l,maillon * m)
{
  if(l->premierMaillon !=NULL)
    {
  l->premierMaillon->maillonPrecedent = m;
    }
   m->maillonSuivant = l->premierMaillon;
  l->premierMaillon = m;
  (l->nbr)++;
}

int ValeurFin(liste * l)
{
    return l->dernierMaillon->valeur;
}

int ValeurDebut(liste * l)
{
  return l->premierMaillon->valeur;
 
}





int main()
{
  liste list = listeVide();
  maillon m = {NULL,NULL,0};
  maillon m1 = {NULL,NULL,1};
  maillon m2 = {NULL,NULL,2};
  AjoutElementDebut(&list,&m1);
  AjoutElementDebut(&list,&m);
  AjoutElementFin(&list,&m2);
  printf("\n longueur de la liste %d",longueurDeLaliste(list));
    
  return 0;
}
