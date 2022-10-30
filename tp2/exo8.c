#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int * tab = malloc(sizeof(int)*argc);
  for(int i = 2; i < argc;i++)
    {
      tab[i-2] = atoi(argv[i]);
      
    }

  FILE * f = fopen(argv[1],"w+");
  char * c = malloc(sizeof(char)*18);  
  snprintf(c, sizeof(char)*14, "list : [%d] ", argc-2);
  fputs(c,f);
  for (int i = 0; i < argc-2;i++)
    {
      sprintf(c, "%d ", tab[i]);
      fputs(c,f);
    }
  fclose(f);
  return 0;
}
