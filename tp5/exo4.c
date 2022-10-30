#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE * f = fopen(argv[1],"r");
  char ** tab = malloc(sizeof(char*)*10);
  for (int i = 0; i < 10;i++)
    {
      tab[i] = malloc(11);
      fscanf(f,"%s",tab[i]);
      printf("%s\n",tab[i]);
    }
  



  fclose(f);
  return 0;
}
