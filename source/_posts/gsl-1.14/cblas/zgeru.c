#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_zgeru (const enum CBLAS_ORDER order, const int M, const int N,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const void *alpha, const void *X, const int incX, const void *Y,
             const int incY, void *A, const int lda)
=======
	     const void *alpha, const void *X, const int incX, const void *Y,
	     const int incY, void *A, const int lda)
>>>>>>> config
{
#define BASE double
#include "source_geru.h"
#undef BASE
}
