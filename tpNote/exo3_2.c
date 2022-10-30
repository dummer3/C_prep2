#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incAchat(char * s)
{
  char ligne[1000];
  
  FILE * f = fopen("baseClient.txt","r+");
  if(f == NULL)
    {
      perror("ERROR OUVERTURE DU FICHIER");
      exit(-1);
    }
  while (fgets(ligne,1000,f))
    {
      if(!strcmp(ligne,s))
	{
	  fseek(f,-2,SEEK_CUR);
	  int i;
	  fscanf(f,"%d",&i);
	  char * nbr;
	  sprintf(nbr,"%d",i+1);
	  
	  fseek(f,-1,SEEK_CUR);
	  fputs(nbr,f);
	  fputc('\n',f);
	  
	}
    }
  
}

void verificationDate(char * dt)
{
  int a,b,c;

  sscanf(dt,"%d / %d / %d",&a,&b,&c);
  
  if (a <= 31 && b <= 12 && a> 0 && b > 0 && c >= 0)
    {
      printf("Date valide\n");
    }
  else
    {
      printf("ERROR DATE NON VALIDE\n");
      exit(-1);
    }
}

char * cherche(char * prenom, char * nom, char * dateDeNaissance)
{
  verificationDate(dateDeNaissance);
  FILE * f = fopen("baseClient.txt","r");
  if(f == NULL)
    {
      perror("ERROR OUVERTURE FICHIER\n");
      exit(-1);
    }

  char * ligne;
  char prenomActu[100];
  char nomActu[100];
  char dateDeNaissanceActu[11];
      
  while(fgets(ligne,1000,f))
    {    
      sscanf(ligne,"%s ;%s ;%s ;",prenomActu,nomActu,dateDeNaissanceActu);
      if(!strcmp(prenomActu,prenom) && !strcmp(nom,nomActu) && !strcmp(dateDeNaissance,dateDeNaissanceActu))
	{
	  fclose(f);
	  return ligne;
	}
    }
  fclose(f);
  printf("ERROR AUCUNE DATE DE NAISSANCE NE CORRESPOND PAS");
  return NULL;
}

char * existe(char* prenom, char* nom)
{
  char * ligne;
  char ligneActu[1000];
  int occurence = 0;
  char prenomActu[100];
  char nomActu[100];
  
  FILE * f = fopen("baseClient.txt","r");
  if(f == NULL)
    {
      perror("ERROR OUVERTURE FICHIER\n");
      exit(-1);
    }
  
  while(fgets(ligneActu,1000,f))
    {
      sscanf(ligneActu,"%s ;%s ;",prenomActu,nomActu);
      if(!strcmp(prenomActu,prenom) && !strcmp(nom,nomActu))
	{
	  ligne = ligneActu;
	  occurence ++;
	}
    }
  fclose(f);
  if (occurence > 1 )
    {
      char dateDeNaissance[11];
      printf("%d clients ont le même nom. préciser la date de naissance :\n",occurence);
      scanf("%s",dateDeNaissance);
      return cherche(prenom,nom,dateDeNaissance);
      
    }
  else if(occurence == 1)
    {
      printf("1 client trouvé\n");
      return ligne;
    }
  else
    {
      printf("Aucun Client trouvé\n");
      return NULL;
    }
}

int main(int argc, char * argv[])
{
  if (argc < 3)
    {
      printf("ERROR PAS ASSEZ D'ARGUMENTS");
      exit(-1);
    }
  char * c = existe(argv[1],argv[2]);
  incAchat(c);
    return 0;
}
