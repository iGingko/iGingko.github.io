#include <stdio.h>
#include <gsl/gsl_poly.h>

int
main (void)
{
  int i;
  /* coefficients of P(x) =  -1 + x^5  */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  double a[6] = { -1, 0, 0, 0, 0, 1 };  
  double z[10];

  gsl_poly_complex_workspace * w 
      = gsl_poly_complex_workspace_alloc (6);
  
=======
  double a[6] = { -1, 0, 0, 0, 0, 1 };
  double z[10];

  gsl_poly_complex_workspace * w
      = gsl_poly_complex_workspace_alloc (6);

>>>>>>> config
  gsl_poly_complex_solve (a, 6, w, z);

  gsl_poly_complex_workspace_free (w);

  for (i = 0; i < 5; i++)
    {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      printf ("z%d = %+.18f %+.18f\n", 
              i, z[2*i], z[2*i+1]);
=======
      printf ("z%d = %+.18f %+.18f\n",
	      i, z[2*i], z[2*i+1]);
>>>>>>> config
    }

  return 0;
}
