/* radicand function */
#include "QE.h"
#include<math.h>
int radicand(int x, int y, int z)
{
   int value;
   
   value = y*y - 4.0*x*z;
   if (value < 0)
      return -1;
   if (value == 0)
      return 0;
   return value;
}

