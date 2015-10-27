#include <stdio.h>
#include <gsl/gsl_combination.h>

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
main (void) 
=======
int
main (void)
>>>>>>> config
{
  gsl_combination * c;
  size_t i;

  printf ("All subsets of {0,1,2,3} by size:\n") ;
  for (i = 0; i <= 4; i++)
    {
      c = gsl_combination_calloc (4, i);
      do
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          printf ("{");
          gsl_combination_fprintf (stdout, c, " %u");
          printf (" }\n");
        }
=======
	{
	  printf ("{");
	  gsl_combination_fprintf (stdout, c, " %u");
	  printf (" }\n");
	}
>>>>>>> config
      while (gsl_combination_next (c) == GSL_SUCCESS);
      gsl_combination_free (c);
    }

  return 0;
}
