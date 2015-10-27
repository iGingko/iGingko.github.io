#include <stdio.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  int i, j, k = 0; 
  gsl_matrix * m = gsl_matrix_alloc (100, 100);
  gsl_matrix * a = gsl_matrix_alloc (100, 100);
  
=======
  int i, j, k = 0;
  gsl_matrix * m = gsl_matrix_alloc (100, 100);
  gsl_matrix * a = gsl_matrix_alloc (100, 100);

>>>>>>> config
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      gsl_matrix_set (m, i, j, 0.23 + i + j);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  {  
=======
  {
>>>>>>> config
     FILE * f = fopen ("test.dat", "wb");
     gsl_matrix_fwrite (f, m);
     fclose (f);
  }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  {  
=======
  {
>>>>>>> config
     FILE * f = fopen ("test.dat", "rb");
     gsl_matrix_fread (f, a);
     fclose (f);
  }

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        double mij = gsl_matrix_get (m, i, j);
        double aij = gsl_matrix_get (a, i, j);
        if (mij != aij) k++;
=======
	double mij = gsl_matrix_get (m, i, j);
	double aij = gsl_matrix_get (a, i, j);
	if (mij != aij) k++;
>>>>>>> config
      }

  gsl_matrix_free (m);
  gsl_matrix_free (a);

  printf ("differences = %d (should be zero)\n", k);
  return (k > 0);
}
