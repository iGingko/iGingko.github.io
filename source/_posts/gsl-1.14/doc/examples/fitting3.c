#include <stdio.h>
#include <math.h>
#include <gsl/gsl_randist.h>

int
main (void)
{
  double x;
  const gsl_rng_type * T;
  gsl_rng * r;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  gsl_rng_env_setup ();
  
=======

  gsl_rng_env_setup ();

>>>>>>> config
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);

  for (x = 0.1; x < 2; x+= 0.1)
    {
      double y0 = exp (x);
      double sigma = 0.1 * y0;
      double dy = gsl_ran_gaussian (r, sigma);

      printf ("%g %g %g\n", x, y0 + dy, sigma);
    }

  gsl_rng_free(r);

  return 0;
}
