
static inline int
cheb_eval_e(const cheb_series * cs,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            const double x,
            gsl_sf_result * result)
=======
	    const double x,
	    gsl_sf_result * result)
>>>>>>> config
{
  int j;
  double d  = 0.0;
  double dd = 0.0;

  double y  = (2.0*x - cs->a - cs->b) / (cs->b - cs->a);
  double y2 = 2.0 * y;

  double e = 0.0;

  for(j = cs->order; j>=1; j--) {
    double temp = d;
    d = y2*d - dd + cs->c[j];
    e += fabs(y2*temp) + fabs(dd) + fabs(cs->c[j]);
    dd = temp;
  }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  { 
=======
  {
>>>>>>> config
    double temp = d;
    d = y*d - dd + 0.5 * cs->c[0];
    e += fabs(y*temp) + fabs(dd) + 0.5 * fabs(cs->c[0]);
  }

  result->val = d;
  result->err = GSL_DBL_EPSILON * e + fabs(cs->c[cs->order]);

  return GSL_SUCCESS;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
