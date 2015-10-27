#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_scopy (const int N, const float *X, const int incX, float *Y,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int incY)
=======
	     const int incY)
>>>>>>> config
{
#define BASE float
#include "source_copy_r.h"
#undef BASE
}
