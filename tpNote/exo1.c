#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


double MaxVal(int n , ...)
{
  int i;
  double max = 0;
  double f = 0;
  va_list l;
  va_start(l,n);
  for(i = 0; i<n;i++)
    {
      f = va_arg(l,double);
      if (f > max)
	{
	  max = f;
	}
    }

  va_end(l);
  return max;
}


int main()
{
  // Obliger de caster sinon saute le paramètre si il est écrit sous forme entière. 
  printf("%.3f\n",MaxVal((double)5,(double)20,(double)25,(double)30,(double)5.4,(double)15.7));
  return 0;
}
