#include <stdio.h>
#include <gsl/gsl_rng.h>

int
main (void)
{
  const gsl_rng_type * T;
  gsl_rng * r;

  int i, n = 10;

  gsl_rng_env_setup();

  T = gsl_rng_default;
  r = gsl_rng_alloc (T);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  for (i = 0; i < n; i++) 
=======
  for (i = 0; i < n; i++)
>>>>>>> config
    {
      double u = gsl_rng_uniform (r);
      printf ("%.5f\n", u);
    }

  gsl_rng_free (r);

  return 0;
}
