#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectClient(char * info,char * crit)
{
  int i = 0;
  char ligne[1000];
  char ** donnee = malloc(sizeof(char*)* 5);
  for (int j = 0; j < 5; j++)
    {
      donnee[j] = malloc(100);
    }
  
  if(!strcmp(info, "prenom")){i=0;}
  else if(!strcmp(info, "nom")){i=1;}
  else if(!strcmp(info, "dateNaissance")){ i=2;}
  else if(!strcmp(info, "mail")){ i=3;}
  else if(!strcmp(info, "nombreAchat")){ i=4;}
  else
    {
      printf("ERROR CRITERE NON RECONNU.\n");
      for(int l = 0; l<5;l++)
	{
	  free(donnee[l]);
	}
      free(donnee);
      exit(-1);
    }

  FILE * f = fopen("baseClient.txt","r");
  if(f == NULL)
    {
      perror("ERROR OUVERTURE FICHIER.\n");
      exit(-1);
    }
  while(fgets(ligne,1000,f))
    {
      sscanf(ligne,"%s ;%s ;%s ;%s ;%s",donnee[0],donnee[1],donnee[2],donnee[3],donnee[4]);
      if(!strcmp(donnee[i],crit))
	{
	  printf("%s",ligne);
	}
    }

  for(int l = 0; l<5;l++)
    {
      free(donnee[l]);
    }
  free(donnee);
      
}
int main(int argc, char *argv[])
{
  if(argc < 3)
    {
      printf("ERROR PAS ASSEZ D'ARGUMENTS.\n");
      exit(-1);
    }
  selectClient(argv[1],argv[2]);
  return 0;
}
