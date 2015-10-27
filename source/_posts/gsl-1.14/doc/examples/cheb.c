#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_chebyshev.h>

double
f (double x, void *p)
{
  if (x < 0.5)
    return 0.25;
  else
    return 0.75;
}

int
main (void)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  int i, n = 10000; 
=======
  int i, n = 10000;
>>>>>>> config

  gsl_cheb_series *cs = gsl_cheb_alloc (40);

  gsl_function F;

  F.function = f;
  F.params = 0;

  gsl_cheb_init (cs, &F, 0.0, 1.0);

  for (i = 0; i < n; i++)
    {
      double x = i / (double)n;
      double r10 = gsl_cheb_eval_n (cs, 10, x);
      double r40 = gsl_cheb_eval (cs, x);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      printf ("%g %g %g %g\n", 
              x, GSL_FN_EVAL (&F, x), r10, r40);
=======
      printf ("%g %g %g %g\n",
	      x, GSL_FN_EVAL (&F, x), r10, r40);
>>>>>>> config
    }

  gsl_cheb_free (cs);

  return 0;
}
