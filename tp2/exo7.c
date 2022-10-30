#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
  int k;
  sscanf(argv[2],"%d",&k);
  
  FILE * f = fopen(argv[1], "r+");
  char c;
  char c2;
  fpos_t pos;
  do
    {
      fgetpos(f,&pos);
      c = fgetc(f);
      if(c != EOF)
	{
	  c2 = (c+k)%255;
	  fsetpos(f,&pos);
	  fputc(c2,f);
	}
    } while(c != EOF);

  


  fclose(f);

  return 0;
}
