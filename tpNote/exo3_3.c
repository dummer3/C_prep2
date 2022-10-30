#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void suppClient(char * s)
{
  FILE * tempo = tmpfile() ;
  FILE * f = fopen("baseClient.txt","r");
  if(f == NULL || tempo == NULL)
    {
      perror("ERROR OUVERTURE FICHIER\n");
      exit(-1);
    }
 
  char ligne[1000];
  
  while(fgets(ligne,1000,f))
    {
      if(strcmp(ligne,s))
	{
	  fputs(ligne,tempo);
	  printf("%s",ligne);
	}
    }
  fclose(f);

  int size;
  FILE * f1 = fopen("baseClient.txt","w+");
  fseek(tempo,0,SEEK_SET);
  while(size = fread(ligne,1,1000,tempo)){
    fwrite(ligne,1,size,f1) ;
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
  printf("ERROR AUCUNE DATE DE NAISSANCE NE CORRESPOND");
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


int main(int argc, char *argv[])
{
  if (argc < 3)
    {
      printf("ERROR PAS ASSEZ D ARGUMENT");
      exit(-1);
    }
  char * prenom = argv[1];
  char * nom = argv[2];
  
  char * s = existe(prenom,nom);
  suppClient(s);
  return 0;
}
