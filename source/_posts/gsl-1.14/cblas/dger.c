#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_dger (const enum CBLAS_ORDER order, const int M, const int N,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            const double alpha, const double *X, const int incX,
            const double *Y, const int incY, double *A, const int lda)
=======
	    const double alpha, const double *X, const int incX,
	    const double *Y, const int incY, double *A, const int lda)
>>>>>>> config
{
#define BASE double
#include "source_ger.h"
#undef BASE
}
