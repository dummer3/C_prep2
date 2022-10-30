#include <stdio.h>
#include <stdlib.h>

union u
{
  int a;
  char  c[8];
  
};


int main()
{
  union u monUnion;
  monUnion.a = 42;
  char tempo = monUnion.c[0];
  char tempo2 = monUnion.c[7];
  monUnion.a--;
  if(tempo != monUnion.c[0])
    {
      printf("Bits de poids faible en premier\n");
    }
  if(tempo2 != monUnion.c[7])
    {
      printf("Bits de poids fort en premier\n");
    }
  return 0; 
}
