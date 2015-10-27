#include <math.h>

static double xhypot (const double x, const double y);

static double xhypot (const double x, const double y)
{
  double xabs = fabs(x) ;
  double yabs = fabs(y) ;
  double min, max;

  if (xabs < yabs) {
    min = xabs ;
    max = yabs ;
  } else {
    min = yabs ;
    max = xabs ;
  }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (min == 0) 
=======
  if (min == 0)
>>>>>>> config
    {
      return max ;
    }

  {
    double u = min / max ;
    return max * sqrt (1 + u * u) ;
  }
}
