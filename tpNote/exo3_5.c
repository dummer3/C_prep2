#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ajoutClient2(char ** arg)
{
  FILE * f = fopen("baseClient.txt","a+");
   if(f == NULL)
    {
      printf("ERROR OUVERTURE FICHIER");
      exit(-1);
    }

  if(!strcmp(arg[1],"?"))
    {
      printf("ERROR le prenom doit être fourni");
      exit(-1);
    }
  if(!strcmp(arg[2],"?"))
    {
      printf("ERROR le nom doit être fourni");
      exit(-1);
    }
  for (int i = 1;i<3;i++)
    {
	  fputs(arg[i],f);
	  fputc(' ',f);
	  fputc(';',f);
    }
  
  for (int i = 3;i<5;i++)
    {
      if(strcmp(arg[i],"?"))
	{
	  fputs(arg[i],f);
	  fputc(' ',f);
	  fputc(';',f);
	}
      else
	{
	  fputs("NONE",f);
	  fputc(' ',f);
	  fputc(';',f);
	}
    }
  fputc('0',f);
  fputc('\n',f);
}


    int main(int argc, char *argv[])
{
  if (argc <= 4)
    {
      printf("ERROR pas assez d'arguments\n");
      exit(-1);
    }
  
  ajoutClient2(argv);
  return 0;
}
