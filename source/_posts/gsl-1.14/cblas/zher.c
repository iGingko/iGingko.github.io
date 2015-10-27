#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_zher (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            const int N, const double alpha, const void *X, const int incX,
            void *A, const int lda)
=======
	    const int N, const double alpha, const void *X, const int incX,
	    void *A, const int lda)
>>>>>>> config
{
#define BASE double
#include "source_her.h"
#undef BASE
}
