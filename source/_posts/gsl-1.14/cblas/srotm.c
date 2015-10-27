#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_srotm (const int N, float *X, const int incX, float *Y, const int incY,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const float *P)
=======
	     const float *P)
>>>>>>> config
{
#define BASE float
#include "source_rotm.h"
#undef BASE
}
