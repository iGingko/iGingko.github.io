#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_zsymm (const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const enum CBLAS_UPLO Uplo, const int M, const int N,
             const void *alpha, const void *A, const int lda, const void *B,
             const int ldb, const void *beta, void *C, const int ldc)
=======
	     const enum CBLAS_UPLO Uplo, const int M, const int N,
	     const void *alpha, const void *A, const int lda, const void *B,
	     const int ldb, const void *beta, void *C, const int ldc)
>>>>>>> config
{
#define BASE double
#include "source_symm_c.h"
#undef BASE
}
