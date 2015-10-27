#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int
main (void)
{
  int i;
  double x = 0, y = 0, dx, dy;

  const gsl_rng_type * T;
  gsl_rng * r;

  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);

  printf ("%g %g\n", x, y);

  for (i = 0; i < 10; i++)
    {
      gsl_ran_dir_2d (r, &dx, &dy);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      x += dx; y += dy; 
=======
      x += dx; y += dy;
>>>>>>> config
      printf ("%g %g\n", x, y);
    }

  gsl_rng_free (r);
  return 0;
}
