#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  int i; 
  gsl_vector * v = gsl_vector_alloc (100);
  
=======
  int i;
  gsl_vector * v = gsl_vector_alloc (100);

>>>>>>> config
  for (i = 0; i < 100; i++)
    {
      gsl_vector_set (v, i, 1.23 + i);
    }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  {  
=======
  {
>>>>>>> config
     FILE * f = fopen ("test.dat", "w");
     gsl_vector_fprintf (f, v, "%.5g");
     fclose (f);
  }

  gsl_vector_free (v);
  return 0;
}
