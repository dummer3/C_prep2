#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union decoupeTrois
{
  char decoupe[6];
  char s[3][2];
} un;


int main(int argc,char * argv[])
{
  if(argc < 2)
    {
      printf("ERROR PAS DE NOMBRE DONNE EN ARGUMENT.\n");
      exit(-1);
    }
  if(strlen(argv[1]) != 6)
    {
      printf("ERROR NOMBRE NON CONFORME.\n");
      exit(-1);
    }
  
  un nbr;
  sscanf(argv[1],"%s",nbr.decoupe);
  int a,b,c;
  sscanf(nbr.s[0],"%d",&a);
  sscanf(nbr.s[1],"%d",&b);
  sscanf(nbr.s[2],"%d",&c);
  
  a -= b;
  b -=c;
  a/=10000;
  b/=100;
  printf("%d,%d,%d\n",a,b,c);
  
  if (a<50 && b<50 && c<50)
    {
      printf("le nombre %s correspond à %d en base 10.\n",nbr.decoupe,50*(50*a+b)+c);
    }
  else
    {
      printf("ERROR PAS EN BASE 50.\n");
      exit(-1);
    }
  
  return 0;
}
