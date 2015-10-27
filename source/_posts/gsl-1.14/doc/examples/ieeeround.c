#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_ieee_utils.h>

int
main (void)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  double x = 1, oldsum = 0, sum = 0; 
=======
  double x = 1, oldsum = 0, sum = 0;
>>>>>>> config
  int i = 0;

  gsl_ieee_env_setup (); /* read GSL_IEEE_MODE */

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  do 
    {
      i++;
      
      oldsum = sum;
      sum += x;
      x = x / i;
      
      printf ("i=%2d sum=%.18f error=%g\n",
              i, sum, sum - M_E);

      if (i > 30)
         break;
    }  
=======
  do
    {
      i++;

      oldsum = sum;
      sum += x;
      x = x / i;

      printf ("i=%2d sum=%.18f error=%g\n",
	      i, sum, sum - M_E);

      if (i > 30)
	 break;
    }
>>>>>>> config
  while (sum != oldsum);

  return 0;
}
