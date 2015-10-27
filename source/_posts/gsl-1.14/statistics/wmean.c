#include <config.h>
#include <gsl/gsl_statistics.h>

#define BASE_LONG_DOUBLE
#include "templates_on.h"
#include "wmean_source.c"
#include "templates_off.h"
#undef  BASE_LONG_DOUBLE

#define BASE_DOUBLE
#include "templates_on.h"
#include "wmean_source.c"
#include "templates_off.h"
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include "templates_on.h"
#include "wmean_source.c"
#include "templates_off.h"
#undef  BASE_FLOAT
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
