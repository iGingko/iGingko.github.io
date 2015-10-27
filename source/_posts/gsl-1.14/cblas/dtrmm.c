#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_dtrmm (const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
             const enum CBLAS_DIAG Diag, const int M, const int N,
             const double alpha, const double *A, const int lda, double *B,
             const int ldb)
=======
	     const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
	     const enum CBLAS_DIAG Diag, const int M, const int N,
	     const double alpha, const double *A, const int lda, double *B,
	     const int ldb)
>>>>>>> config
{
#define BASE double
#include "source_trmm_r.h"
#undef BASE
}
