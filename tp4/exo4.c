#include <stdlib.h>
#include <stdio.h>

int comp1(int a, int b)
{
  if(a==b) {return 0;}
  return (a<b)?1:-1;
}
int comp2(int a, int b)
{
  if(a==b) {return 0;}
  return (a>b)?1:-1;
}
int comp3(int a, int b)
{
  if(a%2==b%2) {return 0;}
  return (!(a%2))?1:-1;
}



int comp(int a,int b, int (* comp)(int,int))
{
  return comp(a,b);
}


int main()
{
  int a,b;
  printf("Que vaut a et b ?\n");
  scanf("%d%d",&a,&b);
  printf("%d,%d,%d avec a = %d et b = %d\n",comp(a,b,&comp1),comp(a,b,&comp2),comp(a,b,comp3),a,b);

  
  return 0;
}
