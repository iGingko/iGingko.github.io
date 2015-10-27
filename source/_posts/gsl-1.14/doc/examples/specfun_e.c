#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_sf_bessel.h>

int
main (void)
{
  double x = 5.0;
  gsl_sf_result result;

  double expected = -0.17759677131433830434739701;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  int status = gsl_sf_bessel_J0_e (x, &result);

  printf ("status  = %s\n", gsl_strerror(status));
  printf ("J0(5.0) = %.18f\n"
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          "      +/- % .18f\n", 
          result.val, result.err);
=======
	  "      +/- % .18f\n",
	  result.val, result.err);
>>>>>>> config
  printf ("exact   = %.18f\n", expected);
  return status;
}
