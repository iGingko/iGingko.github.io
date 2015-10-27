#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_caxpy (const int N, const void *alpha, const void *X, const int incX,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             void *Y, const int incY)
=======
	     void *Y, const int incY)
>>>>>>> config
{
#define BASE float
#include "source_axpy_c.h"
#undef BASE
}
