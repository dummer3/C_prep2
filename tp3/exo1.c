#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>


int main(int argc, char ** argv)
{
  srand(time(NULL));
  FILE * f = fopen(argv[1],"a");
  for (int i = 0; i<2000; i++)
    {
      
      for (int j = 2; j < argc;j++)
	{
	  //fputs(argv[2],f);
	  fwrite(argv[j],1,strlen(argv[j]),f);
      usleep(rand()%1000);
	}
    }
  fclose(f);
}

// Si on le lance 2 fois on va écrire en premier le second appel puis écrasé par la suite avec le premier appel (sauf si on append) (si on rajour un & après le second appel ce sera cette fois ci le premier appel en premier puis le second).
