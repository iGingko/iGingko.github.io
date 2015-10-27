struct quadratic_params
  {
    double a, b, c;
  };

double quadratic (double x, void *params);
double quadratic_deriv (double x, void *params);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void quadratic_fdf (double x, void *params, 
                    double *y, double *dy);
=======
void quadratic_fdf (double x, void *params,
		    double *y, double *dy);
>>>>>>> config
