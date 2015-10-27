#include <stdio.h>
#include <gsl/gsl_permutation.h>

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
main (void) 
=======
main (void)
>>>>>>> config
{
  gsl_permutation * p = gsl_permutation_alloc (3);

  gsl_permutation_init (p);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  do 
=======
  do
>>>>>>> config
   {
      gsl_permutation_fprintf (stdout, p, " %u");
      printf ("\n");
   }
  while (gsl_permutation_next(p) == GSL_SUCCESS);

  gsl_permutation_free (p);

  return 0;
}
