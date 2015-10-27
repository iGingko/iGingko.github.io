double
quadratic (double x, void *params)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  struct quadratic_params *p 
=======
  struct quadratic_params *p
>>>>>>> config
    = (struct quadratic_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;

  return (a * x + b) * x + c;
}

double
quadratic_deriv (double x, void *params)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  struct quadratic_params *p 
=======
  struct quadratic_params *p
>>>>>>> config
    = (struct quadratic_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;

  return 2.0 * a * x + b;
}

void
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
quadratic_fdf (double x, void *params, 
               double *y, double *dy)
{
  struct quadratic_params *p 
=======
quadratic_fdf (double x, void *params,
	       double *y, double *dy)
{
  struct quadratic_params *p
>>>>>>> config
    = (struct quadratic_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;

  *y = (a * x + b) * x + c;
  *dy = 2.0 * a * x + b;
}
