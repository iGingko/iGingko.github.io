#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_sspr (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            const int N, const float alpha, const float *X, const int incX,
            float *Ap)
=======
	    const int N, const float alpha, const float *X, const int incX,
	    float *Ap)
>>>>>>> config
{
#define BASE float
#include "source_spr.h"
#undef BASE
}
