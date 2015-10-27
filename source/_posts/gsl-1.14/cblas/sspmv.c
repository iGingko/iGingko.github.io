#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_sspmv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int N, const float alpha, const float *Ap, const float *X,
             const int incX, const float beta, float *Y, const int incY)
=======
	     const int N, const float alpha, const float *Ap, const float *X,
	     const int incX, const float beta, float *Y, const int incY)
>>>>>>> config
{
#define BASE float
#include "source_spmv.h"
#undef BASE
}
