#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f (double x, void * params) {
  double alpha = *(double *) params;
  double f = log(alpha*x) / sqrt(x);
  return f;
}

int
main (void)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  gsl_integration_workspace * w 
    = gsl_integration_workspace_alloc (1000);
  
=======
  gsl_integration_workspace * w
    = gsl_integration_workspace_alloc (1000);

>>>>>>> config
  double result, error;
  double expected = -4.0;
  double alpha = 1.0;

  gsl_function F;
  F.function = &f;
  F.params = &alpha;

  gsl_integration_qags (&F, 0, 1, 0, 1e-7, 1000,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        w, &result, &error); 
=======
			w, &result, &error);
>>>>>>> config

  printf ("result          = % .18f\n", result);
  printf ("exact result    = % .18f\n", expected);
  printf ("estimated error = % .18f\n", error);
  printf ("actual error    = % .18f\n", result - expected);
  printf ("intervals =  %d\n", w->size);

  gsl_integration_workspace_free (w);

  return 0;
}
