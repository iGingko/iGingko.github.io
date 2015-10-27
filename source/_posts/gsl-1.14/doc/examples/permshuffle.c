#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_permutation.h>

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
main (void) 
=======
main (void)
>>>>>>> config
{
  const size_t N = 10;
  const gsl_rng_type * T;
  gsl_rng * r;

  gsl_permutation * p = gsl_permutation_alloc (N);
  gsl_permutation * q = gsl_permutation_alloc (N);

  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  printf ("initial permutation:");  
=======
  printf ("initial permutation:");
>>>>>>> config
  gsl_permutation_init (p);
  gsl_permutation_fprintf (stdout, p, " %u");
  printf ("\n");

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  printf (" random permutation:");  
=======
  printf (" random permutation:");
>>>>>>> config
  gsl_ran_shuffle (r, p->data, N, sizeof(size_t));
  gsl_permutation_fprintf (stdout, p, " %u");
  printf ("\n");

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  printf ("inverse permutation:");  
=======
  printf ("inverse permutation:");
>>>>>>> config
  gsl_permutation_inverse (q, p);
  gsl_permutation_fprintf (stdout, q, " %u");
  printf ("\n");

  gsl_permutation_free (p);
  gsl_permutation_free (q);
  gsl_rng_free (r);

  return 0;
}
