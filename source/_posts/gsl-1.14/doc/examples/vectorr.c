#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  int i; 
  gsl_vector * v = gsl_vector_alloc (10);

  {  
=======
  int i;
  gsl_vector * v = gsl_vector_alloc (10);

  {
>>>>>>> config
     FILE * f = fopen ("test.dat", "r");
     gsl_vector_fscanf (f, v);
     fclose (f);
  }

  for (i = 0; i < 10; i++)
    {
      printf ("%g\n", gsl_vector_get(v, i));
    }

  gsl_vector_free (v);
  return 0;
}
