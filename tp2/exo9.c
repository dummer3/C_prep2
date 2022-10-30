#include<stdio.h>
#include<stdlib.h>

int main (int argc, char * argv[])
{
  int taille;
  FILE * f = fopen(argv[1],"r");
  fseek(f,8,SEEK_SET);
  fscanf(f,"%d",&taille);
  int * tab = malloc(sizeof(int)*taille);
  fseek(f,2,SEEK_CUR);
  for(int i = 0; i<taille;i++)
    {
      fscanf(f,"%d",&tab[i]);
        printf("|%d|",tab[i]);
    }
  fclose(f);
  
  return 0;
}
