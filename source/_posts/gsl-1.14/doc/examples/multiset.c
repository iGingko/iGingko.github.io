#include <stdio.h>
#include <gsl/gsl_multiset.h>

int
main (void)
{
  gsl_multiset * c;
  size_t i;

  printf ("All multisets of {0,1,2,3} by size:\n") ;
  for (i = 0; i <= 4; i++)
    {
      c = gsl_multiset_calloc (4, i);
      do
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          printf ("{");
          gsl_multiset_fprintf (stdout, c, " %u");
          printf (" }\n");
        }
=======
	{
	  printf ("{");
	  gsl_multiset_fprintf (stdout, c, " %u");
	  printf (" }\n");
	}
>>>>>>> config
      while (gsl_multiset_next (c) == GSL_SUCCESS);
      gsl_multiset_free (c);
    }

  return 0;
}
