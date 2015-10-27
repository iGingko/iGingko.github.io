gsl_multifit_function_fdf
make_fdf (int (* f) (const gsl_vector *, void *, gsl_vector *),
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          int (* df) (const gsl_vector *, void *, gsl_matrix *),
          int (* fdf) (const gsl_vector *, void *, gsl_vector *, gsl_matrix *),
          size_t n,
          size_t p,
          void * params);

gsl_multifit_function_fdf
make_fdf (int (* f) (const gsl_vector *, void *, gsl_vector *),
          int (* df) (const gsl_vector *, void *, gsl_matrix *),
          int (* fdf) (const gsl_vector *, void *, gsl_vector *, gsl_matrix *),
          size_t n,
          size_t p,
          void * params)
=======
	  int (* df) (const gsl_vector *, void *, gsl_matrix *),
	  int (* fdf) (const gsl_vector *, void *, gsl_vector *, gsl_matrix *),
	  size_t n,
	  size_t p,
	  void * params);

gsl_multifit_function_fdf
make_fdf (int (* f) (const gsl_vector *, void *, gsl_vector *),
	  int (* df) (const gsl_vector *, void *, gsl_matrix *),
	  int (* fdf) (const gsl_vector *, void *, gsl_vector *, gsl_matrix *),
	  size_t n,
	  size_t p,
	  void * params)
>>>>>>> config
{
  gsl_multifit_function_fdf F_new;
  F_new.f = f;
  F_new.df = df;
  F_new.fdf = fdf;
  F_new.n = n;
  F_new.p = p;
  F_new.params = params;
  return F_new;
}
