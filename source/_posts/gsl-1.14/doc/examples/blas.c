#include <stdio.h>
#include <gsl/gsl_blas.h>

int
main (void)
{
  double a[] = { 0.11, 0.12, 0.13,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 0.21, 0.22, 0.23 };

  double b[] = { 1011, 1012,
                 1021, 1022,
                 1031, 1032 };

  double c[] = { 0.00, 0.00,
                 0.00, 0.00 };
=======
		 0.21, 0.22, 0.23 };

  double b[] = { 1011, 1012,
		 1021, 1022,
		 1031, 1032 };

  double c[] = { 0.00, 0.00,
		 0.00, 0.00 };
>>>>>>> config

  gsl_matrix_view A = gsl_matrix_view_array(a, 2, 3);
  gsl_matrix_view B = gsl_matrix_view_array(b, 3, 2);
  gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);

  /* Compute C = A B */

  gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                  1.0, &A.matrix, &B.matrix,
                  0.0, &C.matrix);
=======
		  1.0, &A.matrix, &B.matrix,
		  0.0, &C.matrix);
>>>>>>> config

  printf ("[ %g, %g\n", c[0], c[1]);
  printf ("  %g, %g ]\n", c[2], c[3]);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  return 0;  
=======
  return 0;
>>>>>>> config
}
