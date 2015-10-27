#include <stdio.h>
#include <gsl/gsl_cblas.h>

int
main (void)
{
  int lda = 3;

  float A[] = { 0.11, 0.12, 0.13,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                0.21, 0.22, 0.23 };

  int ldb = 2;
  
  float B[] = { 1011, 1012,
                1021, 1022,
                1031, 1032 };
=======
		0.21, 0.22, 0.23 };

  int ldb = 2;

  float B[] = { 1011, 1012,
		1021, 1022,
		1031, 1032 };
>>>>>>> config

  int ldc = 2;

  float C[] = { 0.00, 0.00,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                0.00, 0.00 };

  /* Compute C = A B */

  cblas_sgemm (CblasRowMajor, 
               CblasNoTrans, CblasNoTrans, 2, 2, 3,
               1.0, A, lda, B, ldb, 0.0, C, ldc);
=======
		0.00, 0.00 };

  /* Compute C = A B */

  cblas_sgemm (CblasRowMajor,
	       CblasNoTrans, CblasNoTrans, 2, 2, 3,
	       1.0, A, lda, B, ldb, 0.0, C, ldc);
>>>>>>> config

  printf ("[ %g, %g\n", C[0], C[1]);
  printf ("  %g, %g ]\n", C[2], C[3]);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  return 0;  
=======
  return 0;
>>>>>>> config
}
