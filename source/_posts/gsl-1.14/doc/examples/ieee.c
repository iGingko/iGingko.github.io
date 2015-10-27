#include <stdio.h>
#include <gsl/gsl_ieee_utils.h>

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
main (void) 
=======
main (void)
>>>>>>> config
{
  float f = 1.0/3.0;
  double d = 1.0/3.0;

  double fd = f; /* promote from float to double */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  printf (" f="); gsl_ieee_printf_float(&f); 
  printf ("\n");

  printf ("fd="); gsl_ieee_printf_double(&fd); 
  printf ("\n");

  printf (" d="); gsl_ieee_printf_double(&d); 
=======

  printf (" f="); gsl_ieee_printf_float(&f);
  printf ("\n");

  printf ("fd="); gsl_ieee_printf_double(&fd);
  printf ("\n");

  printf (" d="); gsl_ieee_printf_double(&d);
>>>>>>> config
  printf ("\n");

  return 0;
}
