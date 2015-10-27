/* expfit.c -- model functions for exponential + background */

struct data {
  size_t n;
  double * y;
  double * sigma;
};

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
expb_f (const gsl_vector * x, void *data, 
        gsl_vector * f)
=======
expb_f (const gsl_vector * x, void *data,
	gsl_vector * f)
>>>>>>> config
{
  size_t n = ((struct data *)data)->n;
  double *y = ((struct data *)data)->y;
  double *sigma = ((struct data *) data)->sigma;

  double A = gsl_vector_get (x, 0);
  double lambda = gsl_vector_get (x, 1);
  double b = gsl_vector_get (x, 2);

  size_t i;

  for (i = 0; i < n; i++)
    {
      /* Model Yi = A * exp(-lambda * i) + b */
      double t = i;
      double Yi = A * exp (-lambda * t) + b;
      gsl_vector_set (f, i, (Yi - y[i])/sigma[i]);
    }

  return GSL_SUCCESS;
}

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
expb_df (const gsl_vector * x, void *data, 
         gsl_matrix * J)
=======
expb_df (const gsl_vector * x, void *data,
	 gsl_matrix * J)
>>>>>>> config
{
  size_t n = ((struct data *)data)->n;
  double *sigma = ((struct data *) data)->sigma;

  double A = gsl_vector_get (x, 0);
  double lambda = gsl_vector_get (x, 1);

  size_t i;

  for (i = 0; i < n; i++)
    {
      /* Jacobian matrix J(i,j) = dfi / dxj, */
      /* where fi = (Yi - yi)/sigma[i],      */
      /*       Yi = A * exp(-lambda * i) + b  */
      /* and the xj are the parameters (A,lambda,b) */
      double t = i;
      double s = sigma[i];
      double e = exp(-lambda * t);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      gsl_matrix_set (J, i, 0, e/s); 
=======
      gsl_matrix_set (J, i, 0, e/s);
>>>>>>> config
      gsl_matrix_set (J, i, 1, -t * A * e/s);
      gsl_matrix_set (J, i, 2, 1/s);
    }
  return GSL_SUCCESS;
}

int
expb_fdf (const gsl_vector * x, void *data,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          gsl_vector * f, gsl_matrix * J)
=======
	  gsl_vector * f, gsl_matrix * J)
>>>>>>> config
{
  expb_f (x, data, f);
  expb_df (x, data, J);

  return GSL_SUCCESS;
}
