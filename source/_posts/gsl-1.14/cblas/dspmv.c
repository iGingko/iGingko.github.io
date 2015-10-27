#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_dspmv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int N, const double alpha, const double *Ap,
             const double *X, const int incX, const double beta, double *Y,
             const int incY)
=======
	     const int N, const double alpha, const double *Ap,
	     const double *X, const int incX, const double beta, double *Y,
	     const int incY)
>>>>>>> config
{
#define BASE double
#include "source_spmv.h"
#undef BASE
}
