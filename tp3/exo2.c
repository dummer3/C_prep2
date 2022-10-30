#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"string.h"


int verifDigit(char * c)
{
  for (int i = 0; i < strlen(c); i++)
	{
	  if (!isdigit(c[i]) && c[i] != '-')
	    {
	      return 0;
	    }
	}
    return 1;
}

int * comptageDigit(FILE * f, int size)
{

  int * tab = malloc(sizeof(int) * size);
  char * c = malloc(sizeof(char) * 10);
  int i = 0;
  while(i < size)
    {
      fscanf(f,"%s",c);
    
      if (verifDigit(c))
	{
	  tab[i] = atoi(c);
	}
      else
	{
	  return NULL;
	}
      i++;
    }

  return tab;
}


int main(int argc, char** argv)
{
  FILE * f = fopen(argv[1],"r");
  

  fpos_t posInitiale;
  fgetpos(f,&posInitiale);
  char c = getc(f);
  int size = 1;
  
  while (!feof(f))
    {
      c = getc(f);
      if(c != EOF)
	{
      printf("%c",c);
	}
      if(c == ' ')
	{
	  size++;
	}
    }
  
  fsetpos(f,&posInitiale);

  int * tab = comptageDigit(f,size);
  if(tab != NULL)
    {
      for (int i = 0; i < size; i++)
	{
	  printf("|%d|",tab[i]);
	}
      printf("\n");
    }
  else
    {
      printf("Le string n'est pas composé que de digit\n");
    }

  return 0;
}
