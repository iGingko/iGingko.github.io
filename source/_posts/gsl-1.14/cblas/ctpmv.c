#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_ctpmv (const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
             const int N, const void *Ap, void *X, const int incX)
=======
	     const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
	     const int N, const void *Ap, void *X, const int incX)
>>>>>>> config
{
#define BASE float
#include "source_tpmv_c.h"
#undef BASE
}
