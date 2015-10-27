#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_cdotc_sub (const int N, const void *X, const int incX, const void *Y,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int incY, void *result)
=======
	     const int incY, void *result)
>>>>>>> config
{
#define BASE float
#define CONJ_SIGN (-1.0)
#include "source_dot_c.h"
#undef CONJ_SIGN
#undef BASE
}
