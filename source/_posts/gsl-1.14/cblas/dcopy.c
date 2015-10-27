#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_dcopy (const int N, const double *X, const int incX, double *Y,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int incY)
=======
	     const int incY)
>>>>>>> config
{
#define BASE double
#include "source_copy_r.h"
#undef BASE
}
