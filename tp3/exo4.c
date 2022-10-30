#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


int moyenne(int nbr, ...)
{
  int resultat = 0;
  va_list  ensemble;
  va_start(ensemble,nbr);
  for (int i=0;i<nbr;i++)
    {
      resultat += va_arg(ensemble,int);
    }
  va_end(ensemble);
  resultat /= nbr;

  return resultat;
}


int main()
{
  printf("%d,%d,%d\n",moyenne(3,1,2,3),moyenne(4,5,10,15,20),moyenne(5,4,8,12,16,20));
  printf("%d,%d",moyenne(2,4.0,6.0),moyenne(10,2,4,8));

  return 0;
}

// Dans le cas ou le programme reçoit un float au lieu d'un int à un des résultats faux (sans doute core dumped) malgré le fait que le programme n'affiche aucune erreur lors de l'exécution ou lors de la compilation.
