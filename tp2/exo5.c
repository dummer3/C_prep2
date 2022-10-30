#include<stdio.h>
#include<stdlib.h>

void permutation(char * T, int * tab, unsigned int taille)
{
  int * tempo = malloc(sizeof(int)*taille);
  for(int i = 0; i < taille; i++)
    {
      tempo[i] = tab[i];
    }
  for (int i = 0; i < taille; i++)
    {
      char s = T[i];
      T[i] = T[tempo[i]];
      T[tempo[i]] = s;

      for( int j = 0; j <taille;j++)
	{
	  if(tempo[j] == i)
	    {
	      tempo[j] = tempo[i];
	    }
	}
    }
  free(tempo);
}

int main(int argc, char * argv[])
{

  FILE * f2 = fopen(argv[2],"r");
  fseek(f2,0,SEEK_END);
  int size = (ftell(f2))/2;
  int * permut = malloc(sizeof(int) * size);
  int a;
  
  fseek(f2,0,SEEK_SET);
  
   for(int i = 0; i < size; i++)
    {
    
      fscanf(f2,"%d",&a);
      permut[i] = a;
      }
  
  fclose(f2);
  
   FILE * f1 = fopen(argv[1],"r+");
   fseek(f1,0,SEEK_END);
  
  int tailleDeF1 = ftell(f1) -1 ;

  fseek(f1,0,SEEK_SET);

  fpos_t pos;
  char * code = malloc(sizeof(char)*(size+1));
  for(int i = 0; i < tailleDeF1 - tailleDeF1%(size); i += size)
    {
      fgetpos(f1, &pos);
      fgets(code,size+1,f1);
      permutation(code,permut,size);
      fsetpos(f1,&pos);
      fputs(code,f1);
    }
  
  fclose(f1);
  
}
