#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testMail(char * s)
{
  for (int i = 0; i < strlen(s);i++)
    {
      if (s[i] == '@')
	{
	  return 1;
	}
    }
  return 0;
}


void ajoutClient(char ** arg)
{
  FILE * f = fopen("baseClient.txt","a+");
  if(f == NULL)
    {
      perror("ERROR OUVERTURE DU FICHIER\n");
      exit(-1);
    }
  if(!testMail(arg[4]))
    {
      printf("ERROR EMAIL INVALIDE\n");
      exit(-1);
    }
  for (int i = 1;i<5;i++)
    {
      fputs(arg[i],f);
      fputc(' ',f);
      fputc(';',f);
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
  
  ajoutClient(argv);
  return 0;
}
