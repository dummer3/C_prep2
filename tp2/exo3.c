#include <stdio.h>

int testVoyelle(int c)
{
  char voyelle[7] = "aeuioy";
    for (int i = 0; i < 6; i++)
      {
       if(c == voyelle[i])
	 {
	  return 0;
	 }
      }
  return 1;
}

int main(int argc, char * argv[])
{
  FILE* f1 = fopen(argv[1],"r+");
  fpos_t pos;
  fpos_t posSansVoyelle;
  
  char c;
  
  fgetpos(f1,&pos);
  fgetpos(f1,&posSansVoyelle);
  
  int fin = 0;
  int actuelle = 0;
  
  while(!feof(f1))
    {
      c = fgetc(f1);
      fgetpos(f1,&pos);
      if(testVoyelle(c) && c != EOF)
	{
	  printf("%c",c);
	  
	  fsetpos(f1,&posSansVoyelle);
	  fputc(c,f1);
	  
	  fgetpos(f1,&posSansVoyelle);
	  fsetpos(f1,&pos);
	  actuelle++;
	}
      fin ++;
    }

  fsetpos(f1,&posSansVoyelle);

  for(int i = 0; i <  fin - actuelle ;i++ )
    {
     
      fputc(' ',f1);
    }
   
  fclose(f1);

  return 0;
}
