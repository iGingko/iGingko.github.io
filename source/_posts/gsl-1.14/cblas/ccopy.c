#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>
#include "cblas.h"

void
cblas_ccopy (const int N, const void *X, const int incX, void *Y,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const int incY)
=======
	     const int incY)
>>>>>>> config
{
#define BASE float
#include "source_copy_c.h"
#undef BASE
}
