#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_zhbmv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int N, const int K, const void *alpha, const void *A,
             const int lda, const void *X, const int incX, const void *beta,
             void *Y, const int incY)
=======
	     const int N, const int K, const void *alpha, const void *A,
	     const int lda, const void *X, const int incX, const void *beta,
	     void *Y, const int incY)
>>>>>>> config
{
#define BASE double
#include "source_hbmv.h"
#undef BASE
}
