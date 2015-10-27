#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_sgbmv (const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int M, const int N, const int KL, const int KU,
             const float alpha, const float *A, const int lda, const float *X,
             const int incX, const float beta, float *Y, const int incY)
=======
	     const int M, const int N, const int KL, const int KU,
	     const float alpha, const float *A, const int lda, const float *X,
	     const int incX, const float beta, float *Y, const int incY)
>>>>>>> config
{
#define BASE float
#include "source_gbmv_r.h"
#undef BASE
}
