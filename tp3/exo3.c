#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv)
{
  int nbrChar=0;
  int nbrMots=1;
  int nbrLigne=1;
  FILE * f = fopen(argv[1],"r");
  char c;
  while(!feof(f))
    {
      c = fgetc(f);
      if(c != EOF)
	{
	  nbrChar++;
	  if(iscntrl(c) || isblank(c))
	    {
	      nbrChar--;
	      nbrMots++;
	      if(!isblank(c))
		{
		  nbrLigne++;
		}
	    }
	}
    }
  printf("%d %d %d\n",nbrChar,nbrMots,nbrLigne);
  return 0;
}
