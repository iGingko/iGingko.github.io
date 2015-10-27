#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

double
cblas_dsdot (const int N, const float *X, const int incX, const float *Y,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int incY)
=======
	     const int incY)
>>>>>>> config
{
#define INIT_VAL  0.0
#define ACC_TYPE  double
#define BASE float
#include "source_dot_r.h"
#undef ACC_TYPE
#undef BASE
#undef INIT_VAL
}
