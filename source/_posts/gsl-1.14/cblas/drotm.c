#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_drotm (const int N, double *X, const int incX, double *Y,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int incY, const double *P)
=======
	     const int incY, const double *P)
>>>>>>> config
{
#define BASE double
#include "source_rotm.h"
#undef BASE
}
