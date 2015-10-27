#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_saxpy (const int N, const float alpha, const float *X, const int incX,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             float *Y, const int incY)
=======
	     float *Y, const int incY)
>>>>>>> config
{
#define BASE float
#include "source_axpy_r.h"
#undef BASE
}
