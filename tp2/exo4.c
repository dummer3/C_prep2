#include<stdio.h>

int main(int argc, char * argv[])
{

  int T[512];
  for(int i = 0; i<512;i++)
    {
      T[i] = i;
    }

  FILE* f = fopen(argv[1],"w+");
  fwrite(T,sizeof(int),512,f);

  fclose(f);


  return 0;
}
