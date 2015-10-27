#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_drot (const int N, double *X, const int incX, double *Y, const int incY,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            const double c, const double s)
=======
	    const double c, const double s)
>>>>>>> config
{
#define BASE double
#include "source_rot.h"
#undef BASE
}
