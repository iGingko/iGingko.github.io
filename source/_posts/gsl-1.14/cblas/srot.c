#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_srot (const int N, float *X, const int incX, float *Y, const int incY,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            const float c, const float s)
=======
	    const float c, const float s)
>>>>>>> config
{
#define BASE float
#include "source_rot.h"
#undef BASE
}
