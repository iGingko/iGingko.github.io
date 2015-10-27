#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_dgbmv (const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int M, const int N, const int KL, const int KU,
             const double alpha, const double *A, const int lda,
             const double *X, const int incX, const double beta, double *Y,
             const int incY)
=======
	     const int M, const int N, const int KL, const int KU,
	     const double alpha, const double *A, const int lda,
	     const double *X, const int incX, const double beta, double *Y,
	     const int incY)
>>>>>>> config
{
#define BASE double
#include "source_gbmv_r.h"
#undef BASE
}
