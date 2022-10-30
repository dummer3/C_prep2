#include <stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
  char * fichier1 = argv[1];
  char * fichier2 = argv[2];
  char c;
  FILE * f1 = fopen(fichier1,"r");
  FILE * f2 = fopen(fichier2,"w+");

  while(!feof(f1))
    {
      c = fgetc(f1);
      if(c != EOF)
	{
	  fputc(c,f2);
	}
    }
  fclose(f1);
  fclose(f2);

  char shell[100];
  snprintf(shell,100,"diff %s %s",fichier1,fichier2);
  printf("Différence :");
  system(shell);
  printf("\n");

  return 0;

  // chown pour changer groupe et owner
  // chmod [o,u,a][+,-][r,w,x] (ou en binaire)
}
