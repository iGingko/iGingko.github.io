#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_strmm (const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
             const enum CBLAS_DIAG Diag, const int M, const int N,
             const float alpha, const float *A, const int lda, float *B,
             const int ldb)
=======
	     const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
	     const enum CBLAS_DIAG Diag, const int M, const int N,
	     const float alpha, const float *A, const int lda, float *B,
	     const int ldb)
>>>>>>> config
{
#define BASE float
#include "source_trmm_r.h"
#undef BASE
}
