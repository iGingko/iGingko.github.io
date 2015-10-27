#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_daxpy (const int N, const double alpha, const double *X, const int incX,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             double *Y, const int incY)
=======
	     double *Y, const int incY)
>>>>>>> config
{
#define BASE double
#include "source_axpy_r.h"
#undef BASE
}
